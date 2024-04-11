#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
vector<int> v;
const int N=5050;
int dp[N],go[N],w[N],h[N];
bool comp(int a, int b){ return w[a]>w[b];}
int main()
{
	int n,i,j,we,hi;
	scanf("%i %i %i",&n,&we,&hi);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&w[i],&h[i]);
		if(w[i]>we && h[i]>hi) v.pb(i);
	}
	if(v.empty()) return printf("0\n"),0;
	sort(v.begin(),v.end(),comp);
	for(i=0;i<v.size();i++)
	{
		dp[v[i]]=1;
		for(j=0;j<i;j++)
		{
			if(w[v[j]]>w[v[i]] && h[v[j]]>h[v[i]])
			{
				if(dp[v[j]]+1>dp[v[i]])
				{
					dp[v[i]]=dp[v[j]]+1;
					go[v[i]]=v[j];
				}
			}
		}
	}
	int taj=0;
	for(i=1;i<=n;i++) if(dp[taj]<dp[i]) taj=i;
	printf("%i\n",dp[taj]);
	while(taj) printf("%i ",taj),taj=go[taj];
	printf("\n");
	return 0;
}