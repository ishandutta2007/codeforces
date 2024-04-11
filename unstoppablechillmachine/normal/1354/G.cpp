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

const int BUBEN = 20;

int ask(vector<int> a, vector<int> b) {
  cout << "? " << SZ(a) << ' ' << SZ(b) << endl;
  for (auto it : a) {
    cout << it << ' ';
  }
  cout << endl;
  for (auto it : b) {
    cout << it << ' ';
  }
  cout << endl;
  string rez;
  cin >> rez;
  if (rez == "WASTED") {
    exit(0);
  }
  if (rez == "FIRST") {
    return 0; 
  }
  if (rez == "SECOND") {
    return 2;
  }
  return 1;
}

mt19937 rnd(239);

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> order;
    for (int i = 1; i <= n; i++) {
      order.pb(i);
    }
    shuffle(all(order), rnd);
    int pos_max = order[0];
    //0 >
    //1 =
    //2 <
    for (int i = 1; i < min(BUBEN, n); i++) {
      int rez = ask(vector<int>{pos_max}, vector<int>{order[i]});
      if (rez == 2) {
        pos_max = order[i];
      }
    }
    //cout << "C " << pos_max << endl;
    queue<int> ost;
    for (int i = 1; i <= n; i++) {
      if (i != pos_max) {
        ost.push(i);
      }
    }
    vector<vector<int>> kek(11);
    kek[0].pb(pos_max);
    vector<int> need_fnd;
    int lst = 0;
    while ((1 << lst) <= SZ(ost)) {
      vector<int> cur;
      for (int i = 0; i < (1 << lst); i++) {
        int x = ost.front();
        ost.pop();
        cur.pb(x);
      }
      int rez = ask(kek[lst], cur);
      assert(rez <= 1);
      if (rez == 0) {
        need_fnd = cur;
        break;
      }
      else {
        lst++;
        kek[lst] = kek[lst - 1];
        for (int &x : cur) {
          kek[lst].pb(x);
        }
      }
    }
    if (need_fnd.empty()) {
      while (!ost.empty()) {
        need_fnd.pb(ost.front());
        ost.pop();
      }
    }
    while (SZ(need_fnd) > 1) {
      int md = SZ(need_fnd) / 2;
      vector<int> to1, to2;
      for (int i = 0; i < md; i++) {
        to1.pb(need_fnd[i]);
      }
      for (int i = md; i < SZ(need_fnd); i++) {
        to2.pb(need_fnd[i]);
      }
      vector<int> rocks;
      int vl = 0;
      while ((1 << vl) < SZ(to1)) {
        vl++;
      }
      for (int i = 0; i < SZ(to1); i++) {
        rocks.pb(kek[vl][i]);
      }
      int rez = ask(rocks, to1);
      assert(rez <= 1);
      if (rez == 0) {
        need_fnd = to1;
      }
      else {
        need_fnd = to2;
      }
    }
    cout << "! " << need_fnd[0] << endl;
  }
}