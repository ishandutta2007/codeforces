#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5],p[maxn+5];
int dp[maxn+5];
int ans[maxn+5];


int main()
{
	scanf("%s%s",s,p);
	int n=strlen(s);	
	int N=strlen(p);
	rep(i,0,n-1) p[i]=p[i%N];
	memset(dp,63,sizeof dp);
	dp[0]=0;
	rep(i,0,n-1) per(j,1,n)
	{
		if(j%N) dp[j]++;
		if(s[i]==p[j-1]) dp[j]=min(dp[j],dp[j-1]);
	}
	rep(j,0,n) if(j%N==0)
	{
		rep(i,dp[j],n-j) ans[i]=max(ans[i],j/N);
	}
	rep(i,0,n) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}