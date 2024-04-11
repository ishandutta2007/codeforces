#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
struct Person {
  int tm, s, t, id;
  bool operator<(const Person &rhs) { return tm < rhs.tm; }
} a[100001];
int n, m, id = 1, pos = 1, p;
long long now;
long long ans[100001];
std::set<std::pair<int, int>, std::greater<std::pair<int, int>>> in_d, out_d;
std::set<std::pair<int, int>> in_u, out_u;
void Insert() {
  while (a[id].tm == now) {
    if (a[id].s == pos) {
      if (a[id].t > pos) {
        in_u.emplace(a[id].t, a[id].id);
      } else {
        in_d.emplace(a[id].t, a[id].id);
      }
    } else {
      if (a[id].s > pos) {
        out_u.emplace(a[id].s, id);
      } else {
        out_d.emplace(a[id].s, id);
      }
    }
    id++;
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].tm >> a[i].s >> a[i].t;
    a[i].id = i;
  }
  std::sort(a + 1, a + n + 1);
  in_d.emplace(-1, 0);
  out_d.emplace(-1, 0);
  in_u.emplace(m + 1, 0);
  out_u.emplace(m + 1, 0);
  while (p < n) {
    std::size_t cntd = in_d.size() + out_d.size(),
                cntu = in_u.size() + out_u.size();
    if (cntd == 2 && cntu == 2) {
      now = a[id].tm;
      Insert();
      continue;
    }
    if (cntd > cntu) {
      std::pair<int, int> in = *in_d.begin(), out = *out_d.begin();
      int to1 = in.first, to2 = out.first;
      if (id <= n && a[id].tm - now < pos - to1 && a[id].tm - now < pos - to2) {
        pos -= a[id].tm - now;
        now = a[id].tm;
      } else {
        int des = std::max(to1, to2);
        now += pos - des;
        pos = des;
        while (!in_d.empty() && in_d.begin()->first == pos) {
          ans[in_d.begin()->second] = now;
          in_d.erase(in_d.begin());
          p++;
        }
        while (!out_d.empty() && out_d.begin()->first == pos) {
          int ii = out_d.begin()->second;
          if (a[ii].t > pos) {
            in_u.emplace(a[ii].t, a[ii].id);
          } else {
            in_d.emplace(a[ii].t, a[ii].id);
          }
          out_d.erase(out_d.begin());
        }
      }
      Insert();
    } else {
      std::pair<int, int> in = *in_u.begin(), out = *out_u.begin();
      int to1 = in.first, to2 = out.first;
      if (id <= n && a[id].tm - now < to1 - pos && a[id].tm - now < to2 - pos) {
        pos += a[id].tm - now;
        now = a[id].tm;
      } else {
        int des = std::min(to1, to2);
        now += des - pos;
        pos = des;
        while (!in_u.empty() && in_u.begin()->first == pos) {
          ans[in_u.begin()->second] = now;
          in_u.erase(in_u.begin());
          p++;
        }
        while (!out_u.empty() && out_u.begin()->first == pos) {
          int ii = out_u.begin()->second;
          if (a[ii].t > pos) {
            in_u.emplace(a[ii].t, a[ii].id);
          } else {
            in_d.emplace(a[ii].t, a[ii].id);
          }
          out_u.erase(out_u.begin());
        }
      }
      Insert();
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}