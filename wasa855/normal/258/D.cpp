#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1005
double f[N][N];
int a[N];
signed main()
{
	int n,Q;
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) f[i][j]=a[i]>a[j];
	}
	while(Q--)
	{
		int u=read(),v=read();
		f[u][v]=f[v][u]=(f[u][v]+f[v][u])/2.0;
		for(int i=1;i<=n;i++)
		{
			if(i==u||i==v) continue;
			f[i][u]=f[i][v]=(f[i][u]+f[i][v])/2.0;
			f[u][i]=f[v][i]=(f[u][i]+f[v][i])/2.0;
		}
	}
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++) ans+=f[i][j];
	}
	printf("%.7lf\n",ans);
	return 0;
}