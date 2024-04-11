#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string S[2];
	cin >> S[0] >> S[1];
	int N[2] = {S[0].length(), S[1].length()};

	vector< pair<int, int> > first_occ(N[0]+N[1], {N[0], N[1]});
	first_occ[N[0]] = {0, 0};
	for(int i = 0; i < N[1]-1; i++) {
		int x = first_occ[N[0]+i].first, y = first_occ[N[0]+i].second;
		while(x < N[0] && y < N[1] && S[0][x] == S[1][y]) x++, y++;
		if(x == N[0] || y >= N[1]-1) break;
		first_occ[N[0]+i+1] = {x, y+1};
	}
	for(int i = 0; i < N[0]-1; i++) {
		int x = first_occ[N[0]-i].first, y = first_occ[N[0]-i].second;
		while(x < N[0] && y < N[1] && S[0][x] == S[1][y]) x++, y++;
		if(x >= N[0]-1 || y == N[1]) break;
		first_occ[N[0]-i-1] = {x+1, y};
	}

	vector< pair<int, int> > id_range(N[0], {N[0], -1});
	for(int d = -(N[0]-1); d <= N[1]-1; d++) if(first_occ[d+N[0]].first < N[0]) {
		int x = first_occ[d+N[0]].first, y = first_occ[d+N[0]].second;
		id_range[x].first = min(id_range[x].first, y);
		id_range[x].second = max(id_range[x].second, y);
		int a = min(N[0]-1-x, N[1]-1-y);
		id_range[x+a].first = min(id_range[x+a].first, y+a);
		id_range[x+a].second = max(id_range[x+a].second, y+a);
	}
	for(int i = 1; i < N[0]; i++) {
		id_range[i].first = min(id_range[i].first, id_range[i-1].first+1);
		id_range[i].second = max(id_range[i].second, id_range[i-1].second+1);
		id_range[i].second = min(id_range[i].second, N[1]-1);
	}

	long long ans = 0;
	for(int d = -(N[0]-1); d <= N[1]-1; d++) if(first_occ[d+N[0]].first < N[0])
		ans += min(N[0]-first_occ[d+N[0]].first, N[1]-first_occ[d+N[0]].second);

	string C = "RGB";
	for(int a = 0; a < 3; a++) for(int b = 0; b < 3; b++) if(a != b) for(int k = 0; k < 4; k++) {
		// k: parity of i, j
		vector<char> R[2] = {vector<char>(N[0], 0), vector<char>(N[1], 0)};
		for(int i = k/2; i < N[0]; i += 2) if(S[0][i] == C[a]) R[0][i] = 1;
		for(int i = 1-k/2; i < N[0]; i += 2) if(S[0][i] == C[b]) R[0][i] = 1;
		for(int i = k%2; i < N[1]; i += 2) if(S[1][i] == C[b]) R[1][i] = 1;
		for(int i = 1-k%2; i < N[1]; i += 2) if(S[1][i] == C[a]) R[1][i] = 1;
		for(int i = N[0]-1; i > 0; i--) if(R[0][i-1] == 0) R[0][i] = 0;
		for(int i = N[1]-1; i > 0; i--) if(R[1][i-1] == 0) R[1][i] = 0;
		for(int i = 1-k/2; i < N[0]; i += 2) R[0][i] = 0;
		for(int i = 1-k%2; i < N[1]; i += 2) R[1][i] = 0;

		vector<int> cnt(N[1]+1, 0);
		for(int i = 0; i < N[1]; i++) cnt[i+1] = cnt[i] + R[1][i];

		for(int i = 2-k/2; i < N[0]; i += 2) if(R[0][i] && max(id_range[i].first, 2-k%2) <= id_range[i].second)
			ans -= cnt[id_range[i].second+1] - cnt[max(id_range[i].first, 2-k%2)];
	}

	cout << ans << "\n";
}