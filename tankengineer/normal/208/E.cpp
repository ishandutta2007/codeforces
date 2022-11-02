#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, m, fa[N][20], top, v[N], next[N], head[N], qhead, qtail, dis[N], pos[N], q[N], t1, t2, t3, t4;

int go(int i, int dis) {
  int tmp = 19;
  while (dis) {
	  while (tmp && dis < (1 << tmp)) --tmp;
	  i = fa[i][tmp];
	  dis -= (1 << tmp);
	}
	return i;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
	  scanf("%d", &fa[i][0]);
		++top; v[top] = i; next[top] = head[fa[i][0]]; head[fa[i][0]] = top;
	}
	qhead = 0; qtail = 1; dis[0] = 0; pos[0] = 1;
	while (qhead < qtail) {
	  t1 = q[++qhead];
	  for (int j = 1; j <= 19; ++j) fa[t1][j] = fa[fa[t1][j - 1]][j - 1];
	  for (int j = head[t1]; j; j = next[j]) {
		  dis[v[j]] = dis[t1] + 1;
		  pos[v[j]] = ++qtail;
			q[qtail] = v[j];
		}
	}
	
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
	  if (i != 1) printf(" ");
		scanf("%d %d", &t1, &t2);
	  if (dis[t1] <= t2) {
			printf("0");
			continue;
		} else {
			t4 = 0;
			t3 = go(t1, t2);
			
			//printf("%d Parent %d\n", t1, t3);
			
			int l = 0, r = pos[t1], mid;
			while (r - l > 1) {
  			mid = (l + r) / 2;
				if (dis[q[mid]] != dis[t1] || go(q[mid], t2) != t3) l = mid; else r = mid;
			}
			t4 += pos[t1] - l - 1;
			//printf("l %d r %d\n", l, r);
						
			l = pos[t1]; r = n + 2;
			while (r - l > 1) {
				mid = (l + r) / 2;
				if (dis[q[mid]] != dis[t1] || go(q[mid], t2) != t3) r = mid; else l = mid;
			}
			t4 += r - pos[t1] - 1;			
			//printf("l %d r %d\n", l, r);

			printf("%d", t4);
		}
	}
	printf("\n");
	
	return 0;
}