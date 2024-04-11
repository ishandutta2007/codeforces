#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define sumvt(x) accumulate(all(x), 0ll)
#define sumat(v, n) accumulate(v, v+n, 0ll)
#define vt vector
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
void read(vt<array<t,2>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1];
}
template<class t>
void read(vt<array<t,3>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1] >> b[2];
}
template<class t>
void read(vt<array<t,4>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1] >> b[2] >> b[3];
}

template<class t> void print(t &a) {
	cout << a << "\n";
}
template<class T> void print(vt<T> &a) {
	for(auto &e: a)
		cout << e << " ";
	cout << "\n";
}
template<class T, class V> void print(vt<pair<T, V>> &a) {
	for(auto &e: a)
		cout << e.first << " " << e.second << "\n";
}
template<class T, int SZ_> void print(vt<array<T, SZ_>> &a) {
	for(auto &e: a) {
		for(auto &b: e) cout << b << " ";
		cout << "\n";
	}
}
double query(int l, int r, vt<int> &p) {
	if(l == 0) return (double) p[r];
	else return (double)p[r] - p[l-1];
}
void solve() {
	double ans=0;
	int n, k;
	cin >> n >> k;
	vt<int> a(n);
	read(a);
	vt<int> pref(n);
	pref = a;
	for(int i=1;i<n;i++) pref[i] += pref[i-1];
	for(int i=0; i < n; i++) {
		for(int j=i+k-1; j<n; j++) {
			double avg=query(i, j, pref) / (j-i+1);
			ans = max(ans, avg);
		}
	}

	cout << setprecision(15) << ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t= 1;
	while(t--) {
		solve();
	}
}