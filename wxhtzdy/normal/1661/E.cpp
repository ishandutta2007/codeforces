#include <bits/stdc++.h>                      

using namespace std;

const int N = 500005;
const int M = 4 * N;

int a[3][N];

struct node {
  int comps = 0;
  int lval[3];
  int rval[3];
  int lid[3];
  int rid[3];
  node() {
    for (int i = 0; i < 3; i++) {
      lval[i] = 0;
      rval[i] = 0;
      lid[i] = 0;
      rid[i] = 0;
    }
  }
};

node st[M];

node operator + (node l, node r) {
  if (l.lval[0] == -1) {
    return r;
  }
  if (r.lval[0] == -1) {
    return l;
  }
  node ret;             
  ret.comps = l.comps + r.comps;
  for (int i = 0; i < 3; i++) {
    ret.lval[i] = l.lval[i];
    ret.rval[i] = r.rval[i];
  }
  for (int i = 0; i < 3; i++) {
    r.lid[i] += 6;
    r.rid[i] += 6;
  }
  for (int i = 0; i < 3; i++) {
    if (l.rval[i] == 1 && r.lval[i] == 1 && l.rid[i] != r.lid[i]) {
      ret.comps -= 1;
      int idx = r.lid[i];
      for (int j = 0; j < 3; j++) {
        if (l.rid[j] == idx) {
          l.rid[j] = l.rid[i];
        }
        if (l.lid[j] == idx) {
          l.lid[j] = l.rid[i];
        }
        if (r.rid[j] == idx) {
          r.rid[j] = l.rid[i];
        }
        if (r.lid[j] == idx) {
          r.lid[j] = l.rid[i];
        }
      }
    }
  }
  vector<int> val(12, -1);
  int vv = 0;
  for (int i = 0; i < 3; i++) {
    if (val[l.lid[i]] == -1) {
      val[l.lid[i]] = vv++;
    }
    if (val[r.rid[i]] == -1) {
      val[r.rid[i]] = vv++;
    }
    ret.lid[i] = val[l.lid[i]];
    ret.rid[i] = val[r.rid[i]];
  }
  return ret;
}

void build(int i, int l, int r) {
  if (l == r) {
    for (int j = 0; j < 3; j++) {
      st[i].lval[j] = a[j][l];
      st[i].rval[j] = a[j][l];
    }
    int cc = 0;
    if (a[0][l] == 1) {
      st[i].lid[0] = cc++;
    }
    if (a[1][l] == 1) {
      if (a[0][l] == 1) {
        st[i].lid[1] = st[i].lid[0];
      } else {
        st[i].lid[1] = cc++;
      }
    }
    if (a[2][l] == 1) {
      if (a[1][l] == 1) {
        st[i].lid[2] = st[i].lid[1];
      } else {
        st[i].lid[2] = cc++;
      }
    }                    
    for (int j = 0; j < 3; j++) {
      st[i].rid[j] = st[i].lid[j];
    }
    st[i].comps = cc;
    return;  
  }
  int mid = l + r >> 1;
  build(i + i, l, mid);
  build(i + i + 1, mid + 1, r);
  st[i] = st[i + i] + st[i + i + 1];
}

node get(int i, int l, int r, int ll, int rr) {
  if (l > r || l > rr || r < ll) {
    node ret;
    ret.lval[0] = -1;
    return ret;
  }
  if (ll <= l && r <= rr) {
    return st[i];
  }
  int mid = l + r >> 1;
  return get(i + i, l, mid, ll, rr) + get(i + i + 1, mid + 1, r, ll, rr);
}  

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = (int) (s[j] - '0');
    }
  }
  build(1, 0, n - 1);         
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << get(1, 0, n - 1, l, r).comps << '\n';
  }                                                                  
  return 0;
}