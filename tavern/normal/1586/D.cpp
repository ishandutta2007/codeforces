#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int n;
int f[maxn], p[maxn];

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    printf("? ");
    for(int j = 1; j <= n; ++j)
      printf("%d ", 1 + (j != i)); puts("");
    fflush(stdout);
    int k; scanf("%d", &k);
    if(k != i)
      f[k] = i;
  }
  for(int i = 1; i <= n; ++i){
    printf("? ");
    for(int j = 1; j <= n;++j)
      printf("%d ", 2 - (j != i)); puts("");
    fflush(stdout);
    int k; scanf("%d", &k);
    if(k != i)
      assert(!f[i] || f[i] == k), f[i] = k;
  }
  for(int i = 1, j = 0; i <= n; ++i)
    j = f[j], p[j] = i;
  printf("! ");
  for(int i = 1; i <= n; ++i)
    printf("%d ", p[i]); puts("");
  fflush(stdout);
  return 0;
}