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

int dp[1005];
void solve() {
	int s, x1, x2;
	cin >> s >> x1 >> x2;
	int t1, t2;
	cin >> t1 >> t2;
	for(int i = 0; i <= s; i++) {
		dp[i] = t2 * abs(x1 - i);
	}
	int ret = dp[x2];
	int p, d;
	cin >> p >> d;
	bool found = x1 == p;
	int timeNeeded = 0;
	while(true) {
		p += d;
		timeNeeded += t1;
		if(timeNeeded >= ret) break;
		if(p == 0) d = 1;
		if(p == s) d = -1;
		if(timeNeeded >= dp[p]) found = true;
		if(found && p == x2) ret = timeNeeded;
	}
	cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}