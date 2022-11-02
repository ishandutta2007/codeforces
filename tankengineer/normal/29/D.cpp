#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 305, M = 605;
int n, t1, t2, dgr[N], top, v[M], next[M], head[N], k, leaf[N], qtop, vq[M], nextq[M], headq[N], lq[M], ans[N], stop, s[N], fa[N], f[N], chd[N], cnt[N];
bool vis[N];

int find(const int i) {return fa[i] == i ? i : fa[i] = find(fa[i]);}
void merge(const int i, const int j) {fa[i] = j;}

void tarjan(const int i) {
  vis[i] = true;
  chd[i] = 0;
  for (int j = head[i]; j; j = next[j]) {
    if (!vis[v[j]]) {
      ++chd[i];
      f[v[j]] = i;
      tarjan(v[j]);
      merge(v[j], i);
    }
  }
  
  for (int j = headq[i]; j; j = nextq[j]) if (vis[vq[j]]) ++cnt[ans[lq[j]] = find(vq[j])];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &t1, &t2);
    ++dgr[t1]; ++dgr[t2];
    ++top; v[top] = t2; next[top] = head[t1]; head[t1] = top;
    ++top; v[top] = t1; next[top] = head[t2]; head[t2] = top;
  }
  for (int i = 2; i <= n; ++i) {
    if (dgr[i] == 1) {
      ++k;
      scanf("%d", &leaf[k]);
      if (k > 1) {
        ++qtop; vq[qtop] = leaf[k - 1]; nextq[qtop] = headq[leaf[k]]; headq[leaf[k]] = qtop; lq[qtop] = k - 1;        
        ++qtop; vq[qtop] = leaf[k]; nextq[qtop] = headq[leaf[k - 1]]; headq[leaf[k - 1]] = qtop; lq[qtop] = k - 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) fa[i] = i;
  tarjan(1);
  
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] != chd[i] - 1 && chd[i] != 0) {
      printf("-1\n");
      return 0;
    }
  }
  
  ans[0] = ans[k] = 1;
  for (int i = 1; i <= k; ++i) {
    s[stop = 1] = leaf[i];
    while (s[stop++] != ans[i - 1]) s[stop] = f[s[stop - 1]];
    while (--stop) printf("%d ", s[stop]);
    s[stop = 1] = f[leaf[i]];
    while (s[stop++] != ans[i]) {
      printf("%d ", s[stop - 1]);
      s[stop] = f[s[stop - 1]];
    }
  }
  printf("1\n"); 
  return 0;
}