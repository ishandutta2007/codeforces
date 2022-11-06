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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <iomanip> 
#include <chrono>
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

const int MAXN = 1e6 + 1;

int n;

long long gcd(long long a, long long b){
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long mul(long long a, long long b, long long m){
	if(b == 1)
		return a;
	if(b % 2 == 0){
		long long t = mul(a, b >> 1, m);
		return (t << 1) % m;
	}
	return (mul(a, b - 1, m) + a) % m;
}

long long pows(long long a, long long b, long long m){
	if(b == 0)
		return 1;
	if(b % 2 == 0){
		long long t = pows(a, b / 2, m);
		return mul(t, t, m) % m;
	}
	return (mul(pows(a, b - 1, m), a, m)) % m;
}

const int N = 1.3e6 + 1;
vector<int> prime;
bool cool[N];

bool ferma(long long x){
	if(x == 2)
		return true;
	for (int i = 0; i < 100; ++i){
		long long a = (rand() % (x - 2)) + 2;
		if (gcd(a, x) != 1)
			return false;			
		if (pows(a, x - 1, x) != 1)		
			return false;			
	}
	return true;
}

map<long long, int> cnt;
map<long long, int> who;
vector<long long> arr;

const int p = 998244353;

int ans = 1;

int mul(long long a, int b) {
	return (a * b) % p;
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

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    // read("input");
    cin >> n;
    arr.resize(n);
    cin >> arr;
    for (int i = 0; i < n; ++i) {
    	long long sqr = 0;
        sqr = round(pow(arr[i], 1. / 4));
        if (arr[i] != 1 && sqr * sqr * sqr * sqr == arr[i]) {
            cnt[sqr] += 4;
            who[sqr] = 0;
            arr[i] = 1;
        }
        sqr = round(pow(arr[i], 1. / 3));
        if (arr[i] != 1 && sqr * sqr * sqr == arr[i]) {
            cnt[sqr] += 3;
            who[sqr] = 0;
            arr[i] = 1;
        }
        sqr = sqrt(arr[i]);
    	if (arr[i] != 1 && sqr * sqr == arr[i]) {
    		cnt[sqr] += 2;
    		who[sqr] = 0;
    		arr[i] = 1;
    	}
    	if (arr[i] == 1) {
    		swap(arr.back(), arr[i]);
    		arr.pop_back();
    		--n;
    		--i;
    		continue;
    	}
    }
    for (int i = 0; i < arr.size(); ++i) {
    	who[arr[i]]++;
    }	
    for (int i = 0; i < arr.size(); ++i) {
    	if (who[arr[i]] == 0) {
    		continue;
    	}
    	auto w = who;
    	for (auto j : w) {
    		if (j.x == arr[i]) {
    			continue;
    		}
    		long long g = gcd(j.x, arr[i]);
    		if (g != 1) {
    			cnt[g] += j.y + who[arr[i]];
    			cnt[j.x / g] += j.y;
    			cnt[arr[i] / g] += who[arr[i]];
    			who[arr[i]] = 0;
    			who[j.x] = 0;
    			break;
    		}
    	}
    	if (who[arr[i]] != 0) {
    		int v = who[arr[i]] + 1;
    		ans = mul(ans, mul(v, v));
    		who[arr[i]] = 0;
    	}
    }
    for (auto i : cnt) {
    	if (i.x == 1) continue;
    	ans = mul(ans, i.y + 1);
    }
    cout << ans << '\n';
}