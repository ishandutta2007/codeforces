#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

db f[maxn+5][maxn+5];
int a[maxn+5];

int main()
{
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) rep(j,1,n) f[i][j]=a[i]>a[j]?1.0:0.0;
	rep(i,1,m)
	{
		int a,b; scanf("%d%d",&a,&b);
		rep(j,1,n) if(j!=a && j!=b) 
		{
			f[j][a]=f[j][b]=(f[j][a]+f[j][b])/2.0;
			f[a][j]=f[b][j]=(f[a][j]+f[b][j])/2.0;
		}
		f[a][b]=f[b][a]=(f[a][b]+f[b][a])/2.0;
	}
	db ans=0;
	rep(i,1,n) rep(j,i+1,n) ans+=f[i][j];
	printf("%.10f\n",ans);
	return 0;
}