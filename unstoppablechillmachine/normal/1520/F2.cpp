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
 
const int N = 2e5 + 10;
int t[8 * N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, T;
  cin >> n >> T;
  for (int i = 1; i <= 8 * n + 10; i++) {
    t[i] = -1;
  }
  auto recalc = [&](int v) {
    if (v == 0) {
      return;
    }
    if (t[v] == -1) {
      if (t[v / 2] != -1 && t[v ^ 1] != -1) {
        t[v] = t[v / 2] - t[v ^ 1];
      } else if (t[2 * v] != -1 && t[2 * v + 1] != -1) {
        t[v] = t[2 * v] + t[2 * v + 1];
      }
    }
  };

  auto ask = [&](int v, int l, int r) {
    recalc(v);
    if (t[v] == -1) {
      cout << "? " << l << ' ' << r << endl;
      int result;
      cin >> result;
      t[v] = result;
    }
    return t[v];
  };

  auto guess = [](int result) {
    cout << "! " << result << endl;
  };

  function<int(int, int, int, int)> go = [&](int v, int l, int r, int cnt) {
    if (l == r) {
      assert(cnt == 1);
      return l;
    }
    int mid = (l + r) / 2, zeros_left = (mid - l + 1) - ask(2 * v, l, mid);
    recalc(2 * v + 1);
    recalc(v / 2);
    if (zeros_left >= cnt) {
      return go(2 * v, l, mid, cnt);
    }
    else {
      return go(2 * v + 1, mid + 1, r, cnt - zeros_left);
    }
  };

  function<void(int, int, int, int)> update = [&](int v, int l, int r, int need) {
    if (l == r) {
      t[v] = 1;
      return;
    }
    int mid = (l + r) / 2;
    if (need <= mid) {
      update(2 * v, l, mid, need);
    }
    else {
      update(2 * v + 1, mid + 1, r, need);
    }
    if (t[v] != -1) {
      t[v]++;
    }
  };

  for (int i = 0; i < T; i++) {
    int pos;
    cin >> pos;
    int result = go(1, 1, n, pos);
    guess(result);
    update(1, 1, n, result);
  }
}