#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int x[300005];
int y[300005];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  int lx = x[0];
  int rx = x[0];
  int ly = y[0];
  int ry = y[0];
  for(int i = 0; i < n; i++) {
    lx = min(lx, x[i]);
    rx = max(rx, x[i]);
    ly = min(ly, y[i]);
    ry = max(ry, y[i]);
  }
  vector<pii> v;
  for(int i = 0; i < n; i++) {
    if(lx == x[i] || rx == x[i] || ly == y[i] || ry == y[i]) {
      v.push_back({x[i], y[i]});
    }
  }
  int three = 0;
  for(int i = 0; i < n; i++) {
    for(pii a: v) {
      for(pii b: v) {
        int now = abs(x[i] - a.first) + abs(a.first - b.first) + abs(b.first - x[i]);
        now += abs(y[i] - a.second) + abs(a.second - b.second) + abs(b.second - y[i]);
        three = max(three, now);
      }
    }
  }
  printf("%d", three);
  for(int i = 4; i <= n; i++) {
    printf(" %d", 2 * (rx - lx) + 2 * (ry - ly));
  }
  printf("\n");
}