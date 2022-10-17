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

#define partition dayte_tyank

bool prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

vector<pair<int, vector<int>>> partition(16);

void f(vector<int> &kek) {
  for (int i = 0; i < 16; i++) {
    partition[i].F = 1;
  }
  for (auto it : kek) {
    //cout << "LOL " << it << endl;
    pair<int, int> best = {partition[0].F, 0};
    for (int i = 1; i < 16; i++) {
      best = min(best, make_pair(partition[i].F, i));
    }
    assert(log2(best.F) + log2(it) <= log2(2e18));
    assert(best.F * it <= 1e18);
    //cout << it << ' ' << best.S << '\n';
    partition[best.S].F *= it;
    partition[best.S].S.pb(it);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> p;
  for (int i = 2; i * i * i * 4ll <= 1e9; i++) {
    if (prime(i)) {
      p.pb(i);
    }
  }
  f(p);
  int T;
  cin >> T;
  while (T--) {
    vector<int> guys;
    for (auto it : partition) {
      cout << "? " << it.F << endl;
      int rez;
      cin >> rez;
      for (int &del : it.S) {
        if (rez % del == 0) {
          guys.pb(del);
        }
      }
    }
    //cout << "HEY " << SZ(guys) << endl;
    int know = 1;
    for (int i = 0; i < SZ(guys); i += 2) {
      int cur1 = guys[i], cur2 = 1;
      while (cur1 * guys[i] <= 1e9) {
        cur1 *= guys[i];
      }
      if (i + 1 < SZ(guys)) {
        while (cur2 * guys[i + 1] <= 1e9) {
          cur2 *= guys[i + 1];
        }
      }
      cout << "? " << cur1 * cur2 << endl;
      int rez;
      cin >> rez;
      int cnt1 = 0, cnt2 = 0;
      while (rez % guys[i] == 0) {
        rez /= guys[i];
        cnt1++;
      }
      if (cur2 != 1) {
        while (rez % guys[i + 1] == 0) {
          rez /= guys[i + 1];
          cnt2++;
        }
      }
      know *= (cnt1 + 1) * (cnt2 + 1);
    }
    cout << "! " << max(know + 7ll, know * 2ll) << endl;
  }
  //cout << f(p) << '\n';
}