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
	int x1, y2;
	cin >> x1 >> y2;

	string s;
	cin >> s;

	pair<int, int> cur(0, 0);
	array<int, 4> dir;
	dir[0]=0;
	dir[1]=0;
	dir[2]=0;
	dir[3]=0;
	for(int i=0; i < s.size() ;i++) {
		if(s[i] == 'L') dir[0]++;
		if(s[i] == 'R') dir[1]++;
		if(s[i] == 'U') dir[2]++;
		if(s[i] == 'D') dir[3]++;
	}
	int y1=y2;
	if(x1 <= 0) {
		if(y1 < 0) {
			if(dir[0] >= abs(x1) && dir[3] >= abs(y2)) {
				cout << "YES\n";
				return;
			}
		} else {
			if(dir[0] >= abs(x1) && dir[2] >= abs(y2)) {
				cout << "YES\n";
				return;
			}
		}
	}

	if(x1 >= 0) {
		if(y1 < 0) {
			if(dir[1] >= abs(x1) && dir[3] >= abs(y2)) {
				cout << "YES\n";
				return;
			}
		} else {
			if(dir[1] >= abs(x1) && dir[2] >= abs(y2)) {
				cout << "YES\n";
				return;
			}
		}
	}

	cout << "NO\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
}