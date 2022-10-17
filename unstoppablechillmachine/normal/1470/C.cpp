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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, k, p, cnt_queries = 0;
  //cin >> n >> k >> p;
  cin >> n >> k;
  vector<int> current_pos(n + 1, k);
  int cur = 1;
  vector<int> points;
  for (int i = 1; i <= 480; i++) {
    points.pb(cur);
    if (cur == n) {
      break;
    }
    cur = (cur + i - 1) % n + 1;
  }
  auto ask = [&](int x) {
    cout << "? " << x << endl;
    //int rez = current_pos[x];
    //cnt_queries++;
    //cin >> rez;
    int rez;
    cin >> rez;
    return rez;
  };
  auto answer = [&](int x) {
    cout << "! " << x << endl;
    //assert(p == x);
    exit(0);
  };
  auto do_operation = [&](vector<int> current_pos) {
    vector<int> new_pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int nxt = i + 1, prv = i - 1;
      if (nxt == n + 1) {
        nxt = 1;
      }
      if (prv == 0) {
        prv = n;
      }
      if (i == p) {
        new_pos[nxt] += current_pos[i];
      }
      else {
        new_pos[nxt] += (current_pos[i] + 1) / 2;
        new_pos[prv] += current_pos[i] / 2;
      }
    }
    /*cerr << "CURRENT POS\n";
    for (int i = 1; i <= n; i++) {
      cerr << new_pos[i] << ' ';
    }
    cerr << "\n\n";*/
    return new_pos;
  };
  ask(1);
  //current_pos = do_operation(current_pos);
  pair<int, int> pos;
  for (auto it : points) {
    int rez = ask(it);
    //current_pos = do_operation(current_pos);
    if (rez < k) {
      pos = {it, 1};
      break;
    }
    else if (rez > k) {
      pos = {it, -1};
      break;
    }
  }
  for (;;) {
    if (ask(pos.F) == k) {
      answer(pos.F);
    }
    //current_pos = do_operation(current_pos);
    pos.F += pos.S;
    if (pos.F == 0) {
      pos.F = n;
    }
    if (pos.F == n + 1) {
      pos.F = 1;
    }
  }
}