#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define LL long long
#define st first
#define nd second
#define endl '\n'
using namespace std;

const int INF = 1e9, NINF = -1e9;

struct min_segment_tree {
    struct data {
        int val = INF;
        int idx = -1;
    };
  struct operation {
    int k = 0;
  };
  static data combine(data dl, data dr) {
    data ret;
    if(dl.val < dr.val) {
        ret = dl;
    }
    else {
        ret = dr;
    }
    return ret;
  }
  static data calculate(operation o, data d) {
    return d;
  }
  static operation merge(operation ot, operation ob) {
    return operation();
  }
  int n, h;
  vector<data> t;
  vector<operation> o;
  min_segment_tree(int n = 0) : n(n), h(32 - __builtin_clz(n)), t(2 * n), o(n) {}
  min_segment_tree(vector<data> & a) : min_segment_tree(a.size()) {
    for (int i = 0; i < n; i++)
      t[i + n] = a[i];
    for (int x = n - 1; x > 0; x--)
      t[x] = combine(t[x << 1], t[x << 1 | 1]);
  }
  void apply(int x, operation op) {
    t[x] = calculate(op, t[x]);
    if (x < n)
      o[x] = merge(op, o[x]);
  }
  void push(int x) {
    for (int s = h; s > 0; s--) {
      int c = x >> s;
      apply(c << 1, o[c]);
      apply(c << 1 | 1, o[c]);
      o[c] = operation();
    }
  }
  void build(int x) {
    while (x >>= 1)
      t[x] = calculate(o[x], combine(t[x << 1], t[x << 1 | 1]));
  }
  // set the data at the position i
  void setValue(int i, data d) {
    i += n;
    push(i);
    t[i] = d;
    build(i);
  }
  // query the data on the range [l, r[
  data query(int l, int r) {
    l += n; r += n;
    push(l); push(r - 1);
    data dl, dr;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        dl = combine(dl, t[l++]);
      if (r & 1)
        dr = combine(t[--r], dr);
    }
    return combine(dl, dr);
  }
  // apply an operation on the range [l, r[
  void apply(int l, int r, operation op) {
    l += n; r += n;
    push(l); push(r - 1);
    int xl = l, xr = r;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        apply(l++, op);
      if (r & 1)
        apply(--r, op);
    }
    build(xl); build(xr - 1);
  }
};

struct max_segment_tree {
    struct data {
        int val = NINF;
        int idx = -1;
    };
  struct operation {
    int k = 0;
  };
  static data combine(data dl, data dr) {
    data ret;
    if(dl.val > dr.val) {
        ret = dl;
    }
    else {
        ret = dr;
    }
    return ret;
  }
  static data calculate(operation o, data d) {
    return d;
  }
  static operation merge(operation ot, operation ob) {
    return operation();
  }
  int n, h;
  vector<data> t;
  vector<operation> o;
  max_segment_tree(int n = 0) : n(n), h(32 - __builtin_clz(n)), t(2 * n), o(n) {}
  max_segment_tree(vector<data> & a) : max_segment_tree(a.size()) {
    for (int i = 0; i < n; i++)
      t[i + n] = a[i];
    for (int x = n - 1; x > 0; x--)
      t[x] = combine(t[x << 1], t[x << 1 | 1]);
  }
  void apply(int x, operation op) {
    t[x] = calculate(op, t[x]);
    if (x < n)
      o[x] = merge(op, o[x]);
  }
  void push(int x) {
    for (int s = h; s > 0; s--) {
      int c = x >> s;
      apply(c << 1, o[c]);
      apply(c << 1 | 1, o[c]);
      o[c] = operation();
    }
  }
  void build(int x) {
    while (x >>= 1)
      t[x] = calculate(o[x], combine(t[x << 1], t[x << 1 | 1]));
  }
  // set the data at the position i
  void setValue(int i, data d) {
    i += n;
    push(i);
    t[i] = d;
    build(i);
  }
  // query the data on the range [l, r[
  data query(int l, int r) {
    l += n; r += n;
    push(l); push(r - 1);
    data dl, dr;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        dl = combine(dl, t[l++]);
      if (r & 1)
        dr = combine(t[--r], dr);
    }
    return combine(dl, dr);
  }
  // apply an operation on the range [l, r[
  void apply(int l, int r, operation op) {
    l += n; r += n;
    push(l); push(r - 1);
    int xl = l, xr = r;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        apply(l++, op);
      if (r & 1)
        apply(--r, op);
    }
    build(xl); build(xr - 1);
  }
};



int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        --a; --b;
        vector<int> p(n);
        vector<max_segment_tree::data> c(n);
        vector<min_segment_tree::data> d(n);
        for(int i = 0; i < n; ++i) {
            cin >> p[i];
            c[i].val = i + p[i];
            d[i].val = i - p[i];
            c[i].idx = d[i].idx = i;
            if(i == a) {
                c[i].val = NINF;
                d[i].val = INF;
            }
        }
        min_segment_tree min_seg = min_segment_tree(d);
        max_segment_tree max_seg = max_segment_tree(c);
        int dis[n];
        memset(dis, -1, sizeof(dis));
        dis[a] = 0;
        queue<int> q;
        q.push(a);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            //cout << "TEST: " << t << " curnode: " << x << endl;
            for(min_segment_tree::data dt; (dt = min_seg.query(x, min(x + p[x] + 1, n))).val <= x; ) {
                //cout << "RIGHT " << " " << dt.idx << " " << dt.val << endl;
                dis[dt.idx] = dis[x] + 1;
                q.push(dt.idx);
                min_seg.setValue(dt.idx, min_segment_tree::data{INF, dt.idx});
                max_seg.setValue(dt.idx, max_segment_tree::data{NINF, dt.idx});
            }
            //cout << "RIGHT CAN NOT : " << min_seg.query(x, min(x + p[x] + 1, n)).idx << " " << min_seg.query(x, min(x + p[x] + 1, n)).val << endl;
            //cout << "range " << x << " " << min(x + p[x] + 1, n) << endl;
            for(max_segment_tree::data dt; (dt = max_seg.query(max(x - p[x], 0), x)).val >= x; ) {
                //cout << "LEFT " << " " << dt.idx << " " << dt.val << endl;
                dis[dt.idx] = dis[x] + 1;
                q.push(dt.idx);
                min_seg.setValue(dt.idx, min_segment_tree::data{INF, dt.idx});
                max_seg.setValue(dt.idx, max_segment_tree::data{NINF, dt.idx});
            }
        }
        cout << dis[b] << endl;
    }

}