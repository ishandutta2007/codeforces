#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = N * 2;

int n, fa[N], cnt, du[N], S[N];

int main() {
  cin >> n;
  for(int i = 2; i <= n; ++ i) {
    scanf("%d", &fa[i]);
    ++ du[fa[i]];
  }
  for(int i = 1; i <= n; ++ i) {
    if(!du[i]) S[i] = 1;
  }
  for(int i = n; i >= 1; -- i) S[fa[i]] += S[i];
  sort(S + 1, S + n + 1);
  int now = 0, ans = 0;
  for(int i = 1; i <= n; ++ i) {
    while(ans < i) {
      ++ now;
      while(S[ans + 1] == now) ++ ans;
    }
    printf("%d ", now);
  }
  puts("");
}