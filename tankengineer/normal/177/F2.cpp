//177F
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

multimap<int, int> tree;
multimap<int, int>::iterator it;
int n, k, t, top, t1, v[105], c[105], next[105], head[25], s1[4000005], s2[4000005];

bool full = false;

int main() {
  scanf("%d %d %d", &n, &k, &t);
  for (int i = 1; i <= k; i++) {
    scanf("%d %d %d", &t1, &v[i], &c[i]);
    v[i]--;
    next[i] = head[t1]; head[t1] = i;
  }
  tree.insert(make_pair(0, 0));
  for (int i = 1; i <= n; i++) {
    top = 0;
    for (it = tree.begin(); it != tree.end(); it++) {
      for (int j = head[i]; j; j = next[j]) {
        if ((it->second & (1 << v[j])) == 0) {
          top++;
          s1[top] = it->first + c[j];
          s2[top] = (it->second) | (1 << v[j]);
          if (full && tree.rbegin()->first <= s1[top]) top--;
        }
      }
    }
    for (int j = 1; j <= top; j++) {
      tree.insert(make_pair(s1[j], s2[j]));
      if (tree.size() > t) {
        it = tree.end(); it--;
        tree.erase(it);
      }
    }
    if (tree.size() == t) full = true;
  }
  printf("%d\n", tree.rbegin()->first);
  return 0;
}