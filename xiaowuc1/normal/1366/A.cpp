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

bool can(int a, int b, int t) {
	a -= t;
	b -= t;
	return a >= 0 && b >= 0 && a+b >= t;
}
void rsolve() {
	int a, b;
	cin >> a >> b;
	int lhs = 0;
	int rhs = 1e9;
	while(lhs < rhs) {
		int mid = (lhs+rhs+1)/2;
		if(can(a, b, mid)) lhs = mid;
		else rhs = mid-1;
	}
	cout << lhs << "\n";
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