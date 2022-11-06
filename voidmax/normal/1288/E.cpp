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

const int N = 5e5 + 5;

struct node {
	int y;
	int p, L, R;
	int s;
} a[N];

int get_place(int i) {
	int ans = a[a[i].L].s;
	while (a[i].p != 0) {
		if (a[a[i].p].R == i) {
			ans += a[a[a[i].p].L].s + 1;
		}
		i = a[i].p;
	}
	return ans + 1;
}

int merge(int L, int R) {
	if (L == 0) return R;
	if (R == 0) return L; 
	if (a[L].y < a[R].y) {
		a[L].R = merge(a[L].R, R);
		a[a[L].R].p = L;
		a[L].s = 1 + a[a[L].L].s + a[a[L].R].s;
		return L;
	} else {
		a[R].L = merge(L, a[R].L);
		a[a[R].L].p = R;
		a[R].s = 1 + a[a[R].L].s + a[a[R].R].s;
		return R;
	}
}

void split(int A, int x, int& L, int& R) {
	if (A == 0) {
		L = R = 0;
		return;
	}
	if (a[a[A].L].s >= x) {
		split(a[A].L, x, L, R);
		a[A].L = R;
		a[R].p = A;
		R = A;
	} else {
		split(a[A].R, x - a[a[A].L].s - 1, L, R);
		a[A].R = L;
		a[L].p = A;
		L = A;
	}
	a[A].s = 1 + a[a[A].L].s + a[a[A].R].s;
	a[L].p = 0, a[R].p = 0;
}

void print(int i, bool res = false) {
	if (!i) return;
	if (res) cout << "(";
	else     cout << "[";
	print(a[i].L, true);
	cout << i;
	print(a[i].R);
	if (res) cout << ")";
	else     cout << "]";
}

int root;
int n, m;
int ans[2][N];

void del(int i) {
	int place = get_place(i);
	chkmax(ans[1][i], place);
	int L, M, R;
	split(root, place - 1, L, R);
	split(R, 1, M, R);
	// cout << a[M].s << ' ' << place << ' '  << M << ' ' << i << endl;
	root = merge(M, merge(L, R));
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    for (int i = 0; i < N; ++i) {
    	a[i].y = i;
    }
    random_shuffle(a, a + N);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
    	ans[0][i] = i;
    	ans[1][i] = i;
    	a[i].s = 1;
    	root = merge(root, i);
    }
    for (int i = 1; i <= m; ++i) {
    	int v;
    	cin >> v;
    	ans[0][v] = 1;
    	del(v);
    	// print(root); cout << endl;
    	// for (int i = 1; i <= n; ++i) {
    	// 	cout << get_place(i) << ' ';
    	// }
    	// cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
    	chkmax(ans[1][i], get_place(i));
    }
    for (int i = 1; i <= n; ++i) {
    	cout << ans[0][i] << ' ' << ans[1][i] << '\n';
    }
}