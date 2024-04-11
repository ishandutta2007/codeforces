#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define int long long

int L[N], R[N], n;

int ans =0;

main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    cin >> L[i] >> R[i];
  }
  sort(L + 1, L + n + 1);
  sort(R + 1, R + n + 1);
  for(int i = 1; i <= n; ++ i) {
    ans += 1 + max(L[i], R[i]);
  }
  cout << ans << endl;
}