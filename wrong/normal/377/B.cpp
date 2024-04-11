#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (b < a) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

const int MAXN = 100050;
int seg_pos[MAXN];

struct bug {
  int id, complexity;
} A[100050];

struct student {
  int id, level, pass;
} S[100050];
bool operator < (const student& a, const student& b) {
  return a.pass < b.pass;
}
student seg_min[4*MAXN];

int worker[100050];
int id_revmap[100050];
int id_to_pass[100050];

void seg_init(int x, int l, int r) {
  if (r - l == 1) {
    seg_min[x] = S[l];
    seg_pos[l] = x;
    return;
  }
  int mid = (l + r) / 2;
  seg_init(2 * x, l, mid);
  seg_init(2 * x + 1, mid, r);
  seg_min[x] = min(seg_min[2 * x], seg_min[2 * x + 1]);
}

student seg_query(int x, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) {
    return seg_min[x];
  }
  int mid = (l + r) / 2;
  student res = {-1, INF, INF};
  if (ql < mid) chmin(res, seg_query(2 * x, l, mid, ql, min(mid, qr)));
  if (qr > mid) chmin(res, seg_query(2*x+1, mid, r, max(mid, ql), qr));
  return res;
}

void seg_update(int pos, int v) {
  seg_min[seg_pos[pos]].pass = v;
  for (int x = seg_pos[pos] / 2; x >= 1; x /= 2) {
    seg_min[x] = min(seg_min[2*x], seg_min[2*x+1]);
  }
}

int main()
{
  int n, m, s;
  scanf("%d%d%d", &n, &m, &s);

  for (int i = 0; i < m; ++i) {
    A[i].id = i;
    scanf("%d", &A[i].complexity);
  }
  sort(A, A + m, [] (const bug& a, const bug& b) {
    return a.complexity < b.complexity;
  });

  for (int i = 0; i < n; ++i) {
    S[i].id = i;
    scanf("%d", &S[i].level);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &S[i].pass);
  }
  sort(S, S + n, [] (const student& a, const student& b) {
    return a.level < b.level;
  });

  for (int i = 0; i < n; ++i) {
    id_revmap[S[i].id] = i;
    id_to_pass[S[i].id] = S[i].pass;
  }

  seg_init(1, 0, n);

  int lo = 0, hi = m + 1;
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;

    vector<int> w_id;
    bool ok = true;
    int cur_cost = 0;
    for (int i = m - 1; i >= 0; i -= mid) {
      student dummy = {-1, A[i].complexity, INF};
      int pos = lower_bound(S, S + n, dummy, [] (const student& a, const student& b) {
        return a.level < b.level;
      }) - S;
      if (pos >= n) {
        ok = false;
        break;
      }

      student w = seg_query(1, 0, n, pos, n);
      if (cur_cost + w.pass > s) {
        ok = false;
        break;
      }
      cur_cost += w.pass;
      w_id.push_back(w.id);
      seg_update(id_revmap[w.id], INF);
    }

    if (ok) {
      hi = mid;
      for (int i = m - 1, p = 0; i >= 0; ++p, i -= mid) {
        for (int j = 0; j < mid && i - j >= 0; ++j) {
          worker[A[i - j].id] = w_id[p] + 1;
        }
      }
    } else {
      lo = mid;
    }

    for (int i = 0; i < w_id.size(); ++i) {
      seg_update(id_revmap[w_id[i]], id_to_pass[w_id[i]]);
    }
  }

  if (hi > m) {
    puts("NO");
  } else {
    puts("YES");
    for (int i = 0; i < m; ++i) {
      printf("%d%c", worker[i], i==m-1 ? '\n' : ' ');
    }
  }

  return 0;
}