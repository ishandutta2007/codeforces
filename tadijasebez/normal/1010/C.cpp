#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;
#define ll long int
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
//bitset<200050> sol;
vector<int> val;
bool was[100050];
int main()
{
	int n,k,i,x,j;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		x%=k;
		val.pb(x);
	}
	vector<int> ans;
	sort(val.begin(),val.end());
	for(i=0;i<val.size();i++)
	{
		if(was[val[i]]) continue;
		was[val[i]]=1;
		ans.pb(val[i]);
		for(j=0;j<ans.size();j++)
		{
			x=(ans[j]+val[i])%k;
			if(!was[x])
			{
				was[x]=1;
				ans.pb(x);
			}
		}
	}
	sort(ans.begin(),ans.end());
	printf("%i\n",ans.size());
	for(i=0;i<ans.size();i++) printf("%i ",ans[i]);
	return 0;
}