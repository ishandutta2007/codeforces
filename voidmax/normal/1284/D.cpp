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

const int N = 3e5 + 5;

int q, p;

int next_prime(int v) {
	while (true) {
		bool OK = true;
		for (int j = 2; j * j <= v; ++j) {
			if (v % j == 0) {
				OK = false;
				break;
			}
		}
		if (OK) return v;
		++v;
	}
}

int sum(int a, int b) {
	a += b;
	return a < p ? a : a - p;
}

int mul(long long a, int b) {
	return a * b % p;
}

int powx(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}

void cond(vector<int>& a) {
	sort(a.begin(), a.end());
	vector<int> b;
	b.pb(a[0]);
	for (auto i : a) {
		if (b.back() != i) {
			b.pb(i);
		}
	}
	swap(a, b);
}

int n;

int LR[2][N][2];
long long v[N];
vector<int> Lcoor[2], Rcoor[2];
vector<long long> Lhash[2], Rhash[2];
vector<int> Lpref[2], Rpref[2];

pair<long long, int> get_hash(int t, int i) {
	int it1 = lower_bound(Lcoor[t].begin(), Lcoor[t].end(), LR[t][i][0]) - Lcoor[t].begin();
	int it2 = lower_bound(Rcoor[t].begin(), Rcoor[t].end(), LR[t][i][1]) - Rcoor[t].begin();
	return {Lhash[t][it1] ^ Rhash[t][it2], Lpref[t][it1] + Rpref[t][it2]};
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> LR[0][i][0] >> LR[0][i][1];
    	cin >> LR[1][i][0] >> LR[1][i][1];
    	++LR[0][i][1];
    	++LR[1][i][1];
    	Lcoor[0].pb(LR[0][i][0]);
    	Lcoor[1].pb(LR[1][i][0]);
    	Rcoor[0].pb(LR[0][i][1]);
    	Rcoor[1].pb(LR[1][i][1]);
    }
    for (int t = 0; t < 2; ++t) {
	    Lhash[t].resize(n + 1);
	    Rhash[t].resize(n + 1);
	    Lpref[t].resize(n + 1);
	    Rpref[t].resize(n + 1);
	    cond(Lcoor[t]);
	    cond(Rcoor[t]);
	}
    mt19937 rnd(228); 
    for (int tt = 0; tt < 7; ++tt) {
    	for (int i = 1; i <= n; ++i) {
    		v[i] = rnd() + ((1LL * rnd()) << 32);
    	}
    	for (int i = 0; i <= n; ++i) {
    		Lhash[0][i] = Lhash[1][i] = Rhash[0][i] = Rhash[1][i] = 0;
    		Lpref[0][i] = Lpref[1][i] = Rpref[0][i] = Rpref[1][i] = 0;
    	}
	    for (int t = 0; t < 2; ++t) {
		    for (int i = 1; i <= n; ++i) {
		    	int it = lower_bound(Lcoor[t].begin(), Lcoor[t].end(), LR[t][i][1]) - Lcoor[t].begin();
		    	Lhash[t][it] ^= v[i];
		    	Lpref[t][it]++;
		    	it = upper_bound(Rcoor[t].begin(), Rcoor[t].end(), LR[t][i][0]) - Rcoor[t].begin();
		    	--it;
		    	if (it != -1) {
		    		Rhash[t][it] ^= v[i];
		    		Rpref[t][it]++;
		    	}
		    }
		    for (int i = 1; i <= n; ++i) {
		    	Lhash[t][i] ^= Lhash[t][i - 1];
		    	Lpref[t][i] += Lpref[t][i - 1];
		    }
		    for (int i = n - 1; i >= 0; --i) {
		    	Rhash[t][i] ^= Rhash[t][i + 1];
		    	Rpref[t][i] += Rpref[t][i + 1];
		    }
		}
		for (int i = 1; i <= n; ++i) {
			if (get_hash(0, i) != get_hash(1, i)) {
				cout << "NO\n";
				return 0;
			}
		}
    }
    cout << "YES\n";
}