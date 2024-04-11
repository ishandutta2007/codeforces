#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 200000000;

int n, m, t1, t2, t[105][105];
long long dis1[105], dis2[105], cnt1[105], cnt2[105], qhead, qtail, q[105];
double ans, tmp;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
	  scanf("%d %d", &t1, &t2);
	  t[t1][t2] = 1;
	  t[t2][t1] = 1;
	}
	
	for (int i = 1; i <= n; ++i) {
	  dis1[i] = dis2[i] = INF;
	  cnt1[i] = cnt2[i] = 0;
	}
	
	dis1[1] = 0; cnt1[1] = 1;
	qhead = 0; qtail = 1; q[qtail] = 1;
	while (qhead < qtail) {
	  t1 = q[++qhead];
	  for (int j = 1; j <= n; ++j) {
		  if (t[t1][j] && dis1[t1] + 1 < dis1[j]) {
			  dis1[j] = dis1[t1] + 1;
			  cnt1[j] = 0;
			  q[++qtail] = j;
			}
			if (t[t1][j] && dis1[t1] + 1 == dis1[j]) {
			  cnt1[j] += cnt1[t1];
			}
		}
	}
	
	dis2[n] = 0; cnt2[n] = 1;
	qhead = 0; qtail = 1; q[qtail] = n;
	while (qhead < qtail) {
	  t1 = q[++qhead];
	  for (int j = 1; j <= n; ++j) {
		  if (t[t1][j] && dis2[t1] + 1 < dis2[j]) {
			  dis2[j] = dis2[t1] + 1;
			  cnt2[j] = 0;
			  q[++qtail] = j;
			}
			if (t[t1][j] && dis2[t1] + 1 == dis2[j]) {
			  cnt2[j] += cnt2[t1];
			}
		}
	}
	/*
	for (int i = 1; i <= n; ++i) {
	  printf("%d:\n%I64d %I64d\n%I64d %I64d\n", i, dis1[i], cnt1[i], dis2[i], cnt2[i]);
	}
	*/
	ans = 0;
	for (int i = 1; i <= n; ++i) {
	  tmp = 0;
	  for (int j = 1; j <= n; ++j) {
			if (!t[i][j]) continue;
		  if (dis1[j] + dis2[i] + 1 == dis1[n]) {
			  tmp += cnt1[j] * 1.0 * cnt2[i] / cnt1[n];
			}
			if (dis1[i] + dis2[j] + 1 == dis1[n]) {
			  tmp += cnt1[i] * 1.0 * cnt2[j] / cnt1[n];
			}
		}
		ans = max(ans, tmp);
	}
	printf("%.12lf\n", ans);
	return 0;
}