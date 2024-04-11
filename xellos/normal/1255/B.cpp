#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector< pair<int, int> > A(N);
		for(int i = 0; i < N; i++) {
			cin >> A[i].first;
			A[i].second = i;
		}
		if(M < N || N == 2) {
			cout << "-1\n";
			continue;
		}
		for(int i = 1; i < N; i++) if(A[i] < A[0]) swap(A[i], A[0]);
		for(int i = 2; i < N; i++) if(A[i] < A[1]) swap(A[i], A[1]);
		int ans = 0;
		for(int i = 1; i < N; i++) ans += 2 * A[i].first;
		vector< pair<int, int> > E;
		int C = M-N+1, l = 1;
		while(C > 0 && l < N) {
			int L = (C == 1 || l >= N-3) ? N-l : 2;
			E.push_back({A[0].second, A[l].second});
			for(int j = l+1; j < l+L; j++) E.push_back({A[j-1].second, A[j].second});
			E.push_back({A[l+L-1].second, A[0].second});
			l += L, C--;
			ans += 2 * A[0].first;
		}
		while((int)E.size() < M) {
			ans += A[0].first + A[1].first;
			E.push_back({A[0].second, A[1].second});
		}
		cout << ans << "\n";
		for(int i = 0; i < M; i++) cout << E[i].first+1 << " " << E[i].second+1 << "\n";
	}
}