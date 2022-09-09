#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=200050;
char s[N];
int dp[N][5];
// 0 nista
// 1 o
// 2 on
// 3 t
// 4 tw
void Solve()
{
	int n=strlen(s+1);
	vector<int> ans;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e')
		{
			ans.pb(i+1);
			i+=2;
		}
		else if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o')
		{
			if(s[i+3]=='n' && s[i+4]=='e')
			{
				ans.pb(i+2);
				i+=4;
			}
			else
			{
				ans.pb(i+1);
				i+=2;
			}
		}
	}
	printf("%i\n",ans.size());
	for(int i:ans) printf("%i ",i);
	printf("\n");
	/*dp[0][0]=0;
	for(int i=1;i<=4;i++) dp[0][i]=1e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<5;j++) dp[i][j]=dp[i-1][j]+1;
		if(s[i]=='o')
		{
			for(int j=0;j<4;j++) ckmn(dp[i][1],dp[i-1][j]);
		}
		else if(s[i]=='n')
		{
			ckmn(dp[i][2],dp[i-1][1]);
			for(int j=0;j<5;j++) if(j!=1) ckmn(dp[i][0],dp[i-1][j]);
		}
		else if(s[i]=='t')
		{
			for(int j=0;j<5;j++) ckmn(dp[i][3],dp[i-1][j]);
		}
		else if(s[i]=='w')
		{
			ckmn(dp[i][4],dp[i-1][3]);
			for(int j=0;j<5;j++) if(j!=3) ckmn(dp[i][0],dp[i-1][j]);
		}
		else if(s[i]=='e')
		{
			for(int j=0;j<5;j++) if(j!=2) ckmn(dp[i][0],dp[i-1][j]);
		}
		else
		{
			for(int j=0;j<5;j++) ckmn(dp[i][0],dp[i-1][j]);
		}
	}
	int ans=1e9;
	for(int i=0;i<5;i++) ckmn(ans,dp[n][i]);
	printf("%i\n",ans);*/
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--) scanf("%s",s+1),Solve();
	return 0;
}