#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=300050;
map<int,int> cnt;
int a[N];
vector<pair<int,int> > sol;
int main()
{
	int n,i,j,k;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i=j+1)
	{
		for(j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			if(cnt[a[j]]>1) break;
		}
		if(j>n) break;
		sol.pb(mp(i,j));
		for(k=i;k<=j;k++) cnt[a[k]]--;
	}
	if(sol.empty()) return printf("-1\n"),0;
	sol[sol.size()-1].second=n;
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}