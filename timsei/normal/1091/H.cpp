#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

bitset < N > B[105];

int n, m, x, y, f, pr[N], cnt, SG[N];
bitset < N > isp, w;

void prework(int n) {
  for(int i = 2; i <= n; ++ i) isp[i] = 1;
  for(int i = 2; i <= n; ++ i) {
    if(isp[i]) pr[++ cnt] = i;
    for(int j = i + i; j <= n; j += i) isp[j] = 0;
  }
  for(int i = 1; i <= cnt; ++ i) {
    w[pr[i]] = 1;
    for(int j = 1; j <= cnt && pr[i] * pr[j] <= n; ++ j) {
      w[pr[i] * pr[j]] = 1;
    }
  }
}

int main() {
  scanf("%d%d", &n, &f);
  prework(N - 1);
  w[f] = 0;
  for(int i = 0; i <= 200000; ++ i) {
    for(int j = 0; ; ++ j) if(!B[j][i]) { SG[i] = j; break; }
    if(SG[i] > 100) cerr << "FUCK" << endl;
    B[SG[i]] |= (w << i);
  }

  int a, b, c, ans = 0;
  
  for(int i = 1; i <= n; ++ i) {
    scanf("%d%d%d", &a, &b, &c);
    ans ^= SG[b - a - 1];
    ans ^= SG[c - b - 1];
  }
  if(ans) {
    puts("Alice");
    puts("Bob");
  }
  else puts("Bob"), puts("Alice");
}