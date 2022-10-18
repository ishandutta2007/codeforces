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
#define mod 998244353
#define int long long
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
#define N 15
char _s[N];
int d[N],a[N],n,tot,car[N],pw[N],ans;
int s[1<<14],f[1<<14];
int lg[1<<14];
int lowbit(int x) {return x&(-x);}
void solve()
{
	for(int i=0;i<n;i++) d[i]=a[i];
//	for(int i=0;i<n;i++) printf("%d%c",d[i]," \n"[i==n-1]);
	for(int i=0;i<n;i++) if(car[i]) d[i]-=16,d[i+1]++;
//	for(int i=0;i<n;i++) printf("%d%c",d[i]," \n"[i==n-1]);
	memset(f,0x3f,sizeof(f));
	f[0]=0,s[0]=d[n-1];
	int ful=1<<(n-1);
	for(int i=1;i<ful;i++) s[i]=s[i^lowbit(i)]+d[lg[lowbit(i)]];
//	for(int i=0;i<ful;i++) printf("%d%c",s[i]," \n"[i==ful-1]);
	if(s[ful-1]<0||s[ful-1]>15) return ;
	for(int i=0;i<ful;i++)
	{
		if(s[i]<0||s[i]>15) continue;
		for(int j=0;j<n;j++) if(!(i>>j&1))
		{
			f[i^(1<<j)]=min(f[i^(1<<j)],f[i]+(s[i]<<(j*4)));
		}
	}
//	for(int i=0;i<n;i++) printf("%d ",d[i]);
//	printf(": %lld\n",f[ful-1]);
	ans=min(ans,f[ful-1]);
}
void dfs(int cur,int res)
{
	if(cur==n)
	{
		if(!res) solve();
		return ;
	}
	if(res&&cur!=n-1)
	{
		car[cur]=1;
		dfs(cur+1,res-1);
	}
	car[cur]=0;
	dfs(cur+1,res);
}
signed main()
{
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=pw[i-1]*16;
	for(int i=2;i<1<<14;i++) lg[i]=lg[i/2]+1;
	scanf("%s",_s); n=strlen(_s);
	reverse(_s,_s+n);
	int s=0;
	for(int i=0;i<n;i++)
	{
		if('0'<=_s[i]&&_s[i]<='9') a[i]=_s[i]-'0';
		else a[i]=_s[i]-'a'+10;
		s+=a[i];
	}
	if(s%15!=0) cout<<"NO\n",exit(0);
	tot=s/15;
	ans=INF;
	dfs(0,tot);
	if(ans==INF) cout<<"NO\n",exit(0);
	for(int i=n-1;i>=0;i--)
	{
		int v=ans/pw[i]%16;
		if(v<=9) putchar(v+'0');
		else putchar(v-10+'a');
	}
	cout<<"\n";
	return 0;
}