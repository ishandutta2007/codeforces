#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

bool ans[300][300];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	FOR(t) {
		int n, k;
		cin >> n >> k;
		vector<ar<int, 2>> v;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				ans[i][j]=0;
				v.push_back({j, (j+i)%n});
			}
		}
		for(int i=0; i<k; ++i)
			ans[v[i][0]][v[i][1]]=1;
		cout << (k%n?2:0) << "\n";
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j)
				cout << ans[i][j];
			cout << "\n";
		}
	}
}