#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 200005, TN = 400005, TM = 600005, LM = 1000005, INF = 400000000;
int n, k, l, r, m, seg_wid, seg_wid2, ev_top, p5_top, rec_cnt, x[N], y[N], ds[N], s1[N], s2[N], s3[N], s4[LM], p5[LM], s5[LM], ord_p5[LM], ord[N], xord[N], yord[N], event[LM], times[LM], pri[LM];

struct SegTA {
  int seg_top, l[TN], r[TN], lc[TN], rc[TN], mi[TN];
  void buildtree(const int i, const int left, const int right) {
    l[i] = left; r[i] = right; mi[i] = INF;
    if (l[i] == r[i]) return;
    int k = (l[i] + r[i]) >> 1;
    seg_top++; lc[i] = seg_top; buildtree(lc[i], left, k);
    seg_top++; rc[i] = seg_top; buildtree(rc[i], k + 1, right);
  }
  void init(const int seg_wid) {
    seg_top = 1;
    buildtree(1, 1, seg_wid);
  }
  void change(const int i, const int pos, const int val) {
    if (l[i] == pos && r[i] == pos) {
      mi[i] = val;
      return ;
    }
    int k = (l[i] + r[i]) >> 1;
    if (pos > k) change(rc[i], pos, val); else change(lc[i], pos, val);
    mi[i] = min(mi[lc[i]], mi[rc[i]]);
  }
  int find(const int i, const int left, const int right) {
    if (l[i] == left && r[i] == right) return mi[i];
    int k = (l[i] + r[i]) >> 1;
    if (left > k) {
      return find(rc[i], left, right);
    } else if (right <= k) {
      return find(lc[i], left, right);
    } else {
      return min(find(lc[i], left, k), find(rc[i], k + 1, right));
    }
  } 
} ul, ur, dl, dr;

bool cmp_p1(int i, int j) {return x[i] < x[j];}
void pro_discr() {
  for (int i = 0; i < n + k; i++) s1[i] = i;
  sort(s1, s1 + n + k, cmp_p1);
  ord[s1[0]] = 1; xord[s1[0]] = 1;
  for (int i = 1; i < n + k; i++) {
    ord[s1[i]] = ord[s1[i - 1]] + 1;
    xord[s1[i]] = (x[s1[i]] == x[s1[i - 1]] ? xord[s1[i - 1]] : ord[s1[i]]);
  }
  yord[s1[n + k - 1]] = n + k - 1;
  for (int i = n + k - 2; i > -1; i--) yord[s1[i]] = (x[s1[i]] == x[s1[i + 1]] ? yord[s1[i + 1]] : ord[s1[i]]);
  seg_wid = ord[s1[n + k - 1]];
}
bool cmp_p2(int i, int j) {return y[i] < y[j] || y[i] == y[j] && x[i] < x[j];}
bool cmp_p3(int i, int j) {return ds[i] > ds[j];}
void cal_metro() {
  for (int i = 0; i < n + k; i++) s2[i] = i;
  sort(s2, s2 + n + k, cmp_p2);
  ul.init(seg_wid); ur.init(seg_wid); dl.init(seg_wid); dr.init(seg_wid);
  for (int i = n; i < n + k; i++) {
    ul.change(1, ord[i], -x[i] + y[i]);
    ur.change(1, ord[i], x[i] + y[i]);
  }
  for (int i = 0; i < n + k; i++) {
    if (s2[i] < n) {
      ds[s2[i]] = INF;
      ds[s2[i]] = min(ds[s2[i]], x[s2[i]] - y[s2[i]] + ul.find(1, 1, yord[s2[i]]));
      ds[s2[i]] = min(ds[s2[i]], -x[s2[i]] - y[s2[i]] + ur.find(1, xord[s2[i]], seg_wid));
      ds[s2[i]] = min(ds[s2[i]], x[s2[i]] + y[s2[i]] + dl.find(1, 1, yord[s2[i]]));
      ds[s2[i]] = min(ds[s2[i]], -x[s2[i]] + y[s2[i]] + dr.find(1, xord[s2[i]], seg_wid));
    } else {
      ul.change(1, ord[s2[i]], INF);
      ur.change(1, ord[s2[i]], INF);
      dl.change(1, ord[s2[i]], -x[s2[i]] - y[s2[i]]);
      dr.change(1, ord[s2[i]], x[s2[i]] - y[s2[i]]);
    }
  }
  for (int i = 0; i < n; i++) s3[i] = i;
  sort(s3, s3 + n, cmp_p3);
  r = min(r, ds[s3[0]]);
}

struct rectan {
  int u, d, l, r;
  bool is_empty() {return u < d || l > r;}
} rect[N];
int radi[N];

struct SegTB {
  int seg_top, l[TN], r[TN], lc[TN], rc[TN], cnt[TN];
  void buildtree(const int i, const int left, const int right) {
    l[i] = left; r[i] = right; cnt[i] = 0;
    if (l[i] == r[i]) return;
    int k = (l[i] + r[i]) >> 1;
    seg_top++; lc[i] = seg_top; buildtree(lc[i], left, k);
    seg_top++; rc[i] = seg_top; buildtree(rc[i], k + 1, right);
  }
  void init(const int seg_wid) {
    seg_top = 1;
    buildtree(1, 1, seg_wid);
  }
  void change(const int i, const int left, const int right, const int val) {
    if (l[i] == left && r[i] == right) {
      cnt[i] += val;
      return ;
    }
    int k = (l[i] + r[i]) >> 1;
    if (left > k) {
      change(rc[i], left, right, val);
    } else if (right <= k) {
      change(lc[i], left, right, val);
    } else {
      change(lc[i], left, k, val);
      change(rc[i], k + 1, right, val);
    }
  }
  bool query(const int i, const int pos) {
    if (cnt[i]) return true;
    if (l[i] == r[i]) return false;
    return (pos > (l[i] + r[i]) >> 1) ? query(rc[i], pos) : query(lc[i], pos);
  } 
} rt;

rectan merge(const rectan a, const rectan b) {
  rectan c;
  c.u = min(a.u, b.u);
  c.d = max(a.d, b.d);
  c.l = max(a.l, b.l);
  c.r = min(a.r, b.r);
  return c;
}
void empi(const int i, const int rad) {
  rect[i].u += rad;
  rect[i].d -= rad;
  rect[i].l -= rad;
  rect[i].r += rad;  
}
rectan mak_squar(const int i, const int rad) {
  rectan ret;
  ret.u = x[i] + y[i] + rad;
  ret.d = x[i] + y[i] - rad;
  ret.l = x[i] - y[i] - rad;
  ret.r = x[i] - y[i] + rad;
  return ret;
}
void add_event(const int i) {
  if (i < n) {
    ev_top++; event[ev_top] = i; times[ev_top] = rect[i].d; pri[ev_top] = 1; s4[ev_top] = ev_top;
    ev_top++; event[ev_top] = i; times[ev_top] = rect[i].u; pri[ev_top] = -1; s4[ev_top] = ev_top;
  } else {
    ev_top++; event[ev_top] = i; times[ev_top] = y[i] + x[i]; pri[ev_top] = 0; s4[ev_top] = ev_top;
  }
}
bool cmp_p5(int i, int j) {return p5[i] < p5[j];}
void tmp_discr() {
  p5_top = 0;
  for (int i = 1; i <= rec_cnt; i++) {
    p5[++p5_top] = rect[event[i]].l; s5[p5_top] = p5_top;
    p5[++p5_top] = rect[event[i]].r; s5[p5_top] = p5_top;
  }
  for (int i = rec_cnt + 1; i <= ev_top; i++) {
    p5[++p5_top] = x[event[i]] - y[event[i]]; s5[p5_top] = p5_top;
  }
  sort(s5 + 1, s5 + p5_top + 1, cmp_p5);
  ord_p5[s5[1]] = 1;
  for (int i = 2; i <= p5_top; i++) ord_p5[s5[i]] = ord_p5[s5[i - 1]] + (p5[s5[i]] == p5[s5[i - 1]] ? 0 : 1);
  seg_wid2 = ord_p5[s5[p5_top]];
}
bool cmp_p4(int i, int j) {return times[i] < times[j] || times[i] == times[j] && pri[i] > pri[j];}
bool jug_alive(const int t) {
  int bar = n - 1;
  ev_top = 0; rec_cnt = 0;
  rect[0] = mak_squar(s3[0], t);
  radi[0] = t - ds[s3[1]];
  for (int i = 1; i <= bar; i++) {
    rect[i] = merge(rect[i - 1], mak_squar(s3[i], t));
    radi[i] = t - ds[s3[i + 1]];
    if (radi[i - 1] >= 0) {
      empi(i - 1, radi[i - 1]);
      add_event(i - 1);
      rec_cnt += 2;
    }
    if (rect[i].is_empty()) bar = i - 1;
  }
  if (bar == n - 1) return true;
  if (!rec_cnt) return false;
  for (int i = n; i < n + k; i++) add_event(i);
  sort(s4 + 1, s4 + ev_top + 1, cmp_p4);
  tmp_discr();
  rt.init(seg_wid2);
  for (int i = 1; i <= ev_top; i++) {
    if (pri[s4[i]]) {
      rt.change(1, ord_p5[s4[i] * 2 - 1], ord_p5[s4[i] * 2], pri[s4[i]]);
    } else {
      if (rt.query(1, ord_p5[s4[i] + rec_cnt])) return true;
    }
  }
  return false;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n + k; i++) scanf("%d %d", &x[i], &y[i]);
  pro_discr();
  l = 0; r = (n == 1) ? 0 : 200000000;
  if (k) cal_metro(); else for (int i = 0; i < n; i++) s3[i] = i;
  while (r - l > 1) {
    m = (l + r) >> 1;
    if (jug_alive(m)) r = m; else l = m;
  }
  printf("%d\n", r);
  return 0;
}