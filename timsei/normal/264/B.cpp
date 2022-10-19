#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int A[N], n, m, x, y, pr[N], cnt;
bool isp[N];

void prework(int n) {
  for(int i = 2; i <= n; ++ i) isp[i] = 1;
  for(int i = 1; i <= n; ++ i) {
    if(isp[i]) pr[++ cnt] = i;
    for(int j = 1; j <= cnt && pr[j] * i <= n; ++ j) {
      isp[i * pr[j]] = 0;
      if(i % pr[j] == 0) break;
    }
  }
}

int S[N];
vector <int> G[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
  prework(1e5);
  for(int i = 1; i <= cnt; ++ i) {
    for(int j = pr[i]; j <= 1e5; j += pr[i])
      G[j].push_back(pr[i]);
  }
  int ans = 0;
  for(int i = 1; i <= n; ++ i) {
    int MAX = 0;
    for(int j = 0; j < (int)G[A[i]].size(); ++ j) {
      MAX = max(MAX, S[G[A[i]][j]] + 1);
    }
    ans = max(ans, MAX);
    for(int j = 0; j < (int) G[A[i]].size(); ++ j)
      S[G[A[i]][j]] = MAX;
  }
  cout << max(ans, 1) << endl;
}