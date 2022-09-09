#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define pb push_back
const int N=200050;
int dp[N],go[N],a[N];
map<int,int> last;
int main()
{
	int n,i,taj=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		dp[i]=dp[last[a[i]-1]]+1;
		go[i]=last[a[i]-1];
		last[a[i]]=i;
		if(dp[i]>dp[taj]) taj=i;
	}
	vector<int> sol;
	while(taj) sol.pb(taj),taj=go[taj];
	reverse(sol.begin(),sol.end());
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	printf("\n");
	return 0;
}