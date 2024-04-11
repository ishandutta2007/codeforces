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
#define N 300005
int c[N],k[N],sum[N];
void work()
{
	int n,m; cin>>n>>m;
	// for(int i=1;i<=m;i++) k[i]=0;
	// for(int i=1;i<=n;i++) k[read()]++;
	for(int i=1;i<=n;i++) k[i]=read();
	sort(k+1,k+n+1);
	for(int i=1;i<=m;i++) c[i]=read();
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+c[k[i]];
	// for(int i=1;i<=m;i++) printf("%d%c",sum[i]," \n"[i==m]);
	int ans=sum[n],cur=0;
	// for(int i=1;i<=m;i++)
	// {
		// for(int j=1;j<=k[i];j++) sum[cur+1]=sum[cur]+c[i],cur++;
	// }
	int tmp=0;
	for(int i=1;i<=m;i++)
	{
		tmp+=c[i];
		if(k[n-i+1]>=i) ans=min(ans,tmp+sum[n-i]);
		// printf("%d %d\n",i,tmp+sum[m-i]);
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}