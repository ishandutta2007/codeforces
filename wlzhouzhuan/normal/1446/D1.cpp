// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 200005;

vector<int> gr[N];
set<int> s;
int a[N], cnt[N], n, mx;

int sum[N], ans;

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    gr[a[i]].pb(i);
    mx = max(mx, ++cnt[a[i]]);
  }
  int num = 0, t;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == mx) {
      t = i, num++;
    }
  }
  if (num >= 2) return printf("%d\n", n) & 0;
  
  for (int i = 1; i <= n; i++) {
    if (a[i] == t) {
      s.insert(i);
    }
  }
  for (int i = 1; i <= n + 1; i++) sum[i] = sum[i - 1] + (a[i] == t);
  for (int i = 1; i <= n; i++) {
    if (!cnt[i] || i == t) continue;
    vector<int> bin;
    vector<int> zz;
    for (auto v: gr[i]) {
      auto it = s.lower_bound(v);
      if (it != s.begin()) {
        bin.pb(*prev(it));
        zz.pb(*prev(it));
        s.erase(prev(it));
      }
      if (it != s.end()) {
        bin.pb(*it);
        zz.pb(*it);
        s.erase(it);
      }
      it = s.lower_bound(v);
      if (it != s.begin()) {
        bin.pb(*prev(it));
        zz.pb(*prev(it));
        s.erase(prev(it));
      }
      if (it != s.end()) {
        bin.pb(*it);
        zz.pb(*it);
        s.erase(it);
      }
    }
    //cerr << "!\n";
    
    auto it = s.lower_bound(*min_element(zz.begin(), zz.end()));
    if (it != s.begin()) {
      it--;
      zz.pb(*it);
    }
    zz.pb(0);
    it = s.upper_bound(*max_element(zz.begin(), zz.end()));
    if (it != s.end()) {
      zz.pb(*it);
    } 
    zz.pb(n + 1);
    
    for (auto v: gr[i]) zz.pb(v); 
    sort(zz.begin(), zz.end());
    
    //printf("[%d]: ", i);
    //for (auto v: zz) printf("%d ", v);
    //puts("");
    
    map<int, int> xay;
    int jy = 0;
    for (auto v: zz) {
      if (v && xay.count(sum[v - 1] + jy)) {
        ans = max(ans, v - 1 - xay[sum[v - 1] + jy]);
        //if (ans == 7) {
        //  printf("i = %d, v = %d\n", i, v);
        //  printf("jy = %d\n", jy);
        //}
      }
      if (a[v] == i) jy--;
      if (!xay.count(sum[v] + jy)) xay[sum[v] + jy] = v;
    }
    for (auto v: bin) s.insert(v);
  }
  print(ans, '\n');
  return 0;
}