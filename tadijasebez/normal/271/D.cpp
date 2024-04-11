#include <bits/stdc++.h>
using namespace std;
const int N=1550;
#define ll long long
const ll mod=99194853094755497ll;
map<ll ,bool> vis;
char w[N],Good[26];
int dp[N],sol;
ll Mod(ll x){ return x>mod?x-mod:x;}
int main()
{
	scanf("%s",&w);
	scanf("%s",&Good);
	int n,i,j,k,l;
	scanf("%i",&k);
	n=strlen(w);
	for(i=0;i<n;i++) dp[i+1]=dp[i]+((Good[w[i]-'a']=='0')?1:0);
	for(i=0;i<n;i++)
	{
		ll hash=0;
		for(j=i;j<n;j++)
		{
			for(l=0;l<26;l++) hash=Mod(hash+hash);
			hash=Mod(hash+w[j]-'a'+1);
			if(dp[j+1]-dp[i]<=k) sol+=1-vis[hash],vis[hash]=1;
		}
	}
	printf("%i\n",sol);
	return 0;
}