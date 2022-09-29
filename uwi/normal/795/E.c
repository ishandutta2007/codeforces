#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char a[1000000];
int m;
int n;
long long base;
int i, j, k;
long long ret;
long long hey;

int main()
{
  scanf("%s", a);
  scanf("%d", &m);
  n = strlen(a);

  base = 0;
  hey = 1;
  for(i = 0;i < n;i++){
    base = (base * 10 + a[i]-'0')%m;
  }
  for(i = 0;i < n-1;i++){
    hey = hey * 10 % m;
  }

  ret = 99999999999999LL;
  for(i = 0;i < n;i++){
    if(a[i] != '0'){
      if(base < ret){
        ret = base;
      }
    }
    base -= hey*(a[i]-'0');
    base = base * 10 % m;
    base += a[i]-'0';
    base %= m;
    if(base < 0)base += m;
  }
  printf("%d\n", (int)ret);

  return 0;
}