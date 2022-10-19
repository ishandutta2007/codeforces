#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

map<int, int> calc;

int get(int mask) {
  if (calc.count(mask)) {
    return calc[mask];
  }
  vector<int> ok(50);
  for (int i = 0; (1ll << i) <= mask; i++) {
    if ((mask >> i) & 1) {
      int mask2 = mask;
      for (int j = i; (1ll << j) <= mask; j += i + 1) {
        if ((mask2 >> j) & 1) {
          mask2 ^= 1 << j;
        }
      }
      ok[get(mask2)] = true;
    }
  }
  calc[mask] = 0;
  while (ok[calc[mask]]) {
    calc[mask]++;
  }
  return calc[mask];
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  vector<int> kek(30);
  kek[0] = 0;
  kek[1] = 1;
  kek[2] = 2;
  kek[3] = 1;
  kek[4] = 4;
  kek[5] = 3;
  kek[6] = 2;
  kek[7] = 1;
  kek[8] = 5;
  kek[9] = 6;
  kek[10] = 2;
  kek[11] = 1;
  kek[12] = 8;
  kek[13] = 7;
  kek[14] = 5;
  kek[15] = 9;
  kek[16] = 8;
  kek[17] = 7;
  kek[18] = 3;
  kek[19] = 4;
  kek[20] = 7;
  kek[21] = 4;
  kek[22] = 2;
  kek[23] = 1;
  kek[24] = 10;
  kek[25] = 9;
  kek[26] = 3;
  kek[27] = 6;
  kek[28] = 11;
  kek[29] = 12;
  int n;
  cin >> n;
  set<int> used;
  int ans = 0;
  for (int i = 2; i * i <= n; i++) {
    if (used.count(i)) {
      continue;
    }
    int cur = i, cnt = 1;
    used.insert(i);
    while (cur * 1ll * i <= n) {
      cur *= i;
      cnt++;
      used.insert(cur);
    }
    ans ^= kek[cnt];
  }
  if ((n - SZ(used)) & 1) {
    ans ^= 1;
  }
  cout << (ans ? "Vasya" : "Petya") << '\n'; 
}