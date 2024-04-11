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

const int MX = 5e6 + 10;
const int N = 1e5 + 10;
int num[MX], cnt[N];
string s[N];
set<int> g[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    int sum = 0, current = 1;
    for (int j = 0; j < k; j++) {
      if (s[i][j] != '_') {
        sum += current * (s[i][j] - 'a' + 1);
      }
      current *= 27;
    }
    //cout << sum << ' ' << i << '\n';
    num[sum] = i;
  }
  for (int i = 1; i <= m; i++) {
    string t;
    int mn;
    cin >> t >> mn;
    vector<int> add;
    bool ok = false;
    for (int mask = 0; mask < (1 << k); mask++) {
      int sum = 0, current = 1;
      for (int j = 0; j < k; j++) {
        if ((mask >> j) & 1) {
          sum += (t[j] - 'a' + 1) * current;
        }
        current *= 27;
      }
      if (num[sum]) {
        add.pb(num[sum]);
        if (num[sum] == mn) {
          ok = true;
        }
      }
    }
    if (!ok) {
      cout << "NO\n";
      exit(0);
    }
    for (auto it : add) {
      if (it != mn) {
        g[mn].insert(it);
      }
    }
  }
  set<pair<int, int>> st;
  for (int i = 1; i <= n; i++) {
    for (int j : g[i]) {
      cnt[j]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    st.insert({cnt[i], i});
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int v = st.begin()->S;
    //cout << s[v] << endl;
    st.erase(st.begin());
    if (cnt[v]) {
      cout << "NO\n";
      exit(0);
    }
    ans.pb(v);
    for (int u : g[v]) {
      st.erase({cnt[u], u});
      cnt[u]--;
      st.insert({cnt[u], u});
    }
  }
  cout << "YES\n";
  for (auto it : ans) {
    cout << it << ' ';
  }
  cout << '\n';
}