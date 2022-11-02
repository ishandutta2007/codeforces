#include<cstdio>
#include<algorithm>
#include<complex>
using namespace std;

typedef complex<int> point;
#define x real()
#define y imag()

point p[4];

int main() {
  for (int i = 0; i < 3; ++i) scanf("%d %d", &p[i].x, &p[i].y);
  p[2] -= p[0]; p[1] -= p[0];
  long long cro = (long long)p[1].x * p[2].y - (long long)p[1].y * p[2].x;
  if (cro < 0) {
    puts("RIGHT");
  } else if (cro > 0) {
    puts("LEFT");
  } else {
    puts("TOWARDS");
  }
  return 0;
}