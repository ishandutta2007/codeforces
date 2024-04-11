#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int l[100005];
int need[100005];
int n, m;
bool seen[100005];
bool can(int sz) {
	memset(seen, 0, sizeof(seen));
	int left = m;
	int t = 0;
	for(int i = sz-1; i >= 0; i--) {
		if(l[i] == 0) {
			if(t) t--;
		}
		else if(!seen[l[i]]) {
			seen[l[i]] = true;
			t += need[l[i]];
			left--;
		}
		else {
			if(t) t--;
		}
	}
	return left == 0 && t == 0;
}

void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> l[i];
	for(int i = 1; i <= m; i++) cin >> need[i];
	int lhs = 1;
	int rhs = n+1;
	while(lhs < rhs) {
		int mid = (lhs+rhs)/2;
		if(can(mid)) rhs = mid;
		else lhs = mid+1;
	}
	if(lhs > n) lhs = -1;
	cout << lhs << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}