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

const int N = 5e5 + 10;
int ones[N], go[N], calc[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  s.insert(s.begin(), '0');
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      ones[i] = 0;
    }
    else {
      ones[i] = ones[i - 1] + 1;
    }
  }
  vector<pair<int, int>> st;
  for (int i = 1; i <= n; i++) {
    while (!st.empty() && st.back().F <= ones[i]) {
      st.pop_back();
    }
    if (!st.empty()) {
      go[i] = st.back().S;
    }
    else {
      go[i] = 0;
    }
    st.pb({ones[i], i});
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      calc[i] = calc[i - 1];
      ans += calc[i];
      continue;
    }
    calc[i] = ones[i] * (ones[i] + 1) / 2ll;
    calc[i] += ones[i] * (i - go[i] - ones[i]);
    if (go[i]) {
      calc[i] += calc[go[i]] + (ones[i] * ones[i] - (ones[i] * (ones[i] + 1) / 2ll));
    }
    ans += calc[i];
  }
  cout << ans << '\n';
}