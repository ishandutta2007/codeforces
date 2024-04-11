#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

typedef long long LL;

LL t, a, b;

bool pd(LL x) {
  for(LL i = 2; i * i <= x; ++ i) {
    if(x % i == 0) return 0;
  }
  return 1;
}

int main() {
  for(cin >> t; t --;) {
    cin >> a >> b;
    if(a - b != 1) {
      puts("NO");
      continue;
    }
    else if(pd(a + b)) puts("YES");
    else puts("NO");
  }
}