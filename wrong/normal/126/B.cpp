#include<cstdio>

char s[1<<20];
int n, pow[1<<20], hsh[1<<20];

#define hash(i,j) (hsh[(j)]-hsh[(i)-1]*pow[(j)-(i)+1])

int main()
{
  scanf("%s", &s[1]);
  pow[0] = 1; hsh[0] = 0;
  for(n=1; s[n]; ++n) {
    pow[n]=pow[n-1]*1000000007;
    hsh[n]=hsh[n-1]*1000000007+s[n];
  }
  n--;
  int up = 0;
  for(int i=2; i<n; ++i) {
    int lo = 1, hi = n-i;
    while(hi>=lo) {
      int mid = (hi+lo) / 2;
      if(hash(1,mid) == hash(i,i+mid-1)) lo = mid+1; else hi = mid-1;
    }
    if(up < hi) up = hi;
  }
  for(int i=up; i>=1; --i) {
    if(hash(1,i) != hash(n-i+1,n)) continue;
    s[i+1]=0; puts(&s[1]);
    return 0;
  }
  puts("Just a legend");
  return 0;
}