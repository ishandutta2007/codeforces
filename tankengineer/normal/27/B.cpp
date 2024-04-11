//27B
#include<cstdio>
#include<algorithm>

using namespace std;

int n, g[55][55], in[55], u, v, srt[55]; 

bool cmp(int i, int j) {return in[i] < in[j];}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n * (n - 1) / 2; i++) {
    scanf("%d %d", &u, &v);
    g[u][v] = 1; g[v][u] = -1;
    in[v]++;
  }
  for (int i = 1; i <= n; i++) {
    srt[i] = i;
  }
  sort(srt + 1, srt + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (g[srt[i]][srt[j]] == 0) {
        printf("%d %d\n", srt[i], srt[j]);
        return 0;
      }
    }
  }
  return 0;
}