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

void add(int &x,int y) {x=x+y<mod?x+y:x+y-mod;}

int dp[maxn+5][maxn+5];
int a[maxn+5];


int main()
{
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) dp[i][i]=1;
	rep(L,2,n) rep(l,1,n-L+1)
	{
		int r=l+L-1;
		dp[l][r]=dp[l+1][r];
		rep(i,l+2,r) if(a[l+1]<a[i]) add(dp[l][r],1ll*dp[l+1][i-1]*dp[i-1][r]%mod);
	}
	printf("%d\n",dp[1][n]);
	return 0;
}