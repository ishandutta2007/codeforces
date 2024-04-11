#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long s, k, f[2005], t1;
vector<long long> ans;

int main() {
  scanf("%I64d %I64d", &s, &k);
  f[1] = 1;
  t1 = 1;
  while (f[t1] < s) {
    ++t1;
    for (int j = t1 - 1; j >= 1 && j >= t1 - k; --j) f[t1] += f[j];
  }
  for (int i = t1; i >= 1; --i) {
    if (s >= f[i]) {
      s -= f[i];
      //printf("%I64d %I64d\n", s, f[i]);
      ans.push_back(i);
    }
  }
  if (ans.size() < 2) {
    ans.push_back(0);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size() - 1; ++i) {
    printf("%I64d ", f[ans[i]]);
  }
  printf("%I64d\n", f[ans[ans.size() - 1]]);
  return 0;
}