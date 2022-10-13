#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, int, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 400005;
//> = 1, < = 0, f = inwards, s = outwards
struct Node { 
  int pref[3], suf[3], ans[2];
  int len;
};

Node null() {
  Node ret;
  ret.pref[0] = 0, ret.pref[1] = 0, ret.pref[2] = 0;
  ret.suf[0] = 0, ret.suf[1] = 0, ret.suf[2] = 0;
  ret.ans[0] = 0, ret.ans[1] = 0;
  ret.len = 1;
  return ret;
}

Node merge(Node x, Node y) {
  Node ret = null();
  ret.len = x.len + y.len;
  ret.pref[0] = x.pref[0];
  ret.pref[1] = x.pref[1];
  ret.pref[2] = x.pref[2];
  if(x.pref[0] == x.len) {
    if(y.pref[2] == x.pref[2]) {
      ret.pref[0] += y.pref[0];
      ret.pref[1] += y.pref[1];
    }
    else ret.pref[1] += y.pref[0];
  }
  else if(x.pref[1] == x.len) {
    if(y.pref[2] != x.pref[2]) {
      ret.pref[1] += y.pref[0];
    }
  }
  ret.suf[0] = y.suf[0];
  ret.suf[1] = y.suf[1];
  ret.suf[2] = y.suf[2];
  if(y.suf[0] == y.len) {
    if(x.suf[2] == y.suf[2]) {
      ret.suf[0] += x.suf[0];
      ret.suf[1] += x.suf[1];
    }
    else ret.suf[1] += x.suf[0];
  }
  else if(y.suf[1] == y.len) {
    if(x.suf[2] != y.suf[2]) {
      ret.suf[1] += x.suf[0];
    }
  }
  ret.ans[0] = max(x.ans[0], y.ans[0]);
  ret.ans[1] = max(x.ans[1], y.ans[1]);
  if(x.suf[2] == y.pref[2]) {
    //<<<>>>>>|>>>>><<<
    if(x.suf[2] == 1) {
      ret.ans[0] = max(ret.ans[0], x.suf[0] + y.pref[1]);
      ret.ans[1] = max(ret.ans[1], y.pref[0] + x.suf[1]);
    }
    //<<<<|<<<>>
    else {
      ret.ans[0] = max(ret.ans[0], y.pref[0] + x.suf[1]);
      ret.ans[1] = max(ret.ans[1], x.suf[0] + y.pref[1]);
    }
  }
  else {
    //>>>>|<<<
    if(x.suf[2] == 1) {
      ret.ans[0] = max(ret.ans[0], x.suf[0] + y.pref[0]);
    }
    //<<<<|>>>
    else {
      ret.ans[1] = max(ret.ans[1], x.suf[0] + y.pref[0]);
    }
  }
  return ret;
}

void flip(Node &x) {
  int temp = x.ans[0];
  x.ans[0] = x.ans[1];
  x.ans[1] = temp;
  x.suf[2] ^= 1;
  x.pref[2] ^= 1;
}

struct seg_tree {
  vector<Node> seg;
  vector<int> lazy;
  int sz;
  void build(int x, int lx, int rx, string &s) {
    if(rx - lx == 1) {
      if(lx < s.length()) {
        seg[x].ans[0] = 1, seg[x].ans[1] = 1;
        seg[x].pref[0] = 1, seg[x].pref[1] = 1, seg[x].suf[0] = 1, seg[x].suf[1] = 1;
        seg[x].pref[2] = (s[lx] == '>'), seg[x].suf[2] = (s[lx] == '>');
        seg[x].len = 1;
      }
      else seg[x] = null();
      return;
    }
    int m = (lx + rx)/2;
    build(2*x+1, lx, m, s), build(2*x+2, m, rx, s);
    seg[x] = merge(seg[2*x+1], seg[2*x+2]);
  }
  void init(int n, string s) {
    sz = 1;
    while(sz < n) sz *= 2;
    seg.resize(2*sz);
    lazy.resize(2*sz);
    build(0, 0, sz, s);
  }
  void push(int x, int lx, int rx) {
    flip(seg[x]);
    if(rx-lx!=1) {
      lazy[2*x+1] ^= 1;
      lazy[2*x+2] ^= 1;
    }
  }
  void prop(int x, int lx, int rx) {
    if(lazy[x]) push(x, lx, rx);
    lazy[x] = 0;
  }
  void upd(int l, int r, int x, int lx, int rx) {
    prop(x, lx, rx);
    if(rx <= l || lx >= r) return;
    if(lx >= l && rx <= r) {
      push(x, lx, rx);
      return;
    }
    int m = (lx + rx)/2;
    upd(l, r, 2*x+1, lx, m), upd(l, r, 2*x+2, m, rx);
    seg[x] = merge(seg[2*x+1], seg[2*x+2]);
  }
  void upd(int l, int r) { upd(l, r, 0, 0, sz); }
  Node query(int l, int r, int x, int lx, int rx) {
    prop(x, lx, rx);
    if(rx <= l || lx >= r) return null();
    if(lx >= l && rx <= r) return seg[x];
    int m = (lx+rx)/2;
    return merge(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
  }
  int query(int l, int r) {
    Node ans = query(l, r, 0, 0, sz);
    return ans.ans[0];
  }
  int get(int i, int x, int lx, int rx) {
    prop(x, lx, rx);
    if(rx - lx == 1) {
      if(seg[x].pref[2]) return 1;
      else return 0;
    }
    int m = (lx+rx)/2;
    if(i<m) return get(i, 2*x+1, lx, m);
    else return get(i, 2*x+2, m, rx);
  }
  int get(int i) { return get(i, 0, 0, sz); }
} in;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q; cin >> n >> q;
  string s; cin >> s;
  in.init(n, s);
  while(q--) {
    int l, r; cin >> l >> r;
    --l;
    in.upd(l, r);
    cout << in.query(l, r) << "\n";
  }
}