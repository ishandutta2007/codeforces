#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int counts[1000001];
ll calc[1000002];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	while(T--) {
		// TODO: Run length encoding
		// fen tree
		int N, K;
		cin >> N >> K;
		vector<int> A(N);
		for(int &i : A)
			cin >> i;
		vector<ll> ans(K);
		int left = 0, right = -1;

		ll cur = 0;
		
		for(ll i = 0; i < (int)1000002; i++)
			calc[i] = i * i;
		vector<pair<pair<int, int>, int>> queries(K);

		for(int i = 0; i < K; i++) {
			cin >> queries[i].first.first >> queries[i].first.second;
			--queries[i].first.first, --queries[i].first.second;
			queries[i].second = i;
		}

		const int BLOCK = 512;
		sort(queries.begin(), queries.end(), [&](const auto a, const auto b) {
			return a.first.first / BLOCK == b.first.first / BLOCK ? a.first.second < b.first.second : a.first.first / BLOCK < b.first.first / BLOCK;
		});
		// for(auto e : queries) {
			// cout << e.first.first << " " << e.first.second << " " << e.second << "\n";
		// }
		
		auto move = [&](int originalLeft, int originalRight, int newLeft, int newRight) {
			while(originalLeft < newLeft) {
				--counts[A[originalLeft]];
				cur -= A[originalLeft] * (calc[counts[A[originalLeft]] + 1] - calc[counts[A[originalLeft]]]);
				++originalLeft;
			}
 
			while(newLeft < originalLeft) {
				--originalLeft;
				cur += A[originalLeft] * (calc[counts[A[originalLeft]] + 1] - calc[counts[A[originalLeft]]]);
				++counts[A[originalLeft]];
			}
 
			while(originalRight < newRight) {
				++originalRight;
				cur += A[originalRight] * (calc[counts[A[originalRight]] + 1] - calc[counts[A[originalRight]]]);
				++counts[A[originalRight]];
			}
 
			while(newRight < originalRight) {
				--counts[A[originalRight]];
				cur -= A[originalRight] * (calc[counts[A[originalRight]] + 1] - calc[counts[A[originalRight]]]);
				--originalRight;
			}
		};

		left = queries[0].first.first, right = queries[0].first.first;
		cur = A[queries[0].first.first];
		++counts[A[queries[0].first.first]];
		for(int i = 0; i < K; i++) {
			int l = queries[i].first.first;
			int r = queries[i].first.second;
			move(left, right, l, r);
			ans[queries[i].second] = cur;
			// cout << counts[1] << " " << counts[2] << "\n";
			left = queries[i].first.first;
			right = queries[i].first.second;
		}

		for(ll &i : ans)
			cout << i << "\n";
	}
}