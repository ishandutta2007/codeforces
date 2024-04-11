#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 4000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int n,a[maxn+5],s[maxn+5];
int dp[2][2500+5][200][95];
const int B=95;

int sum(int l,int r) {return s[r]-s[l-1];}

int dfs(int pl,int l,int r,int k)
{
	if(r-l+1<k) return 0;
	if(dp[pl][l][l-(n-r)+B][k]!=inf) return dp[pl][l][l-(n-r)+B][k];
	int res=0;
	if(pl==0)
	{
		res=dfs(pl^1,l+k,r,k)+sum(l,l+k-1);
		if(r-l+1>=k+1) res=max(res,dfs(pl^1,l+k+1,r,k+1)+sum(l,l+k));
	}
	else
	{
		res=dfs(pl^1,l,r-k,k)-sum(r-k+1,r);
		if(r-l+1>=k+1) res=min(res,dfs(pl^1,l,r-k-1,k+1)-sum(r-k,r));
	}
	return dp[pl][l][l-(n-r)+B][k]=res;
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	memset(dp,63,sizeof dp);
	printf("%d\n",dfs(0,1,n,1));
	return 0;
}