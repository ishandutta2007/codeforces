#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int TN = (100000 << 2) + 50;

int l[TN], r[TN], lc[TN], rc[TN], n, m, top;
long long a[TN], sum[TN][30], sum2[TN][8], suma[8], sums[30], ans, cnt[7][14];

void renew(const int i) {
  int sl = (r[lc[i]] - l[lc[i]] + 1) % 30;
  for (int j = 0; j < 30; ++j) sum[i][j] = sum[lc[i]][j] + sum[rc[i]][(j + 30 - sl) % 30];    
  sl = (r[lc[i]] - l[lc[i]] + 1) % 8;
  for (int j = 0; j < 8; ++j) sum2[i][j] = sum2[lc[i]][j] + sum2[rc[i]][(j + 8 - sl) % 8];    
}

void buildtree(const int i, const int left, const int right) {
  l[i] = left; r[i] = right;
  sum[i][1] = a[l[i]];
  sum2[i][1] = a[l[i]];
  if (l[i] == r[i]) {
    lc[i] = rc[i] = 0;
    return;
  }
  int k = (l[i] + r[i]) / 2;
  ++top; lc[i] = top;
  buildtree(lc[i], left, k);
  ++top; rc[i] = top;
  buildtree(rc[i], k + 1, right);
  renew(i);
}

void change(const int i, const int pos, const long long val) {
  if (l[i] == r[i]) {
    sum[i][1] = val;
    sum2[i][1] = val;
    return;
  }
  int k = (l[i] + r[i]) / 2;
  if (pos > k) change(rc[i], pos, val); else change(lc[i], pos, val);
  renew(i);
}

void getsum(const int i, const int left, const int right) {
  if (left <= l[i] && r[i] <= right) {
    int sl = (l[i] - left) % 30;
    for (int j = 0; j < 30; ++j) sums[j] += sum[i][(j + 30 - sl) % 30];    
    sl = (l[i] - left) % 8;
    for (int j = 0; j < 8; ++j) suma[j] += sum2[i][(j + 8 - sl) % 8];    
    return ;
  }
  int k = (l[i] + r[i]) / 2;
  if (right <= k) {
    getsum(lc[i], left, right);
  } else if (left > k) {
    getsum(rc[i], left, right);
  } else {
    getsum(lc[i], left, right);
    getsum(rc[i], left, right);
  }
}

long long getsum(const int z) {
  //for (int i = 0; i < 30; ++i) printf("%d %I64d %I64d\n", i, sums[i], cnt[z][i % (2 * z - 2)]);
  long long ret = 0;
  if (z == 3 || z == 5) {
    for (int i = 0; i < 8; ++i) {
      ret += suma[i] * cnt[z][i % (2 * z - 2)];
    }
  } else { 
    for (int i = 0; i < 30; ++i) {
      ret += sums[i] * cnt[z][i % (2 * z - 2)];
    }
  }
  return ret;
}

int main() {
  cnt[2][1] = 1; cnt[2][0] = 2;
  cnt[3][1] = 1; cnt[3][2] = 2; cnt[3][3] = 3; cnt[3][0] = 2;
  cnt[4][1] = 1; cnt[4][2] = 2; cnt[4][3] = 3; cnt[4][4] = 4; cnt[4][5] = 3; cnt[4][0] = 2;
  cnt[5][1] = 1; cnt[5][2] = 2; cnt[5][3] = 3; cnt[5][4] = 4; cnt[5][5] = 5; cnt[5][6] = 4; cnt[5][7] = 3; cnt[5][0] = 2;
  cnt[6][1] = 1; cnt[6][2] = 2; cnt[6][3] = 3; cnt[6][4] = 4; cnt[6][5] = 5; cnt[6][6] = 6; cnt[6][7] = 5; cnt[6][8] = 4; cnt[6][9] = 3; cnt[6][0] = 2;
  
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  top = 1;
  buildtree(1, 1, n);
  scanf("%d", &m);
  int tag, t1, l, r, z; long long tll;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &tag);
    if (tag == 1) {
      scanf("%d %I64d", &t1, &tll);
      change(1, t1, tll);
    } else {
      scanf("%d %d %d", &l, &r, &z);
      memset(sums, 0, sizeof(sums));
      memset(suma, 0, sizeof(suma));
      getsum(1, l, r);
      ans = getsum(z);
      printf("%I64d\n", ans);
    }
  }
  return 0;
}