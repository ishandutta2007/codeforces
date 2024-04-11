#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200005;
struct node {
  ll a;
  int id;
} A[N];
bool cmp(node &x, node &y) {
  return x.a < y.a;
} 
ll n, W;

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld", &n, &W);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &A[i].a);
      A[i].id = i;
    }
    sort(A + 1, A + n + 1, cmp);
    int j = 1;
    for (; j <= n && A[j].a <= W; j++) ;
    int id = --j;
    ll W2 = (W + 1) / 2, sum = 0;
    for (; j >= 0; j--) {
      sum += A[j].a;
      if (sum >= W2 && sum <= W) break;
    }
    if (sum >= W2 && sum <= W) {
      printf("%d\n", id - j + 1);
      for (int i = j; i <= id; i++) printf("%d ", A[i].id);
      puts("");
    } else puts("-1");
  }
}