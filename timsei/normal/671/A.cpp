#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 111111;
const double eps = 1e-12;

struct P {
  int x, y;
  void input(void) {
    scanf("%lld%lld", &x, &y);
  }

  double abs(void) {
    return sqrt(x * x + y * y);
  }

  friend P operator - (P a, P b) {return (P) {a.x - b.x, a.y - b.y};}
} K[N], A, B, T;

int n;
double ans, C[N], D[N];

double calc(int x, int y) {
  if(x == y) return 1e18;
  double first = min((T - A).abs(), C[x]), second =  min((T - B).abs(), D[y]);
  if(first < 0 && second < 0) return ans + first + second;
  return ans + min(first, second);
}

vector <int> a, b;

main(void) {
  A.input();
  B.input();
  T.input();
  cin >> n;
  for(int i = 1; i <= n; ++ i) K[i].input();
  for(int i = 1; i <= n; ++ i) {
    ans += (K[i] - T).abs() * 2;
    C[i] = (K[i] - A).abs() - (K[i] - T).abs();
    D[i] = (K[i] - B).abs() - (K[i] - T).abs();
  }
  double res = 1e18;

  double Min = 1e18;
  C[0] = D[0] = 1e18;
  for(int i = 1; i <= n; ++ i) Min = min(Min, C[i]);
  for(int i = 1; i <= n; ++ i) if(fabs(Min - C[i]) <= eps) a.push_back(i);

  Min = 1e18;
  for(int i = 1; i <= n; ++ i) Min = min(Min, D[i]);
  for(int i = 1; i <= n; ++ i) if(fabs(Min - D[i]) <= eps) b.push_back(i);

  for(int i = 0; i < min((int)a.size(), n); ++ i) {
    if(a[i] != b[0]) {
      res = min(res, calc(a[i], b[0]));
      continue;
    }
    for(int j = 0; j <= n; ++ j) if(j != a[i]) res = min(res, calc(a[i], j));
  }

  for(int i = 0; i < min((int)b.size(), n); ++ i) {
    if(b[i] != a[0]) {
      res = min(res, calc(a[0], b[i]));
      continue;
    }
    for(int j = 0; j <= n; ++ j) if(j != b[i]) res = min(res, calc(j, b[i]));
  }
  
  printf("%.12lf\n", res);
}