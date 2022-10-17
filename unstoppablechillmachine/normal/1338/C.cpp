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

vector<int> order = {0, 2, 3, 1};

int get(int x) {
  int were = x;
  int positions = 4;
  while (positions <= x) {
    positions *= 4ll;
  }
  int res = 0;
  while (positions > 1) {
    positions /= 4;
    int cur = x / positions;
    res += positions * order[cur];
    x %= positions;
  }
  //cout << "C " << were << ' ' << res << '\n';
  return res;
}

pair<int, int> gen(int pr) {
  for (int mx_bit = 0;; mx_bit += 2) {
    if ((1ll << mx_bit) >= pr) {
      int res1 = (1ll << mx_bit) + pr - 1, 
      res2 = (1ll << (mx_bit + 1)) + get(pr - 1);
      return {res1, res2};
    }
    else {
      pr -= 1ll << mx_bit;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  /*vector<int> calc;
  set<int> used;
  for (int i = 0; i < 100; i++) {
    for (int j = 1;; j++) {
      if (used.find(j) != used.end()) {
        continue;
      }
      for (int k = j + 1;; k++) {
        if (used.find(k) == used.end() && used.find(j ^ k) == used.end()) {
          used.insert(j);
          used.insert(k);
          used.insert(j ^ k);
          calc.pb(j);
          calc.pb(k);
          calc.pb(j ^ k);
          break;
        }
      }
      break;
    }
  }*/
  int T;
  cin >> T;
  int ptr = 1;
  while (T--) {
    int id;
    cin >> id;
    pair<int, int> kek = gen((id - 1) / 3 + 1);
    if (id % 3 == 1) {
      cout << kek.F << '\n';
      //assert(kek.F == calc[id - 1]);
    }
    else if (id % 3 == 2) {
      cout << kek.S << '\n';
      //assert(kek.S == calc[id - 1]);
    }
    else {
      cout << (kek.F ^ kek.S) << '\n';
      //assert((kek.F ^ kek.S) == calc[id - 1]);
    }
  }
}