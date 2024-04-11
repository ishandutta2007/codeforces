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
template<class T, int SZ_> void print(vt<ar<T, SZ_>> &a) {
	for(auto &e: a) {
		for(auto &b: e) cout << b << " ";
		cout << "\n";
	}
}
#define sz(x) (int(x.size()))
const int n = 5;
void solve() {
	int bina, binb, binc; cin >> bina >> binb >> binc;
	vt<int> a(n);
	for(int i=0; i < n; i++) 
		cin >> a[i];
	int c=0;
	bina -= a[0];
	
	if(bina < 0) {
		cout << "NO\n";
		return;
	}
	binb -= a[1];
	if(binb < 0) {
		cout << "NO\n";
		return;
	}
	binc -= a[2];
	if(binc < 0) {
		cout << "NO\n";
		return;
	}

	if(binc + bina < a[3] || binc + binb < a[4]) {
		cout << "NO\n";
		return;
	}

	if(a[3] < bina) {
		bina -= a[3];
	} else if(a[3] > bina) {
		a[3] -= bina;
		bina = 0;
		binc -= a[3];
	}

	if(binc + binb < a[4]) {
		cout << "NO\n";
		return;
	}

	if(a[4] < binb) {
		binb -= a[4];
	} else if(a[4] > binb) {
		a[4] -= binb;
		binb = 0;
		binc -= a[4];
	}

	if(bina >= 0 && binb >=0 && binc >=0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;

	while(t--) {
		solve();
	}
}