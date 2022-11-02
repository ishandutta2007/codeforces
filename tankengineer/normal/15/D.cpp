//15D
#include<cstdio>
#include<deque>
#include<algorithm>

using namespace std;

int n, m, a, b, ma[1005][1005], ans, x[1000005], y[1000005], top, srt[1000005];
long long sum[1005][1005], cost[1000005], mini[1005][1005];
bool use[1000005];
deque<pair<long long, int> > dq;

bool cmp(int i, int j) {return cost[i] < cost[j] || cost[i] == cost[j] && (x[i] < x[j] || x[i] == x[j] && y[i] < y[j]);}

int main() {
  scanf("%d %d %d %d", &n, &m, &a, &b);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &ma[i][j]); 
      mini[i][j] = ma[i][j];
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + ma[i][j];
    }
  }
  
  for (int i = 1; i <= n; i++) {
    dq.clear();
    for (int j = m; j >= 1; j--) {
      while (dq.size() && dq[0].second > j + b - 1) dq.pop_front();
      while (dq.size() && mini[i][j] <= dq.back().first) dq.pop_back();
      dq.push_back(make_pair(mini[i][j], j));
      mini[i][j] = dq[0].first;
    }
  }
  for (int j = 1; j <= m; j++) {
    dq.clear();
    for (int i = n; i >= 1; i--) {
      while (dq.size() && dq[0].second > i + a - 1) dq.pop_front();
      while (dq.size() && mini[i][j] <= dq.back().first) dq.pop_back();
      dq.push_back(make_pair(mini[i][j], i));
      mini[i][j] = dq[0].first;
    }
  }
  
  top = 0;
  for (int i = 1; i + a - 1 <= n; i++) {
    for (int j = 1; j + b - 1 <= m; j++) {
      top++;
      x[top] = i; y[top] = j;
      cost[top] =  sum[i + a - 1][j + b - 1] - sum[i + a - 1][j - 1] - sum[i - 1][j + b - 1] + sum[i - 1][j - 1] - mini[i][j] * a * b;
      srt[top] = top;
    }
  }
  sort(srt + 1, srt + top + 1, cmp);
  
  ans = 0; 
  for (int k = 1; k <= top; k++) {
    if (mini[x[srt[k]]][y[srt[k]]] >= 0) {
      ans++;
      use[srt[k]] = true;
      for (int i = max(1, x[srt[k]] - a + 1); i <= x[srt[k]] + a - 1; i++) {
        for (int j = max(1, y[srt[k]] - b + 1); j <= y[srt[k]] + b - 1; j++) {
          mini[i][j] = -1;
        }
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= top; i++) {
    if (use[srt[i]]) {
      printf("%d %d %I64d\n", x[srt[i]], y[srt[i]], cost[srt[i]]);
    }
  }
  
  return 0;
}