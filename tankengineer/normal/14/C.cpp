#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

int x1, y1, x2, y2, x, y;
map<pair<int,int>,int> a;
bool f;

int main() {
  for (int i = 0; i < 4; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x += (y1 == y2) && (x1 != x2);
    y += (x1 == x2) && (y1 != y2);
    a[make_pair(x1, y1)]++;
    a[make_pair(x2, y2)]++;
  }
  f = (x == 2 && y == 2);
  for (map<pair<int,int>,int>::iterator i = a.begin(); i != a.end(); i++) {
    f = f && i->second == 2;
  }
  if (f) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}