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

const int mxN=1e3;
int n, a[mxN], p[mxN];
ar<int, 2> b[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(n) {
		cin >> a[i];
		b[i]={a[i], i};
	}
	sort(b, b+n);
	FOR(n) {
		p[i]=b[i][1];
		a[b[i][1]]=i;
	}
	vector<ar<int, 2>> ans;
	FOR(i, n-1, -1, -1) {
		FOR(j, i, n-1) {
			if(p[j]>p[j+1]) {
				swap(p[j], p[j+1]);
				ans.push_back({p[j], p[j+1]});
			}
		}
	}
	cout << ans.size() << "\n";
	for(ar<int, 2> a : ans) {
		//if(a[0]>a[1])
			//swap(a[0], a[1]);
		cout << a[0]+1 << " " << a[1]+1 << "\n";
	}
}