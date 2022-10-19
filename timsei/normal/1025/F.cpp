#include <bits/stdc++.h>
using namespace std;

typedef double db;

const int N = 2e3 + 5;
const db eps = 1e-9;
const db pi = acos(-1);
  
struct Po {
  int x, y;
  friend Po operator - (Po a, Po b) {return (Po){a.x - b.x, a.y - b.y};}
  db ang() {
    return atan2(y, x); // [-pi, pi)
  }
}P[N];

db A[N << 1];
int tot, n;

long long calc(int x) {
  return 1LL * x * (x - 1) / 2 * (n - 2 - x) * (n - 2 - x - 1) / 2;
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }

  long long ans = 0;
  
  for(int i = 1; i <= n; ++ i) {
    tot = 0;
    for(int j = 1; j <= n; ++ j)
      if(j != i)
	A[++ tot] = (P[j] - P[i]).ang(), A[tot + n - 1] = A[tot] + 2 * pi;
    //for(int j = 1; j <= tot * 2; ++ j) cerr << A[j] <<" ";
    //cerr << endl;
    sort(A + 1, A + tot * 2 + 1);
    int it = 1;
    for(int j = 1; j <= tot; ++ j) {
      while(A[it] - A[j] <= pi) ++ it;
      ans += calc(it - j - 1);
      //cerr << j <<" " << it << endl;
    }
  }
  cout << ans / 2 << endl;
}