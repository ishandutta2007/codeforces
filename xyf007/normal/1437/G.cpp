#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, q, a[300001], ch[300001][26], tot, ed[300001], id[300001], cnt;
std::string s[300001], t;
std::multiset<int, std::greater<int>> st[300001];
bool vis[300001];
void Insert(const std::string s, int x) {
  int now = 0;
  for (const auto &c : s) {
    if (!ch[now][c - 'a']) ch[now][c - 'a'] = ++tot;
    now = ch[now][c - 'a'];
  }
  vis[ed[x] = now] = true;
  if (!id[now]) id[now] = ++cnt;
  st[id[now]].emplace(0);
}
class SuffixAutomaton {
 private:
  struct Node {
    int len, link, nxt[26];
  } t_[600001];
  int sz_, last_;

 public:
  SuffixAutomaton() { t_[0].link = -1; }
  void Clear() {
    for (int i = 0; i <= sz_; i++)
      t_[i].len = t_[i].link = 0, std::memset(t_[i].nxt, 0, sizeof(t_[i].nxt));
    sz_ = last_ = 0, t_[0].link = -1;
  }
  void Expand(char c) {
    int cur = ++sz_, p = last_;
    t_[cur].len = t_[last_].len + 1;
    while (p != -1 && !t_[p].nxt[c - 'a'])
      t_[p].nxt[c - 'a'] = cur, p = t_[p].link;
    if (p == -1) {
      t_[cur].link = 0;
    } else {
      int q = t_[p].nxt[c - 'a'];
      if (t_[q].len == t_[p].len + 1) {
        t_[cur].link = q;
      } else {
        int nq = ++sz_;
        t_[nq].len = t_[p].len + 1, t_[nq].link = t_[q].link;
        std::memcpy(t_[nq].nxt, t_[q].nxt, sizeof(t_[q].nxt));
        while (p != -1 && t_[p].nxt[c - 'a'] == q)
          t_[p].nxt[c - 'a'] = nq, p = t_[p].link;
        t_[cur].link = t_[q].link = nq;
      }
    }
    last_ = cur;
  }
  bool Find(const std::string &s) {
    int now = 0;
    for (const auto &c : s) {
      if (!t_[now].nxt[c - 'a']) return false;
      now = t_[now].nxt[c - 'a'];
    }
    return true;
  }
  ~SuffixAutomaton() {}
} sam;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q;
  std::size_t B = 0;
  for (int i = 1; i <= n; i++) std::cin >> s[i], B += s[i].size();
  for (int i = 1; i <= n; i++) Insert(s[i], i);
  B = std::sqrt(B);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, y;
      std::cin >> x >> y;
      st[id[ed[x]]].erase(st[id[ed[x]]].find(a[x]));
      st[id[ed[x]]].emplace(a[x] = y);
    } else {
      std::cin >> t;
      int ans = -1;
      if (t.size() <= B) {
        for (std::size_t i = 0; i < t.size(); i++) {
          int now = 0;
          for (std::size_t j = i; j < t.size(); j++) {
            if (!ch[now][t[j] - 'a']) break;
            now = ch[now][t[j] - 'a'];
            if (vis[now]) checkmax(ans, *st[id[now]].begin());
          }
        }
      } else {
        sam.Clear();
        for (const auto &c : t) sam.Expand(c);
        for (int i = 1; i <= n; i++)
          if (sam.Find(s[i])) checkmax(ans, *st[id[ed[i]]].begin());
      }
      std::cout << ans << '\n';
    }
  }
  return 0;
}