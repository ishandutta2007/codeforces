#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int n;
int a[maxn], b[maxn];

inline void solve(){
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for(int i = 0; i < n; ++i)
    scanf("%d", b + i);
  sort(a, a + n), sort(b, b + n);
  bool ok = true;
  for(int i = 0; i < n; ++i)
    ok &= (a[i] == b[i] || a[i] + 1 == b[i]);
  puts(ok ? "YES" : "NO");
  return;
}

int main(){
  //freopen("A.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}