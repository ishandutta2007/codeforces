#include <bits/stdc++.h>
using namespace std;

const int N = 111111;

int A[N], n, m, x, y, L[N], R[N];

int main(void) {
  long long ans = 0;
  cin >> n;
  for(int i = 1; i <= n * 2; ++ i) {
    scanf("%d", &A[i]);
    if(!L[A[i]]) L[A[i]] = i;
    else R[A[i]] = i;
  }
  for(int i = 1; i <= n; ++ i) ans += R[i] - L[i] - 1;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      if(L[i] < L[j] && R[i] < R[j] && R[i] > L[j]) -- ans;
    }
  }
  cout << ans << endl;
}