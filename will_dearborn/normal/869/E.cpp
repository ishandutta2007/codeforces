#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

const int N = 1 << 12;

ll tr[N + 2505][N + 2505];

void upd(int x, int y1, int y2, ll h) {
  while (y1 <= y2) {
    if (y1 & 1) {
      tr[x][y1] ^= h;
      ++y1;
    }
    if (!(y2 & 1)) {
      tr[x][y2] ^= h;
      --y2;
    }
//    if (y1 > y2) break;
    y1 /= 2; y2 /= 2;
  }
}

void update(int x1, int y1, int x2, int y2, ll h) {
  x1 += N;
  y1 += N;
  x2 += N;
  y2 += N;
  while (x1 <= x2) {
    if (x1 & 1) {
      upd(x1, y1, y2, h);
      ++x1;
    }
    if (!(x2 & 1)) {
      upd(x2, y1, y2, h);
      --x2;
    }
//    if (x1 > x2) break;
    x1 /= 2; x2 /= 2;
  }
}

ll calc(int x, int y) {
  x += N;
  y += N;
  ll res = 0;
  while (x) {
    int y1 = y;
    while (y1) {
      res ^= tr[x][y1];
      y1 /= 2;
    }
    x /= 2;
  }
  return res;
}

ll myrand() {
  return ((ll)(rand() * 875489 + 3241234) << 32) + (ll)(rand() * 12424523 + 73178486);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  srand(57);
  int n, m, q;
  cin >> n >> m >> q;
  map<array<short, 4>, ll> was;
  for (int t = 0; t < q; ++t) {
    int type, x1, y1, x2, y2;
    cin >> type >> x1 >> y1 >> x2 >> y2;
    if (type <= 2) {
      if (x1 > x2) swap(x1, x2);
      if (y1 > y2) swap(y1, y2);
      array<short, 4> v = {x1, y1, x2, y2};
      ll h = was.count(v) ? was[v] : myrand();
      was[v] = h;
      update(x1, y1, x2, y2, h);
    } else {
      if (calc(x1, y1) == calc(x2, y2)) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
  return 0;
}