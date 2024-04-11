#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
vector<pair<int,int>> seg[N];
int main()
{
	int n,m,i,x,y;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i",&x,&y),seg[n-y+1].pb({x,i});
	set<pair<int,int>> all;
	vector<int> ans;
	for(i=1;i<=n;i++)
	{
		for(auto p:seg[i]) all.insert(p);
		while(all.size() && all.begin()->first<i) all.erase(all.begin());
		if(all.size())
		{
			ans.pb(all.begin()->second);
			all.erase(all.begin());
		}
	}
	printf("%i\n",ans.size());
	for(int j:ans) printf("%i ",j);
	return 0;
}