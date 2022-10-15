/*input
5 7
1 2 2
2 4 1
4 1 4
2 5 3
5 4 1
5 2 4
2 1 1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unistd.h>
using namespace __gnu_pbds;
using namespace std;

#define ws(x) cerr << #x << " is " << x << endl

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedTree;

typedef long long ll;
#define mp make_pair

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<pair<int, ll> > adj[N], rAdj[N];

	for(int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].push_back(mp(v, w));
		rAdj[v].push_back(mp(u, w));
	}

	const ll INF = 1e15;

	ll dist[N][2];
	for(int i = 0; i < N; i++)
		dist[i][0] = dist[i][1] = INF;
	dist[0][0] = 0;

	bool visited[N][2] = {};

	priority_queue<pair<ll, pair<int, int> >, vector<pair<ll, pair<int, int> > >, greater<pair<ll, pair<int, int> > > > pq;
	pq.push(mp(0, mp(0, 0)));

	while(!pq.empty())
	{
		auto g = pq.top();
		pq.pop();
		
		ll d = g.first;
		int u = g.second.first, dir = g.second.second;

		if(visited[u][dir])
			continue;
		visited[u][dir] = true;

		if((dir == 0) && (dist[u][1] > dist[u][0]))
		{
			dist[u][1] = dist[u][0];
			pq.push(mp(dist[u][1], mp(u, 1)));
		}

		if(dir == 0)
		{
			for(auto e : adj[u])
			{
				int v = e.first, w = e.second;
				if(dist[v][dir] > dist[u][dir] + w)
				{
					dist[v][dir] = dist[u][dir] + w;
					pq.push(mp(dist[v][dir], mp(v, dir)));
				}
			}
		}
		else
		{
			for(auto e : rAdj[u])
			{
				int v = e.first, w = e.second;
				if(dist[v][dir] > dist[u][dir] + w)
				{
					dist[v][dir] = dist[u][dir] + w;
					pq.push(mp(dist[v][dir], mp(v, dir)));
				}
			}
		}
	}

	for(int i = 1; i < N; i++)
	{
		if(dist[i][1] == INF)
			dist[i][1] = -1;
		cout << dist[i][1] << " ";
	}

	return 0;
}