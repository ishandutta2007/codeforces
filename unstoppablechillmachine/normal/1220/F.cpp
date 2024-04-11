#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 2e5 + 10;
int a[2 * N], a2[N], t[8 * N];
void build(int v, int l, int r) {
  if (l == r) {
    t[v] = l;
    return;
  }
  int mid = (l + r) / 2;
  build(2 * v, l, mid);
  build(2 * v + 1, mid + 1, r);
  if (a[t[2 * v]] < a[t[2 * v + 1]]) {
    t[v] = t[2 * v];
  }
  else {
    t[v] = t[2 * v + 1];
  }
}

int get_min(int v, int l, int r, int aa, int bb) {
  if (l > bb || r < aa) {
    return 0;
  }
  if (l >= aa && r <= bb) {
    return t[v];
  }
  int mid = (l + r) / 2;
  int A = get_min(2 * v, l, mid, aa, bb), 
  B = get_min(2 * v + 1, mid + 1, r, aa, bb);
  if (a[A] < a[B]) {
    return A;
  }
  return B;
}

int n;

int get2(int l, int r) {
  if (l > r) {
    return 0;
  }
  int pos = get_min(1, 1, 2 * n, l, r);
  return 1 + max(get2(l, pos - 1), get2(pos + 1, r));
}

pair<int, int> get(int l, int r) {
  int pos = get_min(1, 1, 2 * n, l, r);
  return {get2(l, pos - 1), get2(pos + 1, r)};
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int pos;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      pos = i;
    }
  }
  int ptr = 0;
  for (int i = pos + 1; i <= n; i++) {
    a2[++ptr] = a[i];
  }  
  for (int i = 1; i <= pos; i++) {
    a2[++ptr] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a2[i];
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    a[i] = a[i - n];
  }
  a[0] = n + 1;
  build(1, 1, 2 * n);
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    pair<int, int> res = get(1 + mid, n + mid);
    if (res.F >= res.S) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  pair<int, int> res1 = get(1 + l, n + l), 
  res2 = get(1 + r, n + r);
  if (max(res1.F, res1.S) <= max(res2.F, res2.S)) {
    cout << max(res1.F, res1.S) + 1 << ' ' << (l + pos) % n << '\n'; 
  }
  else {
    cout << max(res2.F, res2.S) + 1 << ' ' << (r + pos) % n << '\n';
  }
}