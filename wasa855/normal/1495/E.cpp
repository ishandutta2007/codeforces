#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 1000000007
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
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
#define N 5000005
int a[N],t[N],ans[N],n,m;
int seed,base;
int rnd()
{
	int ret=seed;
	seed=(1LL*seed*base+233)%1000000007;
	return ret;
}
int nxt(int x) {return x==n?1:x+1;}
signed main()
{
	cin>>n>>m; int las=0;
	for(int i=1;i<=m;i++)
	{
		int p=read(),k=read(),b=read(),w=read();
		seed=b,base=w;
		for(int i=las+1;i<=p;i++) t[i]=rnd()&1,a[i]=rnd()%k+1;
		las=p;
	}
	ll s0=0,s1=0;
	for(int i=1;i<=n;i++)
	{
		if(t[i]==0) s0+=a[i];
		else s1+=a[i];
	}
	bool als=1;
	for(int i=2;i<=n;i++) als&=t[i]==t[i-1];
	if(als) ans[1]=1;
	else
	{
		if(s1<s0)
		{
			swap(s0,s1);
			for(int i=1;i<=n;i++) t[i]^=1;
		}
		// for(int i=1;i<=n;i++) printf("%d%c",t[i]," \n"[i==n]);
		// for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		int cur=1;
		if(t[1]==1)
		{
			a[1]--,ans[1]++;
			cur=nxt(1); las=1;
			while(t[cur]==t[las]) cur=nxt(cur);
		}
		ll tmp=0;
		for(int i=1;i<=n*2;i++)
		{
			// printf("%d %d %d\n",i,cur,t[cur]);
			if(!t[cur]) tmp+=a[cur],ans[cur]+=a[cur],a[cur]=0;
			else
			{
				int go=min(tmp,(ll)a[cur]);
				ans[cur]+=go,tmp-=go,a[cur]-=go;
			}
			cur=nxt(cur);
		}
	}
	// for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	int Ans=1;
	for(int i=1;i<=n;i++)
	{
		ll r=ans[i]^(1LL*i*i);
		Ans=mul(Ans,(r+1)%mod);
	}
	cout<<Ans<<endl;
	return 0;
}