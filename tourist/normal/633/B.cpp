#include <bits/stdc++.h>

using namespace std;

inline int get(int n) {
  int z = 0;
  while (n > 0) {
    n /= 5;
    z += n;
  }
  return z;
}

int main() {
  int k;
  scanf("%d", &k);
  int low = 0, high = (int) 1e9;
  while (low < high) {
    int mid = (low + high) >> 1;
    int cnt = get(mid);
    if (cnt < k) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  vector <int> res;
  while (get(low) == k) {
    res.push_back(low);
    low++;
  }
  int sz = res.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}