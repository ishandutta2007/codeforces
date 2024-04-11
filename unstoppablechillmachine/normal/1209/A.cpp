#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
  
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 	int n;
 	cin >> n;
 	vector<int> a(n);
 	for (auto &it : a) {
 		cin >> it;
 	}
 	sort(all(a));
 	int ans = 0;
 	vector<bool> used(n);
 	for (int i =0 ; i < n; i++) {
 		if (!used[i]) {
 			ans++;
 			used[i] = true;
 			for (int j = i + 1; j < n; j++) {
 				if (a[j] % a[i] == 0) {
 					used[j] = true;
 				}
 			}
 		}
 	} 
 	cout << ans << '\n';
}