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

int mex(vector<int> a) {
	sort(all(a));
	a.resize(unique(all(a))-a.begin());
	a.push_back(1e9);
	for(int i=0; ; ++i)
		if(i^a[i])
			return i;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	FOR(t) {
		int n;
		cin >> n;
		vector<int> a(n);
		FOR(n)
			cin >> a[i];
		vector<int> ans;
		while(1) {
			bool ok=1;
			FOR(n-1)
				ok&=a[i]<=a[i+1];
			if(ok)
				break;
			int b=mex(a), j=b;
			if(b==n) {
				int k=0;
				while(a[k]==k)
					++k;
				j=find(all(a), k)-a.begin();
			}
			a[j]=b;
			ans.push_back(j);
		}
		cout << ans.size() << "\n";
		for(int a : ans)
			cout << a+1 << " ";
		cout << "\n";
	}
}