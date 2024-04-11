#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 2505;

int n;
int a[maxn];
vector<int> vec;

inline void calc(int n){
  if(n == 1)
    return;
  if(!(n & 1)){
    calc(n - 1);
    return;
  }

  int pos = -1;
  for(int i = 0; i < n; ++i) if(a[i] == n - 1)
			       pos = i;
  vec.PB(pos + 1); reverse(a, a + pos + 1);
  for(int i = 0; i < n; ++i) if(a[i] == n - 2)
			       pos = i;
  vec.PB(pos); reverse(a, a + pos);
  vec.PB(pos + 2); reverse(a, a + pos + 2);
  vec.PB(3); reverse(a, a + 3);
  vec.PB(n); reverse(a, a + n);
  calc(n - 2);
  return;
}

inline void solve(){
  scanf("%d", &n);
  vec.clear();
  bool ok = true;
  for(int i = 0; i < n; ++i){
    scanf("%d", a + i), --a[i];
    ok &= !(i - a[i] & 1);
  }
  if(!ok || !(n & 1) && a[n - 1] != n - 1){
    puts("-1");
    return;
  }

  calc(n);
  printf("%d\n", vec.size());
  for(int i = 0; i < vec.size(); ++i)
    printf("%d ", vec[i]); puts("");
  return;
}

int main(){
  //freopen("C.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}