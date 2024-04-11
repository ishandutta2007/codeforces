#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
const int M = 3e4 + 5;
const int Segment_Size = M * 4;

#define lc (no << 1)
#define rc (no << 1 | 1)
#define getmid int mid = (L[no] + R[no]) >> 1

int L[Segment_Size], R[Segment_Size], n, k, ty, x, y, z, val[N], w[N], q, Tl[N], Tr[N], top;
bool Q[M];
int dp[105][1005];

void build(int no, int l, int r) {
  L[no] = l, R[no] = r;
  if(l == r) return;
  getmid;
  build(lc, l, mid);
  build(rc, mid + 1, r);
}

vector <int> who[Segment_Size];

void add(int no, int l, int r, int w) {
  if(L[no] == l && R[no] == r) {
    who[no].push_back(w);
    return;
  }
  getmid;
  if(l > mid) add(rc, l, r, w);
  else if(r <= mid) add(lc, l, r, w);
  else add(lc, l, mid, w), add(rc, mid + 1, r, w);
}

const int Base = 1e7 + 19;
const int mod = 1e9 + 7;

void dfs(int no) {
  ++ top;
  for(int i = 1; i <= k; ++ i) dp[top][i] = dp[top - 1][i];
  for(int i = 0; i < (int) who[no].size(); ++ i) {
    int W = w[who[no][i]], V = val[who[no][i]];
    for(int j = k - W; j >= 0; -- j)
      dp[top][j + W] = max(dp[top][j + W], dp[top][j] + V);
  }
  if(L[no] == R[no]) {
    if(!Q[L[no]]) {
      -- top;
      return;
    }
    int ans = 0, now = 1;
    for(int i = 1; i <= k; ++ i) {
      ans = (ans + 1LL * now * dp[top][i] % mod) % mod;
      now = 1LL * now * Base % mod;
    }
    printf("%d\n", ans);
    -- top;
    return;
  }
  dfs(lc); dfs(rc);
  -- top;
}

int main() {
  cin >> n >> k;
  for(int i = 1; i <= n; ++ i)
    scanf("%d%d", &val[i], &w[i]), Tl[i] = 1;
  cin >> q;
  build(1, 1, q);
  for(int i = 1; i <= q; ++ i) {
    scanf("%d", &ty);
    if(ty == 1) {
      ++ n;
      scanf("%d%d", &val[n], &w[n]);
      Tl[n] = i;
    }
    else if(ty == 2) {
      scanf("%d", &x);
      Tr[x] = i;
    }
    else if(ty == 3) {
      Q[i] = 1;
    }
  }
  for(int i = 1; i <= n; ++ i) {
    if(!Tr[i]) Tr[i] = q;
    add(1, Tl[i], Tr[i], i);
  }
  dfs(1);
}