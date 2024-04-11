#pragma GCC optimze(3)
#pragma GCC target("avx")
#pragma GCC target("popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("no-stack-protector")
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
#define N 100005
#define lim 600
double f[2][lim+5],g[2][lim+5];
signed main()
{
	int n,k; cin>>n>>k;
	double p=1.0/k;
	f[0][1]=0,g[0][1]=1;
	for(int i=0;i<n;i++)
	{
		memset(g[i+1&1],0,sizeof(g[i+1&1]));
		memset(f[i+1&1],0,sizeof(f[i+1&1]));
		for(int j=1;j<=min(i,lim)+1;j++)
		{
			double A=1.0/(j+1);
			double B=p*(1-A),C=A*p;
			g[i+1&1][j]+=g[i&1][j]*(1-p+B);
			g[i+1&1][j+1]+=g[i&1][j]*C;
			f[i+1&1][j]+=f[i&1][j]*(1-p+B);
			f[i+1&1][j]+=j/2.0*g[i&1][j]*p;
			f[i+1&1][j+1]+=f[i&1][j]*C+(B*g[i&1][j]);
		}
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=i+1;j++) printf("%.2lf ",f[i][j]);
		// cout<<"\n";
	// }
	double ans=0;
	for(int i=1;i<=lim;i++) ans+=f[n&1][i];
	printf("%.9lf",ans*k);
	return 0;
}