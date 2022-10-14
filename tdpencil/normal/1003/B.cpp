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
void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	char last;
	if(n >= k) {
		last = '1';
	} else if(k >= n) {
		last = '0';
	}
	int res=n+k-x;
	// 3 3 3
	// 010
	while(x-- > 0) {
		if(last == '1') {
			cout << 0;
			n--;
			last = '0';
		} else {
			cout << 1;
			k--;
			last = '1';
		}
	}
	assert(res == n+k);
	if(last == '0') {
		while(n-- > 0) {
			cout << 0;
		}
		while(k-- > 0) {
			cout << 1;
		}
	} else {
		while(k-- > 0) {
			cout << 1;
		}
		while(n-- > 0) {
			cout << 0;
		}
	}

	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t= 1;
	while(t--) {
		solve();
	}
}