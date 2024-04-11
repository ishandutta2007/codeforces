#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>
const int mod=1000000007;

string a, b, c;
int P[200005], dp[200005], pp[200005], pp2[200005];


void kmp()
{
	for(int i=1; i<(int)c.size(); i++)
	{
		int x=P[i-1];
		while(x!=0 && c[x]!=c[i]) x=P[x-1];
		P[i]=x;
		if(c[i]==c[x]) P[i]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> a >> b;
	int s=b.size(), last=-1;
	c=b+'#'+a;
	kmp();
	//for(int i=0; i<(int)c.size(); i++) printf("%d\n", P[i]);
	for(int i=0; i<(int)a.size(); i++)
	{
		if(P[i+s+1]==s)
		{
			last=i;
			//printf("%d\n", i);
			dp[i]+=i-s+2;
			if(i>=s) dp[i]+=pp2[i-s];
			if(dp[i]>=mod) dp[i]-=mod;
		}
		else if(last!=-1) dp[i]=dp[last];
		if(i>0) pp[i]=(pp[i-1]+dp[i])%mod;
		else pp[i]=dp[i];
		if(i>0) pp2[i]=(pp2[i-1]+pp[i])%mod;
		else pp2[i]=pp[i];
	}
	//for(int i=0; i<(int)a.size(); i++) printf("%d\n", dp[i]);
	cout<< pp[a.size()-1] << '\n';
	return 0;
}