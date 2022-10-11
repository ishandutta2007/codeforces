#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<vector<ll>> matrix;

int n;
int f[310000];
int par[310000];
vector<int> child[310000];
int leaves;

int need(int curr, int want) {
	if(child[curr].empty()) return 1;
	if(f[curr] == 1) {
		int total = 1e9;
		for(int out: child[curr]) {
			total = min(total, need(out, want));
		}
		return total;
	}
	else {
		int total = 0;
		for(int out: child[curr]) {
			total += need(out, want);
		}
		return total;
	}
}

bool can(int want) {
	int have = leaves-want+1;
	return need(1, want) <= have;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	for(int i = 2; i <= n; i++) {
		cin >> par[i];
		child[par[i]].push_back(i);
	}
	leaves = 0;
	for(int i = 1; i <= n; i++) if(child[i].empty()) leaves++;
	int lhs = 1;
	int rhs = leaves;
	while(lhs < rhs) {
		int mid = (lhs+rhs+1)/2;
		if(can(mid)) lhs = mid;
		else rhs = mid-1;
	}
	cout << lhs << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
	/*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
	*/
	solve();
}