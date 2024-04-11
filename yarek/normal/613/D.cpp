#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int N = 100001;
vector<int> g[N];
int parent[N];
set<int> s[N];
int ans[N];
int imp[N];

void dfs1(int v, int prev)
{
    parent[v] = prev;
    for(int u: g[v])
	if(u != prev)
	    dfs1(u, v);
}

set<int>* dfs2(int v)
{
    set<int> free;
    set<int> *sum = nullptr;
    for(int u: g[v])
	if(u != parent[v])
	{
	    set<int> *us = dfs2(u);
	    if(sum == nullptr) sum = us;
	    else
	    {
		if(us->size() > sum->size()) swap(us, sum);
		for(auto k: *us)
		    if(sum->insert(k).second == false)
		    {
			if(!free.count(k)) ans[k]++;
			if(!s[v].count(k)) free.insert(k);
		    }
		us->clear();
	    }
	}
    for(auto k: free)
	sum->erase(k);
    free.clear();
    if(sum)
    {
	auto ns = &s[v];
	if(ns->size() > sum->size())
	    swap(sum, ns);
	for(auto k: *ns)
	    if(sum->insert(k).second == false)
		ans[k]++;
	ns->clear();
	return sum;
    }
    else return &s[v];
}

int main()
{
    int n, q;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
	int a, b;
	scanf("%d %d", &a, &b);
	g[a].push_back(b);
	g[b].push_back(a);
    }
    dfs1(1, 0);
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
	int k;
	scanf("%d", &k);
	for(int j = 0; j < k; j++)
	    scanf("%d", imp + j);
	sort(imp, imp + k);
	for(int j = 0; j < k; j++)
	    if(binary_search(imp, imp + k, parent[imp[j]]))
		ans[i] = -1;
	if(ans[i] != -1)
	    for(int j = 0; j < k; j++)
		s[imp[j]].insert(i);
    }
    dfs2(1);
    for(int i = 0; i < q; i++)
	printf("%d\n", ans[i]);
}