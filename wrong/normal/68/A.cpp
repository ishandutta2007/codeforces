#include<cstdio>
#include<algorithm>

int main()
{
  int p[4], a, b, s=0;
  for(int i=0; i<4; ++i) scanf("%d", &p[i]);
  scanf("%d%d", &a, &b);
  for(int x=a; x<=b; ++x) {
    int c=0;
    std::sort(p, p+4);
    do {
      if(x%p[0]%p[1]%p[2]%p[3]==x) c++;
    } while(std::next_permutation(p, p+4));
    if(c>=7) s++;
  }
  printf("%d\n", s);
  return 0;
}