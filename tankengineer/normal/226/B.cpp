#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int n, m;
long long a[100005], k;
map<long long, long long> tr;

long long getans(const long long k) {
  long long t1 = 1, t2 = 0, t3 = 0, t4 = 1, ans = 0;
  while (t2 < n) {
    ans += (a[t1] - a[t2]) * t3;
    ++t3;
    t2 = t1;
    t1 += t4 * k;
    t4 *= k;
    if (t1 > n) t1 = n;
  }
  return ans;
}

int main() {
  tr.clear();
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &a[i]);
    a[i] = -a[i];
  }
  sort(a + 1, a + n + 1);
  a[0] = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = -a[i];
    a[i] += a[i - 1];
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%I64d", &k);
    if (i != 1) printf(" ");
    if (!tr.count(k)) tr[k] = getans(k);
    printf("%I64d", tr[k]);  
  }
  printf("\n");
  return 0;
}