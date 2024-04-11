#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A(K);
	for(int i = 0; i < K; i++) {
		cin >> A[i];
		A[i]--;
	}
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> dist[2] = {vector<int>(N, -1), vector<int>(N, -1)};
	queue<int> q;
	dist[0][0] = 0;
	q.push(0);
	for(int i = 0; i < N; i++) {
		for(auto v : G[q.front()]) if(dist[0][v] == -1) {
			dist[0][v] = dist[0][q.front()]+1;
			q.push(v);
		}
		q.pop();
	}
	dist[1][N-1] = 0;
	q.push(N-1);
	for(int i = 0; i < N; i++) {
		for(auto v : G[q.front()]) if(dist[1][v] == -1) {
			dist[1][v] = dist[1][q.front()]+1;
			q.push(v);
		}
		q.pop();
	}
	vector< pair<int, int> > V(K);
	for(int i = 0; i < K; i++) V[i] = {dist[0][A[i]]-dist[1][A[i]], A[i]};
	sort(begin(V), end(V));
	int L0 = dist[0][N-1];
	for(int i = 0; i < N; i++) L0 = min(L0, dist[0][i]+dist[1][i]);
	int max_prev_dist = dist[0][V[0].second];
	int ans = -1;
	for(int i = 1; i < K; i++) {
		ans = max(ans, dist[1][V[i].second]+max_prev_dist+1);
		max_prev_dist = max(max_prev_dist, dist[0][V[i].second]);
	}
	ans = min(ans, L0);
	cout << ans << "\n";
}