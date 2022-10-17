#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int N = 5e5 + 10;
int a[N], need[N], cur[N], cur2[N];
bool take[N];
void source() {
  int n, k, cnt, s;
  cin >> n >> k >> cnt >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  set<int> st;
  for (int i = 1; i <= s; i++) {
    int x;
    cin >> x;
    need[x]++;
    st.insert(x);
  }
  int r = 0, ost = SZ(st);
  while (r < n && ost > 0) {
    r++;
    cur[a[r]]++;
    if (cur[a[r]] == need[a[r]]) {
      ost--;
    }
  }
  if (ost > 0) {
    cout << -1;
    exit(0);
  }
  pair<int, int> ans = {r, 1};
  for (int i = 2; i <= n; i++) {
    cur[a[i - 1]]--;
    while (cur[a[i - 1]] < need[a[i - 1]] && r < n) {
      r++;
      cur[a[r]]++;
    }
    if (cur[a[i - 1]] < need[a[i - 1]]) {
      break;
    }
    ans = min(ans, make_pair((i - 1) % k + r - i + 1, i));
  }
  if (ans.F > n - k * cnt + k) {
    cout << -1;
    exit(0);
  }
  ost = SZ(st);
  int kek = 0;
  for (int i = ans.S;; i++) {
    if (cur2[a[i]] < need[a[i]]) {
      take[i] = true;
      kek++;
      cur2[a[i]]++;
      if (cur2[a[i]] == need[a[i]]) {
        ost--;
      }
      if (ost == 0) {
        break;
      }
    }
  }
  for (int i = ans.S;; i++) {
    if (kek == k) {
      break;
    }
    if (!take[i]) {
      take[i] = true;
      kek++;
    }
  }
  int fff = (cnt - 1);
  int xx = (ans.S - 1) / k;
  for (int i = 1; i <= min(xx, fff) * k; i++) {
    take[i] = true;
  }
  fff -= xx;
  if (fff < 0) {
    fff = 0;
  }
  for (int i = n - fff * k + 1; i <= n; i++) {
    assert(!take[i]);
    take[i] = true;
  }
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (!take[i]) {
      res.pb(i);
    }
  }
  cout << SZ(res) << '\n';
  for (auto it : res) cout << it << ' ';
}
signed main() {
#ifdef extraterrestrial_
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}