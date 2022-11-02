#include<cstdio>
#include<cmath>

using namespace std;

double F[100050];

int main()
{
  int n, m, h, a=0, s[1024];

  scanf("%d%d%d", &n, &m, &h);
  for(int i=0; i<m; ++i)
    scanf("%d", &s[i]), a+=s[i];
  if(a < n) {
    puts("-1.0");
    return 0;
  }

  if(n == 1) puts("0.0");
  else {
    a--; n--;
    int b = 0, c = 0;
    for(int i=0; i<m; ++i)
      if(i+1==h) c=s[i]-1;
      else b+=s[i];
    if(b < n) {
      puts("1.0");
      return 0;
    }

    F[0] = 0;
    for(int i=1; i<=100000; ++i)
      F[i] = log(i) + F[i-1];

    printf("%.9f\n", 1.0 - exp(F[b]-F[b-n]-F[a]+F[a-n]));
  }

  return 0;
}