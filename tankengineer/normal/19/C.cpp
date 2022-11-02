//19C
#include<cstdio>
#include<list>
#include<map>
using namespace std;

int n, a[100001], ans, x, y;
map<int,list<int> > t;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    t[a[i]].push_back(i);
  }
  a[n] = -1;
  ans = 0;
  for (int i = 0; i < n; i++) {
    list<int>& e = t[a[i]];
    e.pop_front();
    for (list<int>::iterator it = e.begin(); it != e.end(); it++) {
      x = i + 1; y = (*it) + 1;
      while (x < (*it) && a[x] == a[y]) {
        x++; y++;
      }
      if (x == *it) {
        i = (*it) - 1;
        ans = (*it);
      }
    }
  }
  printf("%d\n", n - ans);
  for (int i = ans; i < n - 1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n - 1]);
  return 0;
}