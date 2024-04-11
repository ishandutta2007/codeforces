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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int l = 0;
  vector<int> have(26);
  for (int i = 1; i < SZ(s); i++) {
    if (s[i] != s[l]) {
      have[s[l] - 'a'] += (i - l) / k;
      l = i;
    }  
  } 
  have[s[l] - 'a'] += (SZ(s) - l) / k;
  int mx = 0;
  for (auto it : have) {
    mx = max(mx, it);
  } 
  cout << mx;
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