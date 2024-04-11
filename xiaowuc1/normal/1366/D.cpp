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

int minp[10000001];
int a[500000];
int b[500000];
void rsolve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int y;
		cin >> y;
		int x = y;
		int c = minp[x];
		while(x%c==0) {
			x /= c;
		}
		if(x == 1) {
			a[i] = -1;
			b[i] = -1;
		}
		else {
			a[i] = x;
			b[i] = y / a[i];
		}
	}
	for(int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];
	for(int i = 0; i < n; i++) cout << b[i] << " \n"[i == n-1];
}
void solve() {
	for(int x = 2; x <= 10000000; x++) {
		if(minp[x]) continue;
		for(int y = x; y <= 10000000; y += x) {
			if(minp[y] == 0) minp[y] = x;
		}
	}
	rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}