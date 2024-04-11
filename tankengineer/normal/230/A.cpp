#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;

int s, n;
pair<int, int> f[1005];

int main() {
  scanf("%d %d", &s, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &f[i].first, &f[i].second);
  }
  sort(f + 1, f + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (s <= f[i].first) {
      puts("NO");
      return 0;
    } else {
      s += f[i].second;
    }
  }
  puts("YES");
  return 0;
}