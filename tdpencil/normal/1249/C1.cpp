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
const int64_t inf = 1e12;
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
int pow(int x, int y) {
	if(y == 0)
		return 1;
	int mid = pow(x, y / 2);
	if(y % 2 == 0)
		return mid * mid;
	else
		return mid * mid * x;
}

inline void run_case() {
	int n;
	cin >> n;
	// generate every possible subset
	vector<int64_t> pos;

	int limit = 11;
	vector<int> lim;
	for(int i = 0; i <= 10; i++) {
		lim.push_back(pow(3, i));
	}
	vector<int> sm;
	for(int i =0; i < (1 << limit); i++) {
		ll s = 0;
		for(int j = 0; j < limit; j++) {
			if(i & (1 << j)) s += lim[j];
		}
		sm.push_back(s);
	}
	

	auto it = lower_bound(all(sm), n);
	cout << *it << '\n';
	
}


int main() {
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--)
		run_case();
}