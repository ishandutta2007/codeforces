#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int mx[500005],ans[500005],cnt;
vector <int> e[500005];
set <int> S[500005];
pair <int,int> a[500005];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].first);
		--a[i].first,a[i].second=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		//cout << a[i].first << " " << a[i].second << " " << S[a[i].second].size() << "\n";
		if(a[i].first!=S[a[i].second].size()||S[a[i].second].find(a[i].first)!=S[a[i].second].end())
		{
			puts("-1");
			return 0;
		}
		for(auto v:e[a[i].second])
			S[v].insert(a[i].first);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i].second);
	return 0;
}