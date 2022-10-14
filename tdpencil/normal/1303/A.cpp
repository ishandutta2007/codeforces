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
template<class T> void print(set<T> &a) {
	for(auto &e: a)
		cout << e << " ";
	cout << "\n";
}
template<class T> void print(queue<T> &p) {
	while(p.size()) {
		cout << p.front() << " ";
		p.pop();
	}
	cout << "\n";
}
template<class T> void print(stack<T> &s) {
	while(s.size()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}
template<class T, int _SZ> void print(array<T, _SZ> a) {
	for(auto &n: a)
		cout << n << " ";
	cout << "\n";
}
template<class T> void readar(T a[], int n) {
	for(int i =0; i < n; i++)
		cin >> a[i];
}
ll n, k, m;
ll a[1000000];
ll b[1000000];
ll c[1000000];
string s,t;
void solve() {
	int f=-1,sec=-1;
	
	int ans=0;
	bool picked=false;
	
	cin >> s;
	
	for(int i=0; i < int(s.size()); i++) {
		if(s[i] == '1' && !picked) {
			picked=true;
			f=i;
		} else if(s[i] == '1') {
			sec=i;
		}
	}
	
	if(f == -1 || sec == -1) {
		cout << 0 << "\n";
		return;
	}
	
	// int ans=0;
	for(int i=f; i <= sec; i++) if(s[i] == '0') ans++;
	
	cout << ans << "\n";
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