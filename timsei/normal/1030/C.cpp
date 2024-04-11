#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int A[N], n, m, x, y;

bool pd(int x) {
  int now = 0;
  for(int i = 1; i <= n; ++ i) {
    if(now == x) now = 0;
    now += A[i];
    if(now == x) now = 0;
    if(now > x) return 0;
  }
  if(now != x && now != 0) return 0;
  return 1;
}

main() {
  cin >> n;
  int Sum = 0;
  for(int i = 1; i <= n; ++ i){
    char ch = ' ';
    while(!isdigit(ch)) ch = getchar();
    A[i] = ch - '0';
    Sum += A[i];
  }
  for(int i = 0; i <= max(Sum - 1, 0); ++ i) {
    if(pd(i)) {
      //cerr << i << endl;
      return 0 * puts("Yes");
    }
  }
  puts("No");
}