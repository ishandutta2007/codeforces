/*input
4
1 2
2 3
2 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> *G[1000001];
int dom[1000001];
vector<int>adj[1000001];
int D[1000001];
void dfs(int i, int p)
{
	int kkk = 0;
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		dfs(j, i);
		kkk = 1;
	}
	dom[i] += kkk;
	G[i]->push_back(1);
	if ((*G[i])[G[i]->size() - 1 - dom[i]] <= 1)
		dom[i] = 0;
	while (G[i]->back() == 0)
		G[i]->pop_back();
	D[i] = dom[i];
	if (i == p)
		return;

	if (G[i]->size() > G[p]->size())
	{
		swap(G[i], G[p]);
		swap(dom[i], dom[p]);
	}
	int gal = 0;
	int mx = -1;
	for (int a = 0; a < (*G[i]).size(); a++)
	{
		(*G[p])[G[p]->size() - 1 - a] += (*G[i])[G[i]->size() - 1 - a];
		if ((*G[p])[G[p]->size() - 1 - a] > mx)
			gal = a;
		mx = max(mx, (*G[p])[G[p]->size() - 1 - a]);
	}
	G[i]->clear();
	if (gal >= dom[p] || (*G[p])[G[p]->size() - 1 - gal] >= (*G[p])[G[p]->size() - 1 - dom[p]])
		dom[p] = gal;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		G[i] = new vector<int>();
		G[i]->push_back(0);
		dom[i] = 0;
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
		cout << D[i] << "\n";
}