#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#define OVER9000 1234567890
#define soclose 1e-4
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > adj(2*N);
	vector< vector<int> > cap(2*N, vector<int>(2*N, 0));
	vector< vector<int> > cost(2*N, vector<int>(2*N, 0));
	for(int i = 0; i < N; i++) {
		adj[2*i].push_back(2*i+1);
		adj[2*i+1].push_back(2*i);
		cap[2*i][2*i+1] = N;
	}
	for(int i = 0; i < M; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		if(from == N || to == 1 || from == to) continue;
		from = 2*(from-1)+1, to = 2*(to-1);
		adj[from].push_back(to);
		adj[to].push_back(from);
		cost[from][to] = w;
		cost[to][from] = -w;
		cap[from][to] = 1;
	}
	N *= 2;
	vector<int> path_len_seq;
	for(int f = 0; f < N; f++) {
		vector<int> d(N, OVER9000);
		d[0] = 0;
		vector<int> m(N, 2);
		static deque<int> q;
		q.push_back(0);
		vector<int> p(N, -1);
		while(!q.empty()) {
			int u = q.front();
			q.pop_front();
			m[u] = 0;
			for(int v : adj[u]) {
				if(cap[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
					d[v] = d[u] + cost[u][v];
					p[v] = u;
					if(m[v] == 2) {
						m[v] = 1;
						q.push_back(v);
					}
					else if(m[v] == 0) {
						m[v] = 1;
						q.push_front(v);
					}
				}
			}
		}
		if(d[N-1] == OVER9000) break;
		path_len_seq.push_back(d[N-1]);
		int cur = N-1;
		while (cur) {
			cap[p[cur]][cur]--;
			cap[cur][p[cur]]++;
			cur = p[cur];
		}
	}
	int Q;
	cin >> Q;
	for(int q = 0, x; q < Q; q++) {
		cin >> x;
		double ans = 0, sum = 0;
		for(int i = 0; i < (int)path_len_seq.size(); i++) {
			sum += path_len_seq[i];
			double l = (x+sum) / (i+1);
			if(path_len_seq[i] > l+soclose) break;
			if(i+1 == (int)path_len_seq.size() || path_len_seq[i+1]+soclose > l)
				ans = max(ans, l);
		}
		cout << ans << "\n";
	}
}