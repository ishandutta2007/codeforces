#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

constexpr int N = 100;

int n, m, k[N], f[N];
set<int> ans;

bool check(int x) {
  for(int i = 0; i<m; ++i)
    if(k[i] / x != f[i])
      return false;
  return true;
}

int main() {
  scanf("%d %d", &n, &m);
  --n;
  for(int i = 0; i<m; ++i) {
    scanf("%d %d", k+i, f+i);
    --k[i], --f[i];
  }
  for(int i = 1; i<=N; ++i)
    if(check(i))
      ans.insert(n/i+1);
  if(ans.size() > 1)
    puts("-1");
  else 
    printf("%d\n", *ans.begin());
}