//CF 6E
#include<stdio.h>
#include<set>

int n, k, h[100005], a, b, r[100005], t;
std::multiset<int> s;

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }
  for (int i = 0; i < n; i++) {
    s.insert(h[i]);
    while ((*s.rbegin() - *s.begin()) > k) {
      s.erase(s.find(h[t++]));
    }
    if (i - t + 1 > a) {
      a = i - t + 1;
      b = 1;
      r[0] = t;
    } else if (i - t + 1 == a) {
      r[b++] = t;
    }
  }
  printf("%d %d\n", a, b);
  for (int i = 0; i < b; i++) {
    printf("%d %d\n", r[i] + 1, r[i] + a);
  }
  return 0;
}