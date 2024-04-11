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
  int n;
  cin >> n;
  vector<pair<char, int>> que;
  for (int i = 0; i < 2 * n; i++) {
    char c;
    cin >> c;
    if (c == '+') {
      que.pb({c, 0});
    }
    else {
      int x;
      cin >> x;
      que.pb({c, x});
    }
  } 
  reverse(all(que));
  vector<int> ans;
  set<int> have;
  for (auto it : que) {
    if (it.F == '-') {
      if (!have.empty() && it.S > *have.begin()) {
        cout << "NO\n";
        exit(0);
      }
      have.insert(it.S);
    }
    else {
      if (have.empty()) {
        cout << "NO\n";
        exit(0);  
      }
      ans.pb(*have.begin());
      have.erase(have.begin());
    }
  }
  reverse(all(ans));
  cout << "YES\n";
  for (auto it : ans) {
    cout << it << ' ';
  }
  cout << '\n';
}