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

int ask(vector<int> x) {
  if (x.empty()) {
    return 0;
  }
  cout << "? " << SZ(x) << ' ';
  for (auto it : x) {
    cout << it + 1 << ' ';
  }
  cout << endl;
  int res;
  cin >> res;
  return res;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> have;
  for (int i = 0; i < (1 << 13); i++) {
    if (__builtin_popcount(i) == 6 && SZ(have) < n) {
      have.pb(i);
    }
  }
  vector<vector<int>> que(13);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 13; j++) {
      if ((have[i] >> j) & 1) {
        que[j].pb(i);
      }
    }
  }
  vector<int> rez(13);
  for (int i = 0; i < SZ(que); i++) {
    rez[i] = ask(que[i]);
  }
  cout << "! ";
  for (int i = 0; i < n; i++) {
    int vl = 0;
    for (int j = 0; j < 13; j++) {
      if (!((have[i] >> j) & 1)) {
        vl |= rez[j];
      }
    }
    cout << vl << ' ';
  }
  cout << endl;
}