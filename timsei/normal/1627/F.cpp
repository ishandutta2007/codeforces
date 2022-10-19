#include<bits/stdc++.h>
using namespace std;

const int N = 505;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, k, a, b, c, d;
// map 

map < tuple <int, int, int, int>, int> Map;

struct Node {
	int x, y, w;
	friend bool operator < (Node a, Node b) {
		return a.w > b.w;
	}
};

priority_queue < Node > q;
bool vis[N][N];

int main() {
	int t;
	for(cin >> t; t --;) {
		Map.clear();
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++ i) {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if(a > c) swap(a, c); if(b > d) swap(b, d);
			if(a == c) {
				Map[{a - 1, b, a, b}] ++, Map[{a, b, a - 1, b}] ++;
			} else 
			Map[{a, b, a, b - 1}] ++, Map[{a, b - 1, a, b}] ++;
			
		}
		memset(vis, 0, sizeof(vis));
		while(!q.empty()) q.pop();
		q.push((Node){k / 2, k / 2, 0});
		while(1) {
			auto [x, y, w] = q.top(); q.pop();
			if(x == k || y == k || !x || !y) {
				printf("%d\n", n - w);
				break;
			}
			vis[x][y] = 1;
			for(int i = 0; i < 4; ++ i) {
				int a = x + dx[i], b = y + dy[i];
				if(vis[a][b] || vis[k - a][k - b]) continue;
				int ww = w + Map[{x, y, a, b}] + Map[{k - x, k - y, k - a, k - b}];
				q.push((Node){a, b, ww});
			}
		}
	}
}