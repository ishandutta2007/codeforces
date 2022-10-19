#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

int n, x;
bool flag = 0;

main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    cin >> x;
    flag |= x;
  }
  if(flag) puts("HaRd");
  else puts("eAsY");
}