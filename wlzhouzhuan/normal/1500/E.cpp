// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
long long read() {
  long long x = 0, f = 0; char ch = getchar();
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

const int N = 800005;

int node_cnt;

struct Fhq_treap {
  // pre: 0 * val[0] + 1 * val[1] + ...
  // suf: 0 * val[n] + 1 * val[n - 1]  
  #define lc node[u].ls
  #define rc node[u].rs
  struct Info {
    ull val, pre, suf, sum;
    ll sz;
    int ls, rs, rnd;
    void print() {
      printf("[Info] %lld %lld %lld %lld %lld\n", val, sz, pre, suf, sum);
    }
  } node[N];
  int root, tot = 0; 
  int newnode(ll num) {
    tot++;
    node[tot].val = num, node[tot].rnd = rand();
    node[tot].sz = 1, node[tot].sum = num, node[tot].pre = node[tot].suf = 0;
    node[tot].ls = node[tot].rs = 0;
    return tot;
  }
  void pushup(int u) {
    node[u].sz = node[lc].sz + node[rc].sz + 1;
    node[u].pre = node[lc].pre + node[rc].pre + node[rc].sum * (node[lc].sz + 1) + node[u].val * node[lc].sz;
    node[u].suf = node[rc].suf + node[lc].suf + node[lc].sum * (node[rc].sz + 1) + node[u].val * node[rc].sz;
    node[u].sum = node[lc].sum + node[rc].sum + node[u].val;
  }
  void split(int u, ll num, int &x, int &y) {
    if (!u) {
      x = y = 0;
      return ;
    }
    if (node[u].val <= num) x = u, split(node[u].rs, num, node[u].rs, y);
    else y = u, split(node[u].ls, num, x, node[u].ls);
    pushup(u);
  }
  void split_sz(int u, int rnk, int &x, int &y) {
    if (!u) {
      x = y = 0;
      return ;
    }
    if (node[lc].sz + 1 <= rnk) x = u, split_sz(node[u].rs, rnk - node[lc].sz - 1, node[u].rs, y);
    else y = u, split_sz(node[u].ls, rnk, x, node[u].ls);
    pushup(u);
  }
  int merge(int x, int y) {
    if (!x || !y) return x + y;
    else {
      if (node[x].rnd < node[y].rnd) {
        node[x].rs = merge(node[x].rs, y);
        pushup(x);
        return x;
      } else {
        node[y].ls = merge(x, node[y].ls);
        pushup(y);
        return y;
      }
    }
  }
  void ins(ll num) {
    int x = 0, y = 0;
    split(root, num, x, y);
    //printf("ins %d %d\n", x, y);
    root = merge(merge(x, newnode(num)), y);
  }
  void del(ll num) {
    int x = 0, y = 0, z = 0;
    split(root, num, x, z);
    split(x, num - 1, x, y);
    y = merge(node[y].ls, node[y].rs);
    root = merge(merge(x, y), z);
  }
  ll getsuf(int rnk) {
    int u = root;
    ll sum = 0;
    while (u && rnk) {
      if (rnk <= node[rc].sz) u = rc;
      else {
        rnk -= node[rc].sz + 1;
        sum += node[rc].sum + node[u].val;
        u = lc;
      }
    }
    return sum;
  }
  ll getpre(int rnk) {
    int u = root;
    ll sum = 0;
    while (u && rnk) {
      if (rnk <= node[lc].sz) u = lc;
      else {
        rnk -= node[lc].sz + 1;
        sum += node[lc].sum + node[u].val;
        u = rc;
      }
    }
    return sum;
  }
  ll getans() {
    if (node_cnt <= 1) return 0;
    ull Lsum = node[root].suf, Rsum = node[root].pre;
    ull ans = Rsum - Lsum;
    int l = 1, r = (node_cnt - 1) / 2 + 1;
    while (l < r) {
      int mid = l + r >> 1;
      ll R = getsuf(mid) - 1;
      ll L = getpre(mid + 1);
      if (R < L) l = mid + 1;
      else r = mid;
    }
    
    if (l == (node_cnt - 1) / 2 + 1) return ans;
    
    r = node_cnt - 1 - l;
    int x = 0, y = 0, z = 0;
    split_sz(root, node_cnt - 1 - r, x, y);
    split_sz(y, r - l + 2, y, z);
    ull Minus = node[y].pre + (r - l + 1) * node[z].sum;
    root = merge(merge(x, y), z);
    split_sz(root, r + 2, x, y);
    split_sz(x, l, x, z);
    Minus -= node[z].suf + (r - l + 1) * node[x].sum;
    root = merge(merge(x, z), y);
    return ans - Minus;
  }
} tr;

int n, q;

int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) {
    ll x = read();
    tr.ins(x);
    node_cnt++; 
    //printf("When i = %d, ans = %lld\n", i, tr.getans());
  }
  print(tr.getans(), '\n');
  while (q--) {
    int opt = read();
    ll x = read();
    if (opt == 1) {
      tr.ins(x);
      node_cnt++;
    } else {
      tr.del(x);
      node_cnt--;
    }
    print(tr.getans(), '\n');
  }
  return 0;
}