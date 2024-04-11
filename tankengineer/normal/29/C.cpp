//29C
#include<cstdio>
#include<map>
using namespace std;

int n, l, t1, t2, sta, qhead, qtail, q[100005], head[100005], next[200005], top, v[200005], dgr[100005], cnt[100005];
bool vis[100005];
map<int,int> t;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &t1, &t2);
    if (t.find(t1) == t.end()) {
      t[t1] = ++l;
      cnt[l] = t1;
    }
    t1 = t[t1];
    if (t.find(t2) == t.end()) {
      t[t2] = ++l;
      cnt[l] = t2;
    }
    t2 = t[t2];
    dgr[t1]++; dgr[t2]++;
    top++; v[top] = t2; next[top] = head[t1]; head[t1] = top;
    top++; v[top] = t1; next[top] = head[t2]; head[t2] = top;
  }
  
  for (int i = 1; i <= l; i++) {
    if (dgr[i] == 1) {
      sta = i;
      break;
    }
  }
  qhead = 0; qtail = 1; q[qtail] = sta;
  while (qtail < l) {
    t1 = q[++qhead];
    printf("%d ", cnt[t1]);
    vis[t1] = true;
    for (int j = head[t1]; j; j = next[j]) {
      if (!vis[v[j]]) {
        q[++qtail] = v[j];
      }
    }
  }
  printf("%d\n", cnt[q[qtail]]);
  return 0;
}