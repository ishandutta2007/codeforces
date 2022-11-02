#include<cstdio>

int bitrev(int x)
{
  int y = 0;
  for(int i=0; i<8; ++i)
    if(x & (1<<i)) y |= 1<<(8-i-1);
  return y;
}

int main()
{
  char s[128];
  gets(s);

  int prev = 0;
  for(int i=0; s[i]; ++i) {
    int p = bitrev((int)s[i]);
    printf("%d\n", (bitrev(prev)-p+256)%256);
    prev = (int)s[i];
  }
}