#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n;
int a[maxn];

inline void solve(){
  scanf("%d", &n);
  bool ok = true;
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    if(i < 100){
      bool have = false;
      for(int j = 2; j <= i + 1; ++j)
	if(a[i] % j != 0){
	  have = true;
	  break;
	}
      ok &= have;
    }
  }
  puts(ok ? "YES" : "NO");
  return;
}

int main(){
  //freopen("A.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}