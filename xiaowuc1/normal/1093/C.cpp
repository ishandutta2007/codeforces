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

ll b[1000000];
ll ret[1000000];
void solve() {
	int n;
	cin >> n;
	for(int i = n/2-1; i >= 0; i--) cin >> b[i];
	ret[n-1] = b[n/2-1];
	for(int i = 1; i < n/2; i++) {
		ret[i] = ret[i-1];
		ret[n-1-i] = b[n/2-1-i] - ret[i];
		if(ret[n-1-i] > ret[n-i]) {
			ll delta = ret[n-1-i] - ret[n-i];
			ret[i] += delta;
			ret[n-1-i] -= delta;
		}
	}
	for(int i = 0; i < n; i++) cout << ret[i] << " ";
	cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}