#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
  	int n, x;
  	cin >> n >> x;
  	vector<int> a(n);
  	for (auto &it : a) {
  		cin >> it;
  	}
  	sort(all(a));
  	if (x < a.back()) {
  		cout << (find(all(a), x) != a.end() ? 1 : 2) << '\n'; 
  	}
  	else {
  		cout << x / a.back() + (x % a.back() != 0) << '\n';
  	}
  }		
}