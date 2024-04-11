#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
  int n, p, in[1024] = {0}, out[1024] = {0}, to[1024][2];

  scanf("%d%d", &n, &p);
  for(int i=0; i<p; ++i) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    in[b]++; out[a]++;
    to[a][0] = b; to[a][1] = d;
  }

  int t = 0, tank[1024], tap[1024], diameter[1024];
  for(int i=1; i<=n; ++i) {
    if(in[i] == 0) {
      int flow = 1000000, v = i;
      while(out[v] > 0) {
	flow = min(flow, to[v][1]);
	v = to[v][0];
      }
      if(i != v) {
	tank[t] = i; tap[t] = v; diameter[t++] = flow;
      }
    }
  }

  printf("%d\n", t);
  for(int i=0; i<t; ++i)
    printf("%d %d %d\n", tank[i], tap[i], diameter[i]);
}