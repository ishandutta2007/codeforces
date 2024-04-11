#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1005;

int A[N], x, y;

int main() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++ i) scanf("%d", &x), ++ A[x];
  int ans = 0;
  for(int i = 0; i <= 1000000 + 1000; ++ i) {
    A[i + 1] += A[i] / 2;
    ans += A[i] % 2;
  }
  cout << ans << endl;
}