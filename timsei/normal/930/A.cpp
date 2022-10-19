#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

int dep[N] , n , m , x , y , ans[N] , fa[N];

int main() {
  dep[1] = 0;
  ans[0] = 1;
  scanf("%d" , &n);
  for(int i = 2;i <= n;++ i) {
    scanf("%d" , &fa[i]);
    dep[i] = dep[fa[i]] + 1;
    ans[dep[i]] ^= 1;
  }
  int res = 0;
  for(int i = 0;i <= n;++ i) {
    res += ans[i];
  }
  cout << res << endl;
}