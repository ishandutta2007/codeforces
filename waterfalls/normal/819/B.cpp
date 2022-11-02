#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

int ft[1000013];
void update(int x, int v) { x+=1; while (x<1000013) ft[x]+=v, x+=x&-x; }
int query(int x) { x+=1; return x>0 ? ft[x]+query((x-(x&-x)-1)) : 0; }

int n;
int p[1000013];

int main() {
  scanf("%d", &n);
  ll cur = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i] -= 1;
    cur += abs(p[i] - i);
    if (p[i] < i) {
      update(0, -1);
      update(i - p[i], 2);
      update(i, (n - 1 - p[i] - p[i]) - 1);
      update(i + 1, -1 - (n - 1 - p[i] - p[i]));
    } else {
      update(0, 1);
      update(i, (n - 1 - p[i] - p[i]) - 1);
      update(i + 1, -1 - (n - 1 - p[i] - p[i]));
      update(i + n - p[i], 2);
    }
  }

  ll best = cur;
  int which = 0;
  for (int i = 0; i < n; i++) {
    cur += query(i);
    if (cur <= best) {
      best = cur;
      which = n - 1 - i;
    }
  }
  printf("%lld %d\n", best, which);

  return 0;
}