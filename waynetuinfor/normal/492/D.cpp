#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
vector<int> v;
int n, a[maxn], x, y;
string name[3] = { "Vanya", "Vova", "Both" };

typedef double db;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> x >> y;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int cntx = 0, cnty = 0;
  while (cntx < x || cnty < y) {
    if ((db)(cntx + 1) / (db)x > (db)(cnty + 1) / (db)y) v.push_back(1), ++cnty;
    else if ((db)(cntx + 1) / (db)x < (db)(cnty + 1) / (db)y) v.push_back(0), ++cntx;
    else v.push_back(2), v.push_back(2), ++cnty, ++cntx;
  }
  for (int i = 0; i < n; ++i) cout << name[v[(a[i] - 1) % (x + y)]] << '\n';
  return 0;
}