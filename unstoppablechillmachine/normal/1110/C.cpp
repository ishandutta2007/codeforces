#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;

map<int, int> ans;
vector<int> lol = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
void source() {
  for (int i = 2; i <= 25; i++) {
    ans[(1 << i) - 1] = lol[i - 2];
  }
  int test;
  cin >> test;
  for (int tt = 0; tt < test; tt++) {
    int x;
    cin >> x;
    if (ans.find(x) != ans.end()) {
      cout << ans[x] << '\n';
    }
    else {
      int mx;
      for (int i = 0; i < 26; i++) {
        if ((x >> i) & 1) {
          mx = i;
        }
      }
      int pp = (1 << (mx + 1)) - 1;
      cout << pp << '\n';
    }
  }
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