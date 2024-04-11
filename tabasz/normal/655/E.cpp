#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
const int mod=1e9+7;

int n, k;
string s;
int dp[2000005], last[30], T[1000005];
priority_queue<PII> Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n >> k >> s;
	dp[0]=1;
	for(int i=1; i<=(int)s.size(); i++)
		T[i]=(int)s[i-1]-(int)'a';
	for(int i=1; i<=(int)s.size(); i++)
	{
		if(last[T[i]]==0)
			dp[i]=dp[i-1]+dp[i-1];
		else
		{
			int x=dp[i-1]-dp[last[T[i]]-1];
			if(x<0)
				x+=mod;
			dp[i]=dp[i-1]+x;
		}
		if(dp[i]>=mod)
			dp[i]-=mod;
		last[T[i]]=i;
	}
	for(int i=0; i<k; i++)
		Q.push(MP(-last[i], i));
	for(int i=(int)s.size()+1; i<=(int)s.size()+n; i++)
	{
		PII x=Q.top();
		Q.pop();
		if(last[x.S]==0)
			dp[i]=dp[i-1]+dp[i-1];
		else
		{
			int y=dp[i-1]-dp[last[x.S]-1];
			if(y<0)
				y+=mod;
			dp[i]=dp[i-1]+y;
		}
		if(dp[i]>=mod)
			dp[i]-=mod;
		last[x.S]=i;
		Q.push(MP(-last[x.S], x.S));
	}
	printf("%d\n", dp[(int)s.size()+n]);
	return 0;
}