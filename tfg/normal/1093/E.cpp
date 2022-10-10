#include <bits/stdc++.h>
#define dbg(x) cerr << ">>> " << x << endl
#define _ << ", " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
const int bs = 3000;

int a[ms], ra[ms], b[ms];
std::vector<int> pos[ms / bs + 10];

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int n, m;
  std::cin >> n >> m;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
    ra[a[i]] = i;
  }
  auto rem = [](std::vector<int> &v, int x) {
    int p = 0;
    while(p < (int) v.size() && v[p] < x) {
      p++;
    }
    assert(p < (int) v.size() && v[p] == x);
    while(p + 1 < (int) v.size()) {
      v[p] = v[p + 1];
      p++;
    }
    v.pop_back();
  };
  auto add = [](std::vector<int> &v, int x) {
    int p = 0;
    while(p < (int) v.size() && v[p] < x) {
      p++;
    }
    v.push_back(-1);
    for(int i = (int) v.size() - 1; i > p; i--) {
      v[i] = v[i - 1];
    }
    v[p] = x;
  };
  for(int i = 0; i < n; i++) {
    std::cin >> b[i];
    b[i]--;
    b[i] = ra[b[i]];
    pos[i / bs].push_back(b[i]);
  }
  for(int i = 0; i < n; i++) {
    if(i % bs == 0) {
      std::sort(pos[i/bs].begin(), pos[i/bs].end());
    }
  }
  while(m--) {
    int t;
    std::cin >> t;
    if(t == 1) {
      int x, y, l, r;
      std::cin >> x >> y >> l >> r;
      x--;y--;l--;r--;
      int ans = 0;
      if(r - l <= 3 * bs) {
        for(int i = l; i <= r; i++) {
          if(x <= b[i] && b[i] <= y) {
            ans++;
          }
        }
      } else {
        assert(r / bs - l / bs > 0);
        int to = l / bs * bs + bs;
        for(int i = l; i < to; i++) {
          if(x <= b[i] && b[i] <= y) {
            ans++;
          }
        }
        to = r / bs * bs;
        for(int i = r; i >= to; i--) {
          if(x <= b[i] && b[i] <= y) {
            ans++;
          }
        }
        to = r / bs;
        for(int i = l / bs + 1; i < to; i++) {
          ans += std::upper_bound(pos[i].begin(), pos[i].end(), y) - std::lower_bound(pos[i].begin(), pos[i].end(), x);
        }
      }
      std::cout << ans << '\n';
    } else {
      int x, y;
      std::cin >> x >> y;
      x--;y--;
      rem(pos[x / bs], b[x]);
      rem(pos[y / bs], b[y]);
      std::swap(b[x], b[y]);
      add(pos[x / bs], b[x]);
      add(pos[y / bs], b[y]);
    }
  }
  return 0;
}