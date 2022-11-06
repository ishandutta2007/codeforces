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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("unroll-loops")    
#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define len(a) int(a.size())
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

const int N = 2e5 + 5;

struct box {	
	int a[N];

	void add(int i) {
		while (i < N) {
			a[i]++;
			i |= (i + 1);
		}
	}

	int get(int i) {
		int ans = 0;
		while (i >= 0) {
			ans += a[i];
			i &= (i + 1);
			--i;
		}
		return ans;
	}
} box;

int n;
long long cnt = 0;
bool used[N];
vector<int> Lcoor;
vector<point> p;
long long ans = 0;



int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
	cin >> n;
	p.resize(n);
	cin >> p;
	sort(p.begin(), p.end(), [](point a, point b) {
		if (a.y != b.y) {
			return a.y > b.y;
		}
		return a.x < b.x;
	});
	for (auto i : p) Lcoor.pb(i.x);
	sort(Lcoor.begin(), Lcoor.end());
	for (auto &i : p) i.x = lower_bound(Lcoor.begin(), Lcoor.end(), i.x) - Lcoor.begin();
	int L = 0;
	while (L < n) {
		int R = L;
		while (R < n && p[L].y == p[R].y) {
			if (!used[p[R].x]) {
				++cnt;
				used[p[R].x] = true;
				box.add(p[R].x);
			}
			++R;
		}
		// cout << L << ' ' << R << endl;
		vector<long long> bad;
		int lst = 0;
		for (int i = L; i < R; ++i) {
			int t = box.get(p[i].x - 1);
			bad.pb(t - lst);
			lst = t + 1;
		}
		bad.pb(cnt - lst);
		long long cur = cnt * (cnt + 1) / 2;
		// cout << cnt << ":" << bad << endl;
		for (auto i : bad) {
			cur -= i * (i + 1) / 2;
		}
		ans += cur;
		L = R;
	}
	cout << ans << '\n';
}