#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
vector<int> E[N];
bool was[N];
int main()
{
	vector<int> ans;
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	set<int> q;
	q.insert(1);
	while(q.size())
	{
		int x=*q.begin();
		q.erase(q.begin());
		was[x]=1;
		ans.pb(x);
		for(int y:E[x]) if(!was[y]) q.insert(y);
	}
	for(int x:ans) printf("%i ",x);
	return 0;
}