#include<stdio.h>

int n, m;
int curr, prev;
int ans = 0;

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 2 * m; j++){
      scanf("%d", &curr);
      if(j % 2 == 1 && (curr == 1 || prev == 1)){ans++;}
      prev = curr;
    }
  }
  printf("%d", ans);
  return 0;
}