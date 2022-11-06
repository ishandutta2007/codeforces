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

const int N = 2e3 + 5;

int n;
int d[N], p[N], id[N];
bool used[N];
vector<int> cool;
vector<pair<int, int>> edges;

long long sum, m;
queue<int> que;
vector<int> edge[N];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> d[i];
    	id[i] = i;
    	if (d[i] & 1) cool.pb(i);
    	sum += d[i];
    }
    if (sum & 1) {
    	cout << -1 << '\n';
    	return 0;
    }
    sum >>= 1;
    m = sum - (n - 1);
    if (m < 0) {
    	cout << -1 << '\n';
    	return 0;
    }
    sort(cool.begin(), cool.end(), [](int i, int j) {
    	return d[i] > d[j];
    });
    memset(p, -1, sizeof(p));
    for (int i = 0; i < int(cool.size()) - i - 1; ++i) {
    	if (d[cool[i]] == 1) break;
    	p[cool[i]] = cool[cool.size() - i - 1];
    	p[p[cool[i]]] = cool[i];
    	edges.emplace_back(p[cool[i]], cool[i]);
    	--d[p[cool[i]]], --d[cool[i]];
    }
    sort(id, id + n, [](int i, int j) {
    	return d[i] > d[j];
    });
    for (int i = 0; i < n; ++i) {
    	if (used[id[i]]) continue; 
    	while (que.size() && d[que.front()] == 0) que.pop();
    	used[id[i]] = true;
    	int res = -1;
    	if (que.size()) res = que.front();
    	que.push(id[i]);
    	if (p[id[i]] != -1) {
    		que.push(p[id[i]]);
    		used[p[id[i]]] = true;
    	}
    	if (i == 0) continue;
    	if (res == -1) {
    		if (d[id[i]] != 2) {
    			cout << -1 << '\n';
    			return 0;
    		}
    		auto [a, b] = edges.back();
    		edges.pop_back();
    		edges.emplace_back(a, id[i]);
    		edges.emplace_back(b, id[i]);
    		d[id[i]] = 0;
    		continue;
    	}
    	edges.emplace_back(res, id[i]);
    	--d[res], --d[id[i]];
    	if (m) {
    		if (edge[res].size() && d[edge[res].back()] && d[id[i]]) {
    			edges.emplace_back(edge[res].back(), id[i]);
    			--d[id[i]], --d[edge[res].back()];
    			edge[res].pop_back();
    			--m;
    			continue;
    		} 
    	}
    	edge[res].push_back(id[i]);
    }
    if (edges.size() != sum) {
    	cout << -1 << '\n';
    	return 0;
    }
    cout << edges.size() << '\n';
    for (auto [a, b] : edges) {
    	cout << 2 << ' ' << a + 1 << ' ' << b + 1 << '\n';
    }
}