//B
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 505;

int n, m, c, fa[N], size[N], t1, t2;

int find(const int i) {return i == fa[i] ? i : fa[i] = find(fa[i]);}
void merge(const int i, const int j) {
  if (size[i] >= size[j]) {
    fa[j] = i;
    size[i] += size[j];
  } else {
    fa[i] = j;
    size[j] += size[i];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
      fa[i] = i;
      size[i] = 1;
  }
  scanf("%d", &m);
  c = n;
  while (m--) {
    scanf("%d %d", &t1, &t2);
    t1 = find(t1); t2 = find(t2);
    if (t1 != t2) merge(t1, t2); else if ((size[t1] & 1) == 1) --n;
  }
  n = ((n >> 1) << 1);
  printf("%d\n", c - n);    
  return 0;
}