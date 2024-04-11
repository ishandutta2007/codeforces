#include <bits/stdc++.h>
using namespace std;

#define ROAD false
#define RAIL true

struct bfsType
{
	int pos, dist;
}temp, now;

int main()
{
	ios::sync_with_stdio ( false );

	int n, m, u, v, ans = -1;
	bool needed;
	cin >> n >> m;
	vector < vector < bool > > graph ( n );
	for ( int i = 0; i < n; i++ ) graph[i].resize ( n, ROAD );

	for ( int i = 0; i < m; i++ ){
		cin >> u >> v;
		u--;v--;
		graph[u][v] = graph[v][u] = RAIL;
	}

	needed = ( graph[0][n-1] == false );
	
	deque < bfsType > q;
	vector < bool > vis ( n, false );
	temp.pos = temp.dist = 0;
	q.push_back ( temp );
	while ( ( ans == -1 ) && ( !q.empty() ) ){
		now = q[0];
		q.pop_front();

		for ( int i = 0; i < n; i++ ){
			if ( ( !vis[i] ) && ( graph[now.pos][i] == needed ) && ( i != now.pos ) ){
				vis[i] = true;
				temp.pos = i;
				temp.dist = now.dist + 1;
				q.push_back ( temp );

				if ( i == n-1 ){
					ans = now.dist + 1;
					break;
				}
			}
		}
	}

	cout << ans << endl;
}