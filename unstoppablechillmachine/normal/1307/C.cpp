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
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (auto it : s) {
  	cnt[it - 'a']++;
  }		
  int ans = 0;
  for (int i = 0; i < 26; i++) {
  	ans = max(ans, cnt[i]);
  }
  vector<vector<int>> calc(26, vector<int>(26));
  for (int i = 0; i < SZ(s); i++) {
  	cnt[s[i] - 'a']--;
  	for (int j = 0; j < 26; j++) {
  		calc[s[i] - 'a'][j] += cnt[j];
  	}
  }
  for (int i = 0; i < 26; i++) {
  	for (int j = 0; j < 26; j++) {
  		ans = max(ans, calc[i][j]);
  	}
  }
  cout << ans << '\n';
}