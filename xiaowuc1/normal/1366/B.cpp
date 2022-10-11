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
	int n, x, m;
	cin >> n >> x >> m;
	int lhs = x;
	int rhs = x;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if(a > rhs || b < lhs) continue;
		if(a < lhs) {
			lhs = a;
		}
		if(b > rhs) {
			rhs = b;
		}
	}
	cout << rhs-lhs+1 << "\n";
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