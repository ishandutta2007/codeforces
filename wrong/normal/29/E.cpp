#include<cstdio>
#include<cstring>

int deg[512], e[512][512];
int dist[512][512][2], prev[512][512][2];
int q[512*512*2], alex[512], bob[512];

#define enc(a, b, t) (((a)<<10)|((b)<<1)|(t))

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    e[e[a][deg[a]++] = b][deg[b]++] = a;
  }
  int hd = 0, tl = 0;
  q[hd++] = enc(0, n-1, 0);
  memset(dist, -1, sizeof(dist));
  dist[0][n-1][0] = 0; prev[0][n-1][0] = -1;
  while(tl < hd) {
    int a = q[tl]>>10, b = (q[tl]>>1)&511, t = q[tl]&1;
    if(t == 0 && a == n-1 && b == 0) break;
    if(t == 0) {
      for(int i=0; i<deg[a]; ++i) {
	if(dist[e[a][i]][b][1] >= 0) continue;
	dist[e[a][i]][b][1] = dist[a][b][t]+1;
	prev[e[a][i]][b][1] = q[tl];
	q[hd++] = enc(e[a][i], b, 1);
      }
    } else {
      for(int i=0; i<deg[b]; ++i) {
	if(dist[a][e[b][i]][0] >= 0 || a == e[b][i]) continue;
	dist[a][e[b][i]][0] = dist[a][b][t]+1;
	prev[a][e[b][i]][0] = q[tl];
	q[hd++] = enc(a, e[b][i], 0);
      }
    }
    tl++;
  }
  if(tl >= hd) {
    puts("-1");
    return 0;
  }
  int k = dist[n-1][0][0] / 2;
  printf("%d\n", k);
  for(int a = n-1, b = 0, t = 0; ; ) {
    if(t == 0) bob[k] = b;
    else alex[k--] = a;
    if(prev[a][b][t] < 0) break;
    int p = prev[a][b][t];
    a = p>>10; b = (p>>1)&511, t = p&1;
  }
  alex[0] = 0; bob[0] = n-1; k = dist[n-1][0][0] / 2;
  for(int i=0; i<=k; ++i) printf("%d%c", alex[i]+1, i==k ? '\n' : ' ');
  for(int i=0; i<=k; ++i) printf("%d%c", bob[i]+1, i==k ? '\n' : ' ');
  return 0;
}