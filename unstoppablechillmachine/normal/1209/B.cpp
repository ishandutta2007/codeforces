#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
  
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<bool> on(n);
  for (int i = 0; i < n; i++) {
  	char c;
  	cin >> c;
  	if (c == '1') {
  		on[i] = true;
  	}
  }
  vector<pair<int, int>> arr(n);
  for (auto &it : arr) {
  	cin >> it.F >> it.S;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
  	if (on[i]) {
  		ans++;
  	}
  }
  for (int i = 1; i <= 2520; i++) {
  	for (int j = 0; j < n; j++) {
  		if (i >= arr[j].S && (i - arr[j].S) % arr[j].F == 0) {
  			on[j] = !on[j];
  		}
  	}
  	int sum = 0;
  	for (int j = 0; j < n; j++) {
  		if (on[j]) {
  			sum++;
  		}
  	}
  	ans = max(ans, sum);
  }
  cout << ans << '\n';
}