#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define sumvt(x) accumulate(all(x), 0ll)
#define sumat(v, n) accumulate(v, v+n, 0ll)
#define vt vector
#define ar array
template<class t>
void read(t a) {
	cin >> a;
}
template<class t>
void read(vt<t> &a) {
	for(auto &b: a)
		cin >> b;
}
template<class t>
void read(vt<pair<t,t>> &a) {
	for(auto &b: a)
		cin >> b.first >> b.second;
}
template<class t>
void read(vt<ar<t,2>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1];
}
template<class t>
void read(vt<ar<t,3>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1] >> b[2];
}
template<class t>
void read(vt<ar<t,4>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1] >> b[2] >> b[3];
}

template<class t>
void print(t a) {
	cout << a << "\n";
}

// q is horizontal
// p is vertical
ll ft[200000];
int n;
void upd(int idx, int val) {
	for(++idx; idx <= n; idx += idx & -idx)
		ft[idx] += val;
}
int sum(int p) {
	int s=0;
	for(++p; p > 0; p -= p & -p)
		s += ft[p];
	return s;
}
int qry(int l, int r) {
	if(l == 0) return sum(r);
	return sum(r) - sum(l-1);
}
void solve() {
	cin >> n;

	int ans=0;
	vt<int> stored(n);
	for(int i=0; i < n; i++) cin >> stored[i];
	vt<int> a(n);
	for(int i=0; i < n; i++) a[i] = stored[i];
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for(int i=0; i < n; ++i)
		upd(i, a[i]);
	int bg=qry(0, n-1);
	cerr << bg << "\n";
	++ans;
	for(int i=0; i < n-1; ++i) ans += stored[i] != stored[i+1];
	cout << ans << "\n";


}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	solve();
}