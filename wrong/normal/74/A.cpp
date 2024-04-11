#include<cstdio>
#include<cstring>

int main()
{
  char s[32];
  int mx = -50*51;
  int n;
  scanf("%d", &n);
  while(n--) {
    char t[32];
    int a[7];
    scanf("%s", t);
    for(int i=0; i<7; ++i)
      scanf("%d", &a[i]);
    int p = a[0]*100-a[1]*50+a[2]+a[3]+a[4]+a[5]+a[6];
    if(p > mx) {
      mx = p;
      strcpy(s, t);
    }
  }
  puts(s);
  return 0;
}