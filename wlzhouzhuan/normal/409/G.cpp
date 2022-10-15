#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

double sum = 0;
int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    double x; cin >> x >> x;
    sum += x;
  }
  printf("%.3lf\n", sum / n + 5.0);
  return 0;
}