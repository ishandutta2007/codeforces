#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ar array

int n, a[200000], b[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<n; ++i)
		cin >> b[i];
	ll ans=0;
	oset<ar<int, 2>> s;
	for(int i=0; i<n; ++i) {
		ans+=s.order_of_key({a[i]-b[i], 0});
		s.insert({b[i]-a[i], i});
	}
	cout << ans;
}