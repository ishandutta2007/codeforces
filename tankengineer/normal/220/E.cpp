#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, a[N], b[N], ord[N];
long long k, sum, ans;

struct trry {
  int n, tr[N];
  
  inline int lowbit(const int i) {return (i & -i);}

  void clear(int i) {
    n = i;
    memset(tr, 0, sizeof(tr));
  }

  void insert(const int pos, const int delta) {
    int s = pos;
    while (s <= n) {
      tr[s] += delta;
      s += lowbit(s);
    }
  }

  int query(const int pos) {
    int s = pos, t = 0;
    while (s) {
      t += tr[s];
      s -= lowbit(s);
    }
    return t;
  }  
} tr1, tr2, tr3;

bool cmp(int i, int j) {return a[i] < a[j];}

int main() {
  scanf("%d %I64d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ord[i] = i;
  }
  sort(ord + 1, ord + n + 1, cmp);
  b[ord[1]] = 1;
  for (int i = 2; i <= n; ++i) {
    b[ord[i]] = a[ord[i - 1]] == a[ord[i]] ? b[ord[i - 1]] : b[ord[i - 1]] + 1; 
  }
  int t1 = b[ord[n]];
  tr1.clear(t1);
  tr2.clear(t1);
  for (int i = 1; i <= n; ++i) {
    sum += i - 1 - tr1.query(b[i]);
    tr1.insert(b[i], 1);
    tr2.insert(b[i], 1);
  }
  tr1.clear(t1);
  int r = 1;
  if (sum <= k) ans += n - 1;
  //printf("%I64d\n", sum);
  tr2.insert(b[1], -1);
  sum -= tr2.query(b[1] - 1);
  //printf("%I64d\n", sum);
  for (int l = 1; l <= n; ++l) {
    while (sum > k && r < n || r < l) {
      ++r;
      tr2.insert(b[r], -1);
      sum -= tr2.query(b[r] - 1) + (l - 1 - tr1.query(b[r]));
      //printf("%d\n", tr2.query(b[r] - 1));
      //printf("%d %d - %I64d\n", l, r, sum);
    }
    //printf("%d %d\n", l, r);
    if (sum > k && r == n) break;
    if (l != 1) ans += n - r;
    sum += l - 1 - tr1.query(b[l]) + tr2.query(b[l] - 1);
    tr1.insert(b[l], 1);
  }
  printf("%I64d\n", ans);
  return 0;
}