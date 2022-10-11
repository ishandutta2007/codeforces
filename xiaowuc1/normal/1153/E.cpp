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

pii find(int xa, int ya, int xb, int yb) {
	while(xa != xb) {
		int mid = (xa+xb)/2;
		printf("? %d %d %d %d\n", xa, ya, mid, yb); fflush(stdout);
		int val;
		cin >> val;
		assert(val >= 0);
		if(val%2) xb = mid;
		else xa = mid+1;
	}
	while(ya != yb) {
		int mid = (ya+yb)/2;
		printf("? %d %d %d %d\n", xa, ya, xb, mid); fflush(stdout);
		int val;
		cin >> val;
		assert(val >= 0);
		if(val%2) yb = mid;
		else ya = mid+1;
	}
	return {xa, ya};
}

void solve() {
	int n;
	cin >> n;
	vector<pii> ret;
	for(int col = 1; ret.empty() && col < n; col++) {
		printf("? %d %d %d %d\n", 1, 1, n, col); fflush(stdout);
		int val;
		cin >> val;
		assert(val >= 0);
		if(val%2) {
			ret.push_back(find(1, col, n, col));
			ret.push_back(find(1, col+1, n, n));
		}
	}
	for(int row = 1; ret.empty() && row < n; row++) {
		printf("? %d %d %d %d\n", 1, 1, row, n);
		fflush(stdout);
		int val;
		cin >> val;
		assert(val >= 0);
		if(val%2) {
			ret.push_back(find(row, 1, row, n));
			ret.push_back(find(row+1, 1, n, n));
		}
	}
	cout << "!";
	for(pii out: ret) {
		cout << " " << out.first << " " << out.second;
	}
	cout << endl;
	fflush(stdout);
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