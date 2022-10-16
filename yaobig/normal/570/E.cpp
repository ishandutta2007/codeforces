#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5][maxn+5];
int dp[2][maxn+5][maxn+5];
int n,m; 

const int lmov[2][2]={{-1,0},{0,-1}};
const int rmov[2][2]={{1,0},{0,1}};

bool valid(int x,int y)
{
	return x>0 && x<=n && y>0 && y<=m;
}

int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%s",s[i]+1);
	if(s[1][1]!=s[n][m]) puts("0");
	else
	{
		int ans=0;
		dp[1][1][n]=1;
		rep(k,2,(n+m)/2) 
		{
			int s1=k+1,s2=n+m+1-k;
			rep(x1,1,n)
			{
				int y1=s1-x1;
				if(y1<1 || y1>m) continue;
				rep(x2,1,n)
				{
					int y2=s2-x2;
					if(y2<1 || y2>m) continue;
					dp[k&1][x1][x2]=0;
					if(s[x1][y1]!=s[x2][y2]) continue;
					rep(i,0,1) rep(j,0,1)
					{
						int nx1=x1+lmov[i][0]; int ny1=y1+lmov[i][1];
						int nx2=x2+rmov[j][0]; int ny2=y2+rmov[j][1];
						if(valid(nx1,ny1) && valid(nx2,ny2)) dp[k&1][x1][x2]=(dp[k&1][x1][x2]+dp[k-1&1][nx1][nx2])%mod;
					}
					if(abs(x1-x2)+abs(y1-y2)<=1) ans=(ans+dp[k&1][x1][x2])%mod;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}