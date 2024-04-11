#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
typedef long long ll; 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

set<ll> cubes;

void precalc() {
	ll i = 1, cur = 0;


	while( i * i * i <= ll(1e12)) {
		cubes.insert(i*i*i);
		i++;
	}
}
void solve() {
	ll x; cin >> x;
	bool works = false;
	for(ll i = 1; i * i * i <= x; i++) {
		ll res = x - i*i*i;
		// res should be a cube
		auto it = cubes.find(res);

		if(it != cubes.end() && *it != 0) {
			works = true;
		}
	}

	cout << (works ? "YES\n" : "NO\n");
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    precalc();
    while(T--)
        solve();
}