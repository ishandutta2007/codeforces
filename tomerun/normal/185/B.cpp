#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;

int n,l,k;

int main(){
  int S,a,b,c;
  cin >> S >> a >> b >> c;
  if (a == 0 && b == 0 && c == 0) {
    printf("%.9f %.9f %.9f\n", 1.0*S, 0.0, 0.0);
  } else {
    double aa = 1.0 * a * S / (a + b + c);
    double ba = 1.0 * b * S / (a + b + c);
    double ca = 1.0 * c * S / (a + b + c);
    if (aa > 0) aa -= 1e-12;
    if (ba > 0) ba -= 1e-12;
    if (ca > 0) ca -= 1e-12;
    printf("%.13f %.13f %.13f\n", aa, ba, ca);
  }
  return 0;
}