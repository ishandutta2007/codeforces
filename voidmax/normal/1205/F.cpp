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

const int N = 101;
const int T = 5;

int n;
bool used[N * N];
pair<point, point> how[N * N];

vector<int> can[N];
vector<pair<point, point>> way[N]; 
vector<int> answer[T][T * T];

void init_small() {	
	for (int i = 1; i < T; ++i) {
		vector<int> res;
		for (int j = 1; j <= i; ++j) res.pb(j);
		do {
			int cnt = 0;
			for (int L = 0; L < i; ++L) {
				for (int R = L + 1; R <= i; ++R) {
					int minx = 1e9, maxx = -1e9;
					for (int M = L; M < R; ++M) {
						chkmax(maxx, res[M]);
						chkmin(minx, res[M]);
					}
					if (maxx - minx + 1 == R - L) {
						++cnt;
					}
				}
			}
			answer[i][cnt] = res;
		} while (next_permutation(res.begin(), res.end()));
		for (int j = 0; j <= (i + 1) * i / 2; ++j) {
			if (answer[i][j].size()) {
				can[i].pb(j);
			}
		}
	}
}


void init_big() {
	for (int a = T; a < N; ++a) {
		memset(used, 0, sizeof(used));
		for (int b = 2; b <= a + 1 - b; ++b) {
			int c = a + 1 - b;
			for (int wb : can[b]) {
				for (int wc : can[c]) {
					used[wb + wc - 1] = true;
					how[wb + wc - 1] = {{b, wb}, {c, wc}};
				}
			}
		}
		can[a].pb(a + 1);
		way[a].pb({{-1, -1}, {-1, -1}});
		for (int i = a + 2; i < a * (a + 1) / 2; ++i) {
			if (used[i]) {
				can[a].pb(i);
				way[a].pb(how[i]);
			}
		}
		can[a].pb(a * (a + 1) / 2);
		way[a].pb({{-1, -1}, {-1, -1}});
	}
}

void get(int a, int b, vector<int> &ans) {
	if (a < T) {
		ans = answer[a][b];
		return;
	}
	int it = lower_bound(can[a].begin(), can[a].end(), b) - can[a].begin();
	if (can[a][it] != b) return;
	if (b == a * (a + 1) / 2) {
		ans.resize(a);
		for (int i = 0; i < a; ++i) {
			ans[i] = i + 1;
		}
		return;
	} 
	if (b == a + 1) {
		for (int i = 2; i <= a; i += 2) {
			ans.pb(i);
		}
		ans.pb(1);
		if (a & 1) ans.pb(a);
		for (int i = 3; i < a; i += 2) {
			ans.pb(i);
		}
		return;
	}
	vector<int> L, R;
	get(way[a][it].x.x, way[a][it].x.y, L);
	get(way[a][it].y.x, way[a][it].y.y, R);
	ans.resize(a);
	for (int i = 0; i < L.size(); ++i) ans[i] = L[i] + R[0] - 1;
	for (int i = 1; i < R.size(); ++i) {
		ans[L.size() + i - 1] = R[i] + int(R[i] > R[0]) * (L.size() - 1);
	}
	if ((ans[0] < ans[L.size() - 1]) == (ans[L.size() - 1] < ans[L.size()])) {
		reverse(ans.begin(), ans.begin() + L.size());
	}
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    init_small();
    init_big();
    int t;
    cin >> t;
    while (t--) {
    	vector<int> ans;
    	int a, b;
    	cin >> a >> b;
    	get(a, b, ans);
    	if (ans.size() == 0) {
    		cout << "NO\n";
    	} else {
    		cout << "YES\n";
    		cout << ans << '\n';
    	}
    }
}