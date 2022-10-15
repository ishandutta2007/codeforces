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
#define F_OR3(i, b, e) F_OR(i, b, e, (b)<(e)?1:-1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	FOR(t) {
		int n;
		cin >> n;
		vector<ar<int, 2>> a(n);
		int inv=0;
		bool unq=1;
		int ui, uj;
		FOR(n) {
			cin >> a[i][0];
			a[i][1]=i;
			FOR(j, i) {
				inv+=a[j]>a[i];
				if(a[j][0]==a[i][0]) {
					unq=0;
					ui=i, uj=j;
				}
			}
		}
		if(inv&1) {
			if(unq) {
				cout << "-1\n";
				continue;
			}
			swap(a[ui], a[uj]);
		}
		vector<int> ans;
		for(int i=0; i<n-2; ++i) {
			int p=min_element(a.begin()+i, a.end())-a.begin();
			//cout << i << " " << p << endl;
			while(p-i>=2) {
				swap(a[p-1], a[p]);
				swap(a[p-2], a[p-1]);
				ans.push_back(p-2);
				p-=2;
			}
			if(p-i) {
				swap(a[p], a[p+1]);
				swap(a[p-1], a[p]);
				swap(a[p], a[p+1]);
				swap(a[p-1], a[p]);
				ans.push_back(p-1);
				ans.push_back(p-1);
			}
		}
		//FOR(n)
			//cout << a[i] << " ";
		//cout << endl;
		//vector<int> b=a;
		//sort(all(b));
		//assert(a==b);
		cout << sz(ans) << "\n";
		for(int a : ans)
			cout << a+1 << " ";
		cout << "\n";
	}
}