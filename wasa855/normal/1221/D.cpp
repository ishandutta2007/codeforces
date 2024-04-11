#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 300005
#define INF (1e18+5)
int a[N],b[N];
int f[N][3];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=2;j++) f[i][j]=INF;
	}
	a[0]=-10;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=2;j++)
		{
			for(int k=0;k<=2;k++)
			{
				if(a[i]+j==a[i-1]+k) continue;
				if(f[i-1][k]+b[i]*j<f[i][j]) f[i][j]=f[i-1][k]+b[i]*j;
			}
		}
	}
	printf("%lld\n",min(min(f[n][0],f[n][1]),f[n][2]));
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}