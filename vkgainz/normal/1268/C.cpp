#include <bits/stdc++.h>
using namespace std;

struct seg_tree {
  vector<long long> seg;
  vector<int> med;
  int num_in;
  int sz;
  
  void init(int n) {
    sz = 1;
    while(sz < n)
      sz *= 2;
    seg.resize(2 * sz, 0LL);
    med.resize(2 * sz, 0);
    num_in = 0;
  }

  void upd(int i, int v, int x, int lx, int rx) {
    if(rx - lx == 1) {
      seg[x] = v;
      med[x] = 1;
      ++num_in;
      return;
    }

    int m = (lx + rx) / 2;
    if(i < m) upd(i, v, 2 * x + 1, lx, m);
    else upd(i, v, 2 * x + 2, m, rx);
    
    seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    med[x] = med[2 * x + 1] + med[2 * x + 2];
  }
  
  void upd(int i, int v) { upd(i, v, 0, 0, sz); }

  long long query(int l, int r, int x, int lx, int rx) {
    if(lx >= r || rx <= l) return 0LL;

    if(lx >= l && rx <= r) return seg[x];
    
    int m = (lx + rx) / 2;
    return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
  }

  long long query(int l, int r) { return query(l, r, 0, 0, sz); }

  int find_kth(int k, int x, int lx, int rx) {
    if(rx - lx == 1) return lx;

    int m = (lx + rx) / 2;
    if(med[2 * x + 1] <= k) return find_kth(k - med[2 * x + 1], 2 * x + 2, m, rx);
    return find_kth(k , 2 * x + 1, lx, m);
  }

  int find_median() { return find_kth((num_in + 1) / 2 - 1, 0, 0, sz); }

  int query_more(int l, int r, int x, int lx, int rx) {
    if(lx >= r || rx <= l) return 0;
    
    if(lx >= l && rx <= r) return med[x];

    int m = (lx + rx) / 2;
    return query_more(l, r, 2 * x + 1, lx, m) + query_more(l, r, 2 * x + 2, m, rx);
  }

  int query_more(int l, int r) { return query_more(l, r, 0, 0, sz); }

};

int main() {
  int n; cin >> n;
  
  vector<int> p(n), ord(n);
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    ord[--p[i]] = i;
  }

  seg_tree in;
  in.init(n);

  vector<long long> ans(n);
  long long inv = 0LL;
  for(int i = 0; i < n; i++) {
    inv += in.query_more(ord[i], n);
    in.upd(ord[i], ord[i]);
    
    int med = in.find_median();
    int left = i / 2, right = (i + 1) / 2;
    ans[i] = inv - in.query(0, med) + in.query(med + 1, n) + (2 * med - left - 1) * 1LL * left / 2 - (2 * med + right + 1) * 1LL * right / 2;
  }

  for(int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";

}