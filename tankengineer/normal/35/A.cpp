#include<cstdio>
#include<algorithm>
using namespace std;

int n, t1, t2;
bool v[5];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  v[n] = true;
  for (int i = 1; i <= 3; ++i) {
    scanf("%d%d", &t1, &t2);
    v[t1] ^= v[t2];
    v[t2] ^= v[t1];
    v[t1] ^= v[t2];
  }
  for (int i = 1; i <= 3; ++i) if (v[i]) printf("%d\n", i);
  return 0;
}