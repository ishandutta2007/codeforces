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
#define N 85
int a[N][N];
int f[N][15];
int col[N],n,k;
signed main()
{
	srand(time(NULL));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	int ans=INF;
	while((double)clock()/CLOCKS_PER_SEC<=2.7)
	{
		for(int i=1;i<=n;i++) col[i]=rand()&1;
		for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) f[i][j]=INF;
		f[1][0]=0;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int c=1;c<=n;c++)
				{
					if(col[j]!=col[c])
					{
						if(f[c][i-1]+a[c][j]<f[j][i])
						{
							f[j][i]=f[c][i-1]+a[c][j];
						}
					}
				}
			}
		}
		if(f[1][k]<ans) ans=f[1][k];
	}
	cout<<ans<<endl;
	return 0;
}