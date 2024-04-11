/**                                             
 *    author:  wxhtzdy
 *    created: 29.05.2022 19:48:54
**/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
const long long inf = 1e18;

int n, dx[MAX][2], dy[MAX][2];

struct node {
  int l, r;
  long long f[2][2];  
};

node st[4 * MAX];

node operator + (node ls, node rs) {
  node res;           
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      res.f[i][j] = inf;
    }
  }
  res.l = ls.l;
  res.r = rs.r;
  assert(ls.r == rs.l - 1);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int p = 0; p < 2; p++) {
          int x = dx[ls.r][j] + (j == 0);
          int y = dy[ls.r][j] + (j == 1);
          long long dist = abs(x - dx[rs.l][k]) + abs(y - dy[rs.l][k]);
          res.f[i][p] = min(res.f[i][p], ls.f[i][j] + rs.f[k][p] + dist + 1);
        }
      }
    }
  }
  return res;
}

void build(int node, int l, int r) {
  if (l == r) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {   
        st[node].f[i][j] = abs(dx[l][i] - dx[l][j]) + abs(dy[l][i] - dy[l][j]);
      }
    }     
    st[node].l = l;
    st[node].r = r;
    return;  
  }
  int mid = l + r >> 1;
  build(node + node, l, mid);
  build(node + node + 1, mid + 1, r);
  st[node] = st[node + node] + st[node + node + 1];
}           

node get(int node, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return st[node];
  }
  int mid = l + r >> 1;
  if (rr <= mid) {
    return get(node + node, l, mid, ll, rr);
  } else if (ll > mid) {
    return get(node + node + 1, mid + 1, r, ll, rr);
  } else {
    return get(node + node, l, mid, ll, rr) + get(node + node + 1, mid + 1, r, ll, rr);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  cin >> n;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> dx[i][j] >> dy[i][j];
    }
  }   
  build(1, 1, n - 1);
  int q;
  cin >> q;
  while (q--) {   
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int c1 = max(x1, y1);
    int c2 = max(x2, y2);
    if (c1 == c2) {
      cout << abs(x1 - x2) + abs(y1 - y2) << '\n';
      continue;
    }
    if (c1 > c2) {
      swap(x1, x2);
      swap(y1, y2);
      swap(c1, c2);
    }
    node r = get(1, 1, n - 1, c1, c2 - 1);
    long long ans = inf;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        int x = dx[c2 - 1][j] + (j == 0);
        int y = dy[c2 - 1][j] + (j == 1);
        long long dist = abs(x1 - dx[c1][i]) + abs(y1 - dy[c1][i]) + abs(x2 - x) + abs(y2 - y);
        ans = min(ans, r.f[i][j] + dist + 1);
      }
    }
    cout << ans << '\n';
  }                                                                                 
  return 0;
}