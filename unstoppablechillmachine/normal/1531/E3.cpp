#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
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
 
const int N = 3e6 + 10;
bool lg[N];
vector<int> g[N], order;
int used[N], permutation[N];
 
bool topsort(int v) {
  used[v] = 1;
  for (auto& u : g[v]) {
    if (!used[u]) {
      if (!topsort(u)) {
        return false;
      }
    } else if (used[u] == 1) {
      return false;
    }
  }
  order.push_back(v);
  used[v] = 2;
  return true;
}
 
int position_left[N], position_right[N];
 
bool solve(int l, int r, int& log_position) {
  if (r - l <= 1) {
    if (l < r) permutation[l] = 0;
    return true;
  }
  int mid = (l + r) / 2;
  bool lft_part = solve(l, mid, log_position);
  if (!lft_part) {
    return false;
  } 
  bool rgt_part = solve(mid, r, log_position);
  if (!rgt_part) {
    return false;
  }
  int len = r - l, left_len = mid - l, right_len = r - mid;
  
  for (int i = 0; i < len; i++) {
    g[i].clear();
    used[i] = 0;
  }
  order.clear();
  
  for (int i = l; i < mid; i++) {
    position_left[permutation[i]] = i - l;
  }
  for (int i = 0; i + 1 < left_len; i++) {
    g[position_left[i]].push_back(position_left[i + 1]);
  }
 
  for (int i = mid; i < r; i++) {
    position_right[permutation[i]] = i - mid;
  }
  for (int i = 0; i + 1 < right_len; i++) {
    g[left_len + position_right[i]].push_back(left_len + position_right[i + 1]);
  }
 
  int ptr1 = 0, ptr2 = 0;
  while (ptr1 < left_len && ptr2 < right_len) {
    if (log_position < 0) {
      return false;
    }
    if (lg[log_position--]) {
      g[left_len + position_right[ptr2++]].push_back(position_left[ptr1]);
    } else {
      g[position_left[ptr1++]].push_back(left_len + position_right[ptr2]);
    }
  }
  for (int i = 0; i < len; i++) {
    if (!used[i]) {
      if (!topsort(i)) {
        return false;
      }
    }
  }
  reverse(all(order));
  int ptr = 0;
  for (auto& v : order) {
    permutation[l + v] = ptr++;
  }
  return true;  
}
 
bool check(int l, int r, int& log_position) {
  if (r - l <= 1) {
    return true;
  }
  int mid = (l + r) / 2;
  if (!check(l, mid, log_position)) {
    return false;
  }
  if (!check(mid, r, log_position)) {
    return false;
  }
  int ptr1 = l, ptr2 = mid;
  while (ptr1 < mid && ptr2 < r) {
    if (log_position < 0) {
      return false;
    }
    if (lg[log_position--]) {
      ptr2++;
    } else {
      ptr1++;
    }
  }
  return true;
}
 
const int maxlen = 1e5;
mt19937 rnd(239);
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  string s;
  cin >> s;
  int n = SZ(s);
  assert(n < N);
  for (int i = 0; i < n; i++) {
    lg[i] = s[n - i - 1] - '0';
  }
  int l = 0, r = maxlen + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int log_position = n - 1;
    if (check(0, mid, log_position)) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  int log_position = n - 1;
  assert(solve(0, l, log_position) && log_position == -1);
  cout << l << '\n';
  for (int i = 0; i < l; i++) {
    cout << permutation[i] + 1 << ' ';
  }
  cout << '\n';
  return 0;
}