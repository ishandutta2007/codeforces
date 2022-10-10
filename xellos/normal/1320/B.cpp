#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > Gi(N), G(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		Gi[--v].push_back(--u);
		G[u].push_back(v);
	}
	int K;
	cin >> K;
	vector<int> P(K);
	for(int i = 0; i < K; i++) {cin >> P[i]; P[i]--;}
	vector<int> dist(N, N+1);
	queue<int> q;
	q.push(P[K-1]);
	dist[P[K-1]] = 0;
	while(!q.empty()) {
		for(auto v : Gi[q.front()]) if(dist[v] == N+1) {
			dist[v] = dist[q.front()]+1;
			q.push(v);
		}
		q.pop();
	}
	int min_reb = 0, max_reb = 0;
	for(int i = 0; i < K-1; i++) {
		if(dist[P[i]] != dist[P[i+1]]+1) {
			min_reb++, max_reb++;
			continue;
		}
		bool other_path = 0;
		for(auto v : G[P[i]]) if(dist[v]+1 == dist[P[i]] && v != P[i+1]) {
			other_path = 1;
			break;
		}
		if(other_path) max_reb++;
	}
	cout << min_reb << " " << max_reb << "\n";
}