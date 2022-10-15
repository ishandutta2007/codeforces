// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 200005;
set <pii> a[4], s[4];
multiset <int> chose, inq;
int num[4][N], sum[4][N], len[4];
int n, m, k, t;

ll cans, ans = 1e18;
int calc(int x) {
  if (x <= k) return m + x - 2 * k;
  else return m - x;
}

int main() {
  n = read(), m = read(), k = read();
  for (rint i = 1; i <= n; i++) {
    int t = read(), p1 = read(), p2 = read();
    s[2 * p1 + p2].insert(make_pair(t, i));
  }
  for (rint i = 0; i < 4; i++) {
    a[i] = s[i];
    for (auto v: a[i]) {
      len[i]++;
      num[i][len[i]] = v.first;
      sum[i][len[i]] = sum[i][len[i] - 1] + v.first;
    }
  }
  
  for (rint i = 1; i <= len[0]; i++) inq.insert(num[0][i]);
  for (rint i = k + 1; i <= len[1]; i++) inq.insert(num[1][i]);
  for (rint i = k + 1; i <= len[2]; i++) inq.insert(num[2][i]);
  for (rint i = 1; i <= m - 2 * k; i++) {
    if (inq.empty()) break;
    auto it = inq.begin();
    chose.insert(*it);
    //printf("added %d\n", *it);
    cans += *it;
    inq.erase(it);
  }
  
  for (rint i = 0; i <= m; i++) {
    if (i) {
      if (k - i + 1 >= 1) {
        if (k - i + 1 <= len[1])
          inq.insert(num[1][k - i + 1]);
        if (k - i + 1 <= len[2])
          inq.insert(num[2][k - i + 1]);
      }
      while (chose.size() < calc(i)) {
        if (inq.empty()) break;
        auto it = inq.begin();
        chose.insert(*it);
        inq.erase(it);
        cans += *it;
      }
      while (chose.size() > calc(i)) {
        auto it = chose.end();
        it--;
        cans -= *it;
        inq.insert(*it);
        chose.erase(it);
      }
      while (!inq.empty() && !chose.empty() && *chose.rbegin() > *inq.begin()) {
        auto it1 = chose.end();
        it1--;
        auto it2 = inq.begin();
        int num1 = *it1, num2 = *it2;
        chose.erase(it1);
        inq.erase(it2);
        inq.insert(num1);
        chose.insert(num2);
        //printf("new added %d %d\n", num1, num2);
        cans += num2 - num1;
      }
    }
    
    if (i > len[3] || k - i > len[1] || k - i > len[2] || (i <= k ? 2 * k - i : i) > m) continue;
    ll cur = sum[3][i] + sum[1][max(0, k - i)] + sum[2][max(0, k - i)];
    //printf("i = %d, %lld %lld\n", i, cur, cans);
    if (chose.size() == calc(i) && cur + cans < ans) {
      ans = cur + cans;
      t = i;
    }
  }
  if (ans == 1e18) {
    puts("-1");
    exit(0);
  }
  printf("%lld\n", ans);
  //printf("t = %d\n", t);
  
  //  
  set <pii> pr;
  for (auto v: a[0]) pr.insert(v);
  for (auto v: a[1]) {
    static int id = 0;
    id++;
    if (id >= max(1, k - t + 1)) {
      pr.insert(v);
    }
  }
  for (auto v: a[2]) {
    static int id = 0;
    id++;
    if (id >= max(1, k - t + 1)) {
      pr.insert(v);
    }
  }

  for (auto v: a[3]) {
    static int id = 0;
    id++;
    if (id <= t) {
      printf("%d ", v.second);
    }
  }
  for (auto v: a[1]) {
    static int id = 0;
    id++;
    if (id <= k - t) {
      printf("%d ", v.second);
    }
  }
  for (auto v: a[2]) {
    static int id = 0;
    id++;
    if (id <= k - t) {
      printf("%d ", v.second);
    }
  }
  //printf("size = %d\n", pr.size());
  for (auto v: pr) {
    static int id = 0;
    id++;
    if (id <= calc(t)) {
      printf("%d ", v.second);
    } else {
      break;
    }
  }
  puts("");
  return 0;
}