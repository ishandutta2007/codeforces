#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ar array

const int mxN=2e5;
int n, q, a[mxN];
oset<int> ft[mxN+1];

void upd(int i, int x, bool a) {
	for(++i; i<=n; i+=i&-i) {
		if(a)
			ft[i].insert(x);
		else
			ft[i].erase(x);
	}
}

int qry(int i, int l, int r) {
	int ans=0;
	for(; i; i-=i&-i) {
		ans+=(ft[i].order_of_key(r))-(ft[i].order_of_key(l));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	iota(a, a+n, 0);
	for(int i=0; i<n; ++i)
		upd(i, i, 1);
	ll ans=0;
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		if(l^r) {
			if(l>r)
				swap(l, r);
			//if(a[l]<a[r])
				ans+=2*(qry(r, a[l], a[r])-qry(l+1, a[l], a[r]));
			//else
				//ans-=2*();
			if(a[l]<a[r])
				++ans;
			else
				--ans;
		}
		cout << ans << "\n";
		upd(l, a[l], 0);
		upd(r, a[r], 0);
		swap(a[l], a[r]);
		upd(l, a[l], 1);
		upd(r, a[r], 1);
	}
}