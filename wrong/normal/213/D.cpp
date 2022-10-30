#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

double x[5000], y[5000];

const double pi = acos(-1);

int main()
{
  int n;
  scanf("%d", &n);
  
  double r = 10 * sin(54.0 / 180 * pi) / sin(72.0 / 180 * pi);
  for(int i=0; i<5; ++i) {
    x[i] = r * cos(72.0 * i / 180 * pi);
    y[i] = r * sin(72.0 * i / 180 * pi);
  }
  swap(x[2], x[4]);
  swap(y[2], y[4]);
  
  for(int i=1; i<n; ++i) {
    for(int j=4*i+1; j<=4*i+4; ++j) {
      x[j] = x[j-4] + x[4] - x[0];
      y[j] = y[j-4] + y[4] - y[0];
    }
  }
  
  printf("%d\n", 4*n+1);
  for(int i=0; i<4*n+1; ++i)
    printf("%.12f %.12f\n", x[i], y[i]);
  
  for(int i=0; i<n; ++i)
    printf("%d %d %d %d %d\n", 4*i+1, 4*i+2, 4*i+5, 4*i+4, 4*i+3);
  
  printf("1");
  for(int i=1; i<=n; ++i)
    printf(" %d", 4*i+1);
  
  for(int i=n; i>=1; --i) {
    int p = 4*i+1;
    printf(" %d %d %d %d", p-2, p-3, p-1, p-4);
  }
  puts("");
  
  return 0;
}