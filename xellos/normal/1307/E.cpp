#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using cat = long long;

cat mod = 1000000007;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> S(N);
	for(int i = 0; i < N; i++) cin >> S[i];
	vector<int> r_pair(N, N), l_pair(N, -1), is_l(N, 0), is_r(N, 0);
	vector<int> C(N+1, 0);
	for(int i = 0; i < M; i++) {
		int f, h;
		cin >> f >> h;
		int l = 0, r = N-1, cnt = h;
		while(l < N) {
			cnt -= (S[l] == f);
			if(cnt == 0) break;
			l++;
		}
		if(l == N) continue;
		C[f]++;
		cnt = h;
		while(r >= 0) {
			cnt -= (S[r] == f);
			if(cnt == 0) break;
			r--;
		}
		if(l < r) r_pair[l] = r, l_pair[r] = l;
		is_l[l] = is_r[r] = 1;
	}
	cat ans_max = 0, ans_cnt = 1;
	for(int i = 0; i <= N; i++) if(C[i]) ans_max++, ans_cnt = ans_cnt * C[i] % mod;
	for(int i = 0; i < N; i++) if(is_l[i]) {
		vector<int> X(N+1, 0), Y(N+1, 0), Z(N+1, 0);
		for(int j = 0; j < i; j++) if(S[i] != S[j]) {
			if(is_l[j] && r_pair[j] != N && r_pair[j] > i) Z[S[j]]++;
			else if(is_l[j]) X[S[j]]++;
		}
		for(int j = i+1; j < N; j++) if(S[i] != S[j])
			if(is_r[j] && (l_pair[j] == -1 || l_pair[j] > i)) Y[S[j]]++;
		cat cur_max = 1, cur_cnt = 1, y = 0;
		for(int j = i+1; j < N; j++) if(S[i] == S[j] && is_r[j] && l_pair[j] != i) y++;
		if(y != 0) cur_cnt = y, cur_max++;
		for(int j = 0; j <= N; j++) if(X[j] || Y[j] || Z[j]) {
			int max_add = 1, cnt_pr = (X[j]+Z[j])*(Y[j]+Z[j])-Z[j];
			if(cnt_pr) max_add++;
			else cnt_pr = X[j]+Y[j]+2*Z[j];
			cur_max += max_add;
			cur_cnt = cur_cnt * cnt_pr % mod;
		}
		// cout << i << " " << cur_max << " " << cur_cnt << "\n";
		if(ans_max < cur_max) ans_max = cur_max, ans_cnt = 0;
		if(ans_max == cur_max) {
			ans_cnt += cur_cnt;
			if(ans_cnt >= mod) ans_cnt -= mod;
		}
	}
	cout << ans_max << " " << ans_cnt << "\n";
}