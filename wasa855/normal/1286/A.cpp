#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 105
#define INF 0x3f3f3f3f
int a[N];
int f[N][N][N][2];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	memset(f,0x3f,sizeof(f));
	f[0][0][0][0]=f[0][0][0][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n/2;j++)
		{
			int k=i-j;
			if(k<0) break;
			if(a[i]==0)
			{
				f[i][j][k][0]=j?min(f[i-1][j-1][k][0],f[i-1][j-1][k][1]+1):INF;
				f[i][j][k][1]=k?min(f[i-1][j][k-1][0]+1,f[i-1][j][k-1][1]):INF;
			}
			else
			{
				if(a[i]&1) f[i][j][k][1]=k?min(f[i-1][j][k-1][0]+1,f[i-1][j][k-1][1]):INF;
				else j?f[i][j][k][0]=min(f[i-1][j-1][k][0],f[i-1][j-1][k][1]+1):INF;
			}
//			printf("%d %d %d %d %d\n",i,j,k,f[i][j][k][0],f[i][j][k][1]);
		}
	}
	if(a[n]&1) cout<<f[n][n/2][(n+1)/2][a[n]&1]<<endl;
	else cout<<min(f[n][n/2][(n+1)/2][0],f[n][n/2][(n+1)/2][1])<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}