#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;

void source() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> arr(n);
  for (auto &it : arr) {
    cin >> it;
  }
  int ans = arr.back() - arr[0] + 1;
  multiset<int> st;
  for (int i = 1; i < n; i++) {
    st.insert(arr[i] - arr[i - 1] - 1);
  }
  for (int i = 1; i < k; i++) {
    ans -= *st.rbegin();
    st.erase(--st.end());
  }
  cout << ans;
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}