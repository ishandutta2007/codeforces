#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define nl "\n"
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s;
ll ans, i, j;
vector<pair<char, int>> run_length_encoding(const string &s) {
  vector<pair<char, int>> ans;
  if (s.empty()) return ans;
  int cur = 0, i = 0;
  char mainCharacter = s[i];
#define n sz(s)
  while (i < n) {
    while (i < n && s[i] == mainCharacter) ++i, ++cur;
    if (i == n) break;
    ans.emplace_back(mainCharacter, cur);
    mainCharacter = s[i];
    cur = 0;
  }
  ans.emplace_back(mainCharacter, cur);
  return ans;
}
void solve() {
  cin >> s;
  vector<pair<char, int>> ran = run_length_encoding(s);
  for (auto &u : ran)
    if (u.first == 'v') u.second--;

  int k = ran.size();
  ll cur = 0, cur2 = 0;
  rep(i, 0, k) {
    if (ran[i].first == 'v') cur += ran[i].second, ans += cur2 * ran[i].second;
    if (ran[i].first == 'o') cur2 += ran[i].second * cur;
  }
  cout << ans << nl;
}
int32_t main() {
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}