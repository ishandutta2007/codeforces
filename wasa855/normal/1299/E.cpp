#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(15381);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 805
int sre[N],cnt=0;
int n,ans[N],rev[N];
int query(vector<int> v)
{
	cnt++;
	if(cnt>n*18) exit(0);
	printf("? %d ",(int)v.size()),print(v),fflush(stdout);
#ifdef wasa855
	int ans=0; for(int i:v) ans+=sre[i];
	return ans%(int)v.size()==0;
#endif
	return read();
}
void final_fix()
{
	if(ans[1]>n/2) for(int i=1;i<=n;i++) ans[i]=n-ans[i]+1;
}
void small()
{
	{
		vector<int> pos;
		for(int i=1;i<=n;i++)
		{
			vector<int> tmp;
			for(int j=1;j<=n;j++) if(i!=j) tmp.pb(j);
			if(query(tmp)) pos.pb(i);
		}
		ans[pos[0]]=1,ans[pos[1]]=n,rev[1]=pos[0],rev[n]=pos[1];
	}
	for(int i=2;i<=n/2;i++)
	{
		vector<int> pos;
		for(int j=1;j<=n;j++)
		{
			vector<int> tmp;
			for(int k=1;k<=n;k++) if(j!=k&&!ans[k]) tmp.pb(k);
			if(query(tmp)) pos.pb(j);
		}
		if(query({rev[i-1],pos[0]})) swap(pos[0],pos[1]);
		ans[pos[0]]=i,ans[pos[1]]=n-i+1,rev[i]=pos[0],rev[n-i+1]=pos[1];
	}
	final_fix();
	printf("! "); for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
#ifdef wasa855
	printf("A "); for(int i=1;i<=n;i++) printf("%d%c",sre[i]," \n"[i==n]);
#endif
	exit(0);
}
vector<int> a[15][15];
int p[N];
int get(int pos,int md)
{
	for(int i=0;i<md;i++) p[i]=i;
	shuffle(p,p+md,rnd);
	for(int i=0;i+1<md;i++)
	{
		vector<int> qry=a[md][p[i]];
		qry.pb(pos);
		if(query(qry)) return (md-p[i])%md;
	}
	return (md-p[md-1])%md;
}
signed main()
{
	n=read();
#ifdef wasa855
	for(int i=1;i<=n;i++) sre[i]=i;
	shuffle(sre+1,sre+n+1,rnd);
	if(sre[1]>n/2) for(int i=1;i<=n;i++) sre[i]=n-sre[i]+1;
#endif
	if(n<=10) small();
	{
		vector<int> pos;
		for(int i=1;i<=n;i++)
		{
			vector<int> tmp;
			for(int j=1;j<=n;j++) if(i!=j) tmp.pb(j);
			if(query(tmp)) pos.pb(i);
		}
		ans[pos[0]]=1,ans[pos[1]]=n,rev[1]=pos[0],rev[n]=pos[1];
	}
	for(int i=2;i<=5;i++)
	{
		vector<int> pos;
		for(int j=1;j<=n;j++)
		{
			vector<int> tmp;
			for(int k=1;k<=n;k++) if(j!=k&&!ans[k]) tmp.pb(k);
			if(query(tmp)) pos.pb(j);
		}
		if(query({rev[i-1],pos[0]})) swap(pos[0],pos[1]);
		ans[pos[0]]=i,ans[pos[1]]=n-i+1,rev[i]=pos[0],rev[n-i+1]=pos[1];
	}
	vector<int> val,curpos;
	for(int i=1;i<=n;i++) if(ans[i]) val.pb(ans[i]),curpos.pb(i);
	for(int i=1;i<1<<10;i++)
	{
		int sum=0;
		for(int j=0;j<10;j++) if(i>>j&1) sum+=val[j];
		int pp=__builtin_popcount(i)+1;
		sum%=pp;
		if(!a[pp][sum].empty()) continue;
		for(int j=0;j<10;j++) if(i>>j&1) a[pp][sum].pb(curpos[j]);
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]) continue;
		int md3=get(i,3),md5=get(i,5),md7=get(i,7),md8=get(i,8);
//		printf("%d - %d %d %d %d\n",i,md3,md5,md7,md8);
		for(int j=1;j<=n;j++)
		{
			if(j%3==md3&&j%5==md5&&j%7==md7&&j%8==md8) ans[i]=j;
		}
	}
	final_fix();
	printf("! "); for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
#ifdef wasa855
	printf("%d/%d\n",cnt,n*18);
	printf("A "); for(int i=1;i<=n;i++) printf("%d%c",sre[i]," \n"[i==n]);
#endif
	return 0;
}