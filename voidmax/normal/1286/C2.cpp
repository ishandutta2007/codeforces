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

const int N = 1e6 + 5;

int n;

int cnt[200][26];

string res = "aba";

string get(int L, int R) {
	memset(cnt, 0, sizeof(cnt));
	cout << "? " << L << ' ' << R << endl;
	for (int i = L; i <= R; ++i) {
		for (int j = i; j <= R; ++j) {
			string s;
			cin >> s;
			// s = string(res.begin() + i - 1, res.begin() + j);
			for (char c : s) {
    			cnt[s.size() + 1][c - 'a']++;
    		}
		}	
	}
	string ans;
	// int s = R - L + 1;
	// for (int i = 1; i <= s; ++i) {
	// 	vector<int> res(s);
	// 	for (int j = 0; j + i <= s; ++j) {
	// 		for (int q = 0; q < i; ++q) {
	// 			res[j + q]++;
	// 		}
	// 	}
	// 	// cout << res << '\n';
	// }
	for (int i = R - L + 1; i >= 0; --i) {
    	vector<char> cool;
    	for (int c = 0; c < 26; ++c) {
    		if (cnt[i + 1][c] >= cnt[i][c] + cnt[0][c]) {
    			for (int j = cnt[i][c] + cnt[0][c]; j < cnt[i + 1][c]; ++j) {
    				cool.pb(c + 'a');
    			}
    		}
    	}
    	for (auto c : cool) ++cnt[0][c - 'a'];
    	// cout << cool << endl;
    	for (char c : cool) {
    		ans += c;
    		reverse(ans.begin(), ans.end());
    	}
    }
    return ans;
}

string solve(int Lx, int Rx) {
	int n = Rx - Lx + 1;
	string ans1 = get(Lx, Rx);
   	if (Lx == Rx) {
   		return ans1;
   	}
   	string ans2 = get(Lx + 1, Rx);
   	string ans(n, '-');
   	// cout << ans1 << ' ' << ans2 << endl;
   	int L = 0, R = n - 1;
   	int who = 0;
   	while (L <= R) {
   		// cout << ans1 << ' ' << ans2 << ' ' << ans << endl;
   		vector<int> cnt(26);
   		for (char c : ans1) {
   			++cnt[c - 'a'];
   		}
   		for (char c : ans2) {
   			--cnt[c - 'a'];
   		}
   		char cool = '-';
   		for (int i = 0; i < 26; ++i) {
   			if (cnt[i]) {
   				cool = i + 'a';
   				break;
   			}
   		}
   		assert(cool != '-');
   		if ((ans1[0] != cool) ^ who) {
   			reverse(ans1.begin(), ans1.end());
   		}
   		ans[L] = ans1[0];
   		ans[R] = ans1.back();
   		if (L == R) break;
   		ans1.pop_back();
   		ans1.erase(ans1.begin());
   		if (who == 0) {
   			++L;
   		} else {
   			--R;
   		}
   		who = 1 - who;
   		swap(ans1, ans2);
   	}
   	return ans;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    string ans = get(1, n);
    // cout << ans << endl;
    if (n == 1) {
    	cout << "! " << ans << endl;
    	return 0;
    }
    // cin >> res;
    // n = res.size();
   	int M = n >> 1;
   	string halfL = solve(1, M);
   	// cout << halfL << endl;
   	int L = 0, R = n - 1;
   	for (int i = 0; i < halfL.size(); ++i) {
   		if (ans[i] != halfL[i]) {
   			swap(ans[L], ans[R]);
   		}
   		++L, --R;
   	}
   	cout << "! " << ans << endl;
}