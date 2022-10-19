#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int A[N], n, m, x, y, stk[N], Id[N];

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
  int l, r;
  for(; m --;) {
    scanf("%d%d", &l, &r);
    int tot = 0;
    Id[0] = r;
    stk[++ tot] = abs(A[r - 1] - A[r]); Id[tot] = r - 1;
    long long Sum = stk[tot], ans = Sum;
    for(int i = r - 2; i >= l; -- i) {
      while(tot && stk[tot] <= abs(A[i] - A[i + 1])) {
	Sum -= 1LL * (Id[tot - 1] - Id[tot]) * stk[tot];
	-- tot;
      }
      stk[++ tot] = abs(A[i] - A[i + 1]); Id[tot] = i;
      Sum += 1LL * (Id[tot - 1] - Id[tot]) * stk[tot];
      ans += Sum;
    }
    cout << ans << endl;
  }
}