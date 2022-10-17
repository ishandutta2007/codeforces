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
  int n, b;
  cin >> b >> n;
  int cur = 1;
  vector<int> a(n);
  for (auto &it : a) {
    cin >> it;
  } 
  reverse(all(a));
  int sum = 0;
  for (auto it : a) {
    sum += (it * cur) % 2;
    cur = (cur * b) % 2;
  }
  cout << (sum & 1 ? "odd" : "even");
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