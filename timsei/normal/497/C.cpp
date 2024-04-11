#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct R {
  int l, r, id;
  friend bool operator < (R a, R b) {
    return a.l < b.l;
  }
}A[N], B[N];

int n, cnt[N], m, ans[N];

typedef pair <int, int> pii;

set < pii > S;

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) scanf("%d%d", &A[i].l, &A[i].r), A[i].id = i;
  cin >> m;
  for(int i = 1; i <= m; ++ i) scanf("%d%d%d", &B[i].l, &B[i].r, &cnt[i]), B[i].id = i;
  sort(A + 1, A + n + 1);
  sort(B + 1, B + m + 1);
  int cur = 1;
  for(int i = 1; i <= n; ++ i) {
    while(cur <= m && B[cur].l <= A[i].l) {
      S.insert(make_pair(B[cur].r, B[cur].id));
      ++ cur;
    }
    set < pii > :: iterator it =
      S.lower_bound(make_pair(A[i].r, 0));
    if(it == S.end()) {
      return 0 * puts("NO");
    }
    pii cxt = *it;
    ans[A[i].id] = cxt.second;
    S.erase(cxt);
    if(-- cnt[cxt.second] >= 1) S.insert(cxt);
  }
  puts("YES");
  for(int i = 1; i <= n; ++ i) printf("%d ", ans[i]);
}