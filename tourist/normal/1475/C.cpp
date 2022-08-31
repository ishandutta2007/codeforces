/**
 *    author:  tourist
 *    created: 25.01.2021 18:01:50       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> A(k);
    for (int i = 0; i < k; i++) {
      cin >> A[i];
    }
    vector<int> B(k);
    for (int i = 0; i < k; i++) {
      cin >> B[i];
    }
    map<int, int> ma;
    map<int, int> mb;
    for (int i = 0; i < k; i++) {
      ma[A[i]] += 1;
      mb[B[i]] += 1;
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      ans += (k - 1) - (ma[A[i]] - 1) - (mb[B[i]] - 1);
    }
    assert(ans % 2 == 0);
    cout << ans / 2 << '\n';
  }
  return 0;
}