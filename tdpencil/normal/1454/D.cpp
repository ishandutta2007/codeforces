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
#define ar array
// vector<int> toRemove[200001];
void solve() {
	ll N;
	cin >> N;
	ll res = N;
	map<ll, int> freq;

	vector<ll> primes;

	for(ll i = 2; i * i <= N; i++) {

		while(N % i == 0) {
			N/=i;
			freq[i]++;
		}

	}

	if(N > 1) freq[N]++;

	int mx = 0, ans = 0;
	for(auto &e: freq) {
		if(e.second > mx) {
			mx = e.second;
			ans = e.first;
		}
	}

	if(mx == 1) {
		cout << 1 << "\n";
		cout << res << "\n";
	} else {
		ll cur = 1;
		for(auto &e: freq)
			if(e.first != ans)
				for(int j = 0; j < e.second; j++)
					cur *= e.first;

		cout << mx << "\n";
		cur *= ans;
		for(int i = 0; i < mx - 1; i++)
			cout << ans << " ";

		cout << cur << "\n";

	}






}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T = 1; cin >> T;
   
    while(T--)
        solve();
}