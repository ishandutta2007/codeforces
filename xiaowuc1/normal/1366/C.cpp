#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;

void rsolve() {
	int r, c;
	cin >> r >> c;
	map<int, map<int, int>> dp;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			int x;
			cin >> x;
			if(2*(i+j) == (r+c-2)) continue;
			dp[min(i+j, r+c-2-i-j)][x]++;
		}
	}
	int ret = 0;
	for(auto out: dp) {
		int lhs = 0;
		int rhs = 0;
		for(auto out2: out.second) {
			lhs = max(lhs, out2.second);
			rhs += out2.second;
		}
		ret += rhs - lhs;
	}
	cout << ret << "\n";
}
void solve() {
	int t;
	cin >> t;
	while(t--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}