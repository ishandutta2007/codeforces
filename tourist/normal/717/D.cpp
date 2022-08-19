#include <bits/stdc++.h>

using namespace std;

vector <double> p;

vector <double> unite(vector <double> a, vector <double> b) {
  int k = a.size();
  vector <double> c(k, 0.0);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      c[i ^ j] += a[i] * b[j];
    }
  }
  return c;
}

vector <double> solve(int n) {
  if (n == 1) {
    return p;
  }
  if (n % 2 == 0) {
    vector <double> x = solve(n / 2);
    return unite(x, x);
  }
  vector <double> x = solve(n - 1);
  return unite(x, p);
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int k = 1;
  while (k <= x) {
    k <<= 1;
  }
  p.resize(k);
  for (int i = 0; i <= x; i++) {
    scanf("%lf", &p[i]);
  }
  for (int i = x + 1; i < k; i++) {
    p[i] = 0.0;
  }
  vector <double> res = solve(n);
  printf("%.17f\n", 1.0 - res[0]);
  return 0;
}