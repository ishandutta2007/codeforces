#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long Int;

#define LL "%I64d"

Int s[100050], a[100050], sol[100050];

int main()
{
  int n;
  scanf("%d", &n);

  for(int i=1; i<=n; ++i) {
    scanf(LL, &a[i]);
  }
  sort(a+1, a+n+1);

  s[0] = 0;
  for(int i=1; i<=n; ++i) {
    s[i] = s[i-1] + a[i];
  }

  for(int i=1; i<=100000; ++i) {
    sol[i] = 0;

    Int sub = 1;
    for(Int j=n-1; j>0; j-=sub) {
      sol[i] += s[j];
      sub *= i;
    }
  }

  int q;
  scanf("%d", &q);

  for(int i=0; i<q; ++i) {
    int k;
    scanf("%d", &k);

    printf(LL, sol[k]);
    printf(i==q-1 ? "\n" : " ");
  }

  return 0;
}