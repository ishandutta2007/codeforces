#include <cstdio>

using namespace std;

int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  while (n--) {
    int a;
    scanf("%d", &a);
    int low = 0, high = a;
    while (low < high) {
      int mid = (low + high) >> 1;
      long long other = mid * 1LL * y / x;
      if (mid + other >= a) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    int mid = low;
    long long other = mid * 1LL * y / x;
    int pre_shots = (mid - 1) + other;
    if (mid * 1LL * y == other * x) {
      pre_shots--;
    }
    if (pre_shots >= a) {
      puts("Vova");
    } else {
      if (mid * 1LL * y == other * x) {
        puts("Both");
      } else {
        puts("Vanya");
      }
    }
  }
  return 0;
}