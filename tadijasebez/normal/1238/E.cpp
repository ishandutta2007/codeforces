#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int M=1<<20;
const int N=100050;
ll dp[M];
char s[N];
int cnt[20][20];
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<n;i++) if(s[i]!=s[i+1]) cnt[s[i]-'a'][s[i+1]-'a']++,cnt[s[i+1]-'a'][s[i]-'a']++;
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) dp[1<<i]-=cnt[i][j];
	for(int mask=1;mask<(1<<m);mask++) if(__builtin_popcount(mask)!=1)
	{
		int pc=__builtin_popcount(mask);
		dp[mask]=9e18;
		for(int i=0;i<m;i++) if(mask>>i&1)
		{
			ll sum=dp[mask^(1<<i)];
			for(int j=0;j<m;j++)
			{
				if(mask>>j&1) sum+=(ll)cnt[i][j]*pc;
				else sum-=(ll)cnt[i][j]*pc;
			}
			dp[mask]=min(dp[mask],sum);
		}
	}
	printf("%lld\n",dp[(1<<m)-1]);
	return 0;
}