#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

typedef double db;

int n, m, x, y;
db Pa[N], Pb[N], a[N], b[N];

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) scanf("%lf", &Pa[i]);
  for(int i = 1; i <= n; ++ i) scanf("%lf", &Pb[i]);
  for(int i = 1; i <= n + 1; ++ i) Pa[i] += Pa[i - 1];
  for(int i = n; i >= 1; -- i) Pb[i] += Pb[i + 1];
  for(int i = 1; i <= n; ++ i) {
    db X = Pb[i + 1], Y = Pa[i];
    X = Y + 1 - X;
    db Gen = sqrt(X * X - 4 * Y + 1e-16);
    a[i] = (X + Gen) * 0.5;
    b[i] = (X - Gen) * 0.5;
  }
  for(int i = 1; i <= n; ++ i) {
    printf("%.12lf ", a[i] - a[i - 1]);
  }
  puts("");
  for(int i = 1; i <= n; ++ i)
    printf("%.12lf ", b[i] - b[i - 1]);
  puts("");
}