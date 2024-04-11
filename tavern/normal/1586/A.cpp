#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;

int n;
int a[maxn];

inline void solve(){
  scanf("%d", &n);
  int sum = 0;
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), sum += a[i];
  bool isp = true;
  for(int i = 2; 1ll * i * i <= sum; ++i)
    isp &= (sum % i != 0);
  if(!isp){
    printf("%d\n", n);
    for(int i = 0; i < n; ++i)
      printf("%d ", i + 1);
    puts("");
  }
  else{
    printf("%d\n", n - 1);
    bool flg = false;
    for(int i = 0; i < n; ++i){
      if(a[i] % 2 == 1 && !flg)
	flg = true;
      else
	printf("%d ", i + 1);
    }
    puts("");
  }
  return;
}

int main(){
  //freopen("A.in", "r", stdin);
  
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}