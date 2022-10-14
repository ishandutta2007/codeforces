#include <bits/stdc++.h>

using namespace std;

const int N = 123456;
const int M = 20 * N;

int a[N];
int x[M], y[M], z[M];
int nxt, ls[M], rs[M];
int root[N];
               
void modify(int p, int& c, int l, int r, int xx) {
  c = ++nxt; ls[c] = ls[p]; rs[c] = rs[p];
  if (l == r) {
    x[c] = 1;
    y[c] = 1;
    z[c] = 1; 
    return;
  }
  int mid = l + r >> 1;
  if (xx <= mid) modify(ls[p], ls[c], l, mid, xx);
  else modify(rs[p], rs[c], mid + 1, r, xx);
  x[c] = max({x[ls[c]], x[rs[c]], z[ls[c]] + y[rs[c]]});
  y[c] = (y[ls[c]] == mid - l + 1 ? y[ls[c]] + y[rs[c]] : y[ls[c]]);
  z[c] = (z[rs[c]] == r - mid ? z[rs[c]] + z[ls[c]] : z[rs[c]]);
}

tuple<int, int, int> get(int c, int l, int r, int ll, int rr) {
  if (l > r || l > rr || r < ll) return {0, 0, 0};
  if (ll <= l && r <= rr) return {x[c], y[c], z[c]};
  int mid = l + r >> 1;
  auto L = get(ls[c], l, mid, ll, rr);
  auto R = get(rs[c], mid + 1, r, ll, rr);
  tuple<int, int, int> ret;
  get<0>(ret) = max({get<0>(L), get<0>(R), get<2>(L) + get<1>(R)});
  get<1>(ret) = (get<1>(L) == mid - l + 1 ? get<1>(L) + get<1>(R) : get<1>(L));
  get<2>(ret) = (get<2>(R) == r - mid ? get<2>(R) + get<2>(L) : get<2>(R));
  return ret;    
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }                  
  vector<int> a_order(n);
  iota(a_order.begin(), a_order.end(), 0);
  sort(a_order.begin(), a_order.end(), [&](int i, int j){ return a[i] > a[j]; });
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      root[i] = root[i - 1];
    }
    modify(root[i], root[i], 0, n - 1, a_order[i]);
  }        
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, w;
    scanf("%d%d%d", &l, &r, &w);
    --l, --r; 
    int low = 0, top = n - 1, ans = 0;
    while (low <= top) {
      int mid = low + top >> 1;
      if (get<0>(get(root[mid], 0, n - 1, l, r)) >= w) {
        ans = mid;
        top = mid - 1;   
      } else {
        low = mid + 1;
      }
    }
    printf("%d\n", a[a_order[ans]]);
  }
  return 0;
}