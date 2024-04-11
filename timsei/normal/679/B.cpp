#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;

int tmp[N] , n , m , x , y;

int get(int x) {
  tmp[m + 1] = 1e18;
  for(int i = 1;i <= m + 1;++ i) {
    if(tmp[i] > x) return i - 1; 
  }
}

int cub(int x) {
  return x * x * x;
}

main(void) {
  cin >> n;
  int now = 0;
  for(int i = 1;i <= 1e5;++ i) {
    while(now + cub(i) < cub(i + 1) && now + cub(i) <= n) {
      now += cub(i);
      tmp[++ m] = now;
    }
  }
  cout << get(n) << ' ';
  now = get(n);
  int S = 0;
  for(int i = 1e5;i >= 1;-- i) {
    while(n >= cub(i)) {
      if(now == 1 + get(n - cub(i))) {
	n -= cub(i);
	S += cub(i);
	-- now;
      }
      else {
	n = min(n , cub(i) - 1);
      }
    }
  }
  cout << S << endl;
}