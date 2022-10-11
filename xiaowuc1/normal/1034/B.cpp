#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int main() {
  int lhs, rhs;
  scanf("%d%d", &lhs, &rhs);
  if(lhs > rhs) swap(lhs, rhs);
  if(lhs == 1) {
    int g = (rhs/6)*6;
    if(rhs%6==4) g+=2;
    if(rhs%6==5) g+=4;
    printf("%d\n", g);
    return 0;
  }
  if(lhs == 2) {
    // 2 -> 0
    if(rhs == 2) {
      printf("0\n");
      return 0;
    }
    // 3 -> 4
    if(rhs == 3) {
      printf("4\n");
      return 0;
    }
    // 4 -> 8
    if(rhs == 4) {
      printf("8\n");
      return 0;
    }
    // 5 -> 10
    if(rhs == 5) {
      printf("10\n");
      return 0;
    }
    if(rhs <= 7) {
      printf("12\n");
      return 0;
    }
  }
  ll ans = lhs;
  ans *= rhs;
  if(ans%2) ans--;
  printf("%lld\n", ans);
  return 0;
}