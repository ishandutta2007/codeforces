// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")    
#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout)
using namespace std;
		
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
		
typedef long long base; 
typedef pair<int, int> point;      
typedef complex<double> comp;

const int N = 5e5 + 5;

int n;
bool odd;
long long sum = 0;

vector<int> a;
vector<int> cnt;

bool chg = false;

int check(int v) {
	int it = lower_bound(a.rbegin(), a.rend(), v) - a.rbegin();
	it = n - 1 - it;
	a.insert(it + a.begin(), v);
	//cout << a << endl;
	long long sumL = 0, cntL = 0;
	cnt.clear();
	cnt.resize(n + 1);
	vector<long long> pref;
	pref.pb(0);
	for (int i = 0; i < n; ++i) {
		pref.pb(pref.back() + a[i]);
	}
	for (long long k = n - 1; k >= 1; --k) {
		if (a[k] < k) {
			++cnt[a[k]];
			sumL += a[k];
		} else {
			++cntL;
		}
		cntL += cnt[k];
		sumL -= 1LL * k * cnt[k];
		//cout << k * (k - 1) << ' ' << sumL << ' ' << cntL * k << endl;
		long long cur_sum = k * (k - 1) + sumL + cntL * k; 
		//cout << a << endl;
		//cout << pref[k] << ' ' << cur_sum << endl;
		if (pref[k] > cur_sum) {
			a.erase(it + a.begin());
			if (k <= it ^ chg) {
				return 0;
			}
			return 2;
		}
	}
	a.erase(it + a.begin());
	//cout << "can" << endl;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read("input")
	cin >> n;
	a.resize(n);
	cin >> a;
	++n;
	cnt.resize(n + 1);
	sort(a.rbegin(), a.rend());
	//cout << a << endl;
	for (auto i : a) sum += i;
	odd = sum & 1;
	vector<int> elems;
	for (int i = odd; i < n; i += 2) {
		elems.pb(i);
	}
	// for (auto i : elems) {
	// 	if (check(i))
	// 	cout << i << endl;
	// }
	// return 0;
	int ansL = 0, ansR = (int)elems.size() - 1;
	//cout << elems << endl;
	int v1 = check(elems[0]);
	int v2 = check(elems.back());
	int L = -1, R = elems.size();
	if (v1 == 2 || v2 == 0) {
		chg = true;
	}
	while (R - L > 1) {
		int M = (L + R) >> 1;
		if (check(elems[M]) == 0) {
			L = M;
		} else {
			R = M;
		}
	}
	ansL = R;
	L = -1, R = elems.size();
	while (R - L > 1) {
		int M = (L + R) >> 1;
		if (check(elems[M]) == 2) {
			R = M;
		} else {
			L = M;
		}
	}
	ansR = L;
	//cout << ansL << ' ' << ansR << endl;
	if (ansL <= ansR) {
		for (int i = ansL; i <= ansR; ++i) {
			cout << elems[i] << ' ';
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}