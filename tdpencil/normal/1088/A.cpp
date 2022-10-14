#include <algorithm>
#include <unordered_set>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <unordered_map>
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
#define ll long long
#define sz(s) (int(s.size()))
#define all(x) x.begin(),x.end()
#define sum(x) accumulate(x.begin(), x.end(), 0LL)
#define vec vector
#define nl '\n'
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


inline void run_case() {
	int x;cin >> x;
	if(x == 1) {
		cout << -1 << '\n';
		return;
	}
	for(int i = 2; i <= x; i++) {
		for(int j = i; j <= x; j += i) {
			if(j % i == 0 && i * j > x && j / i < x){
				cout << j << " " << i << '\n';
				return;
			}
		}
	}
	cout << -1 << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--)
		run_case();
}