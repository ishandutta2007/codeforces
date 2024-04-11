#include <stdio.h>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int get_ans(ll a, ll b, ll n) {
  if (a < b) return get_ans(b, a, n);
  if (a > n) return 0;
  if (a + b > n) return 1;
  return get_ans(a, a + b, n) + 1;
}

int main() {
  int TC;
  scanf("%d", &TC);
  for(int tc = 1; tc <= TC; tc++) {
    ll a, b, n;
    scanf("%lld%lld%lld", &a, &b, &n);
    printf("%d\n", get_ans(a, b, n));
  }
  return 0;
}