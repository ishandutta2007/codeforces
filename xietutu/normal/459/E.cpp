#include <cstdio>
#include <algorithm>
#include <queue>
std::queue<int> Q;
const int maxn = 1000000;
struct arr {
	int u,v,w;
} ES[maxn];
bool operator<(const arr& lhs,const arr& rhs) {
	return lhs.w < rhs.w;
}
int l,r,n,m,ans,d[maxn][2];
int main() {
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= m; ++i) 
		scanf("%d %d %d",&ES[i].u,&ES[i].v,&ES[i].w);
	std::sort(ES + 1,ES + m + 1);
	//for (int i = 1; i <= m; ++i) printf("%d %d %d\n",ES[i].u,ES[i].v,ES[i].w);
	l = 1;
	for (int i = 1; i <= 100000; ++i) {
		if (l > m) break;
		if (i == ES[l].w) {
			r = l;
			while (r + 1 <= m && ES[r + 1].w == i) ++r;
			for (int j = l; j <= r; ++j) {
				int u = ES[j].u,v = ES[j].v;
				if (d[u][0] + 1 > d[v][1]) {
					d[v][1] = d[u][0] + 1;
					Q.push(v);
				}
			}
			while (Q.size()) {
				int x = Q.front(); Q.pop();
				d[x][0] = d[x][1];
			}
		}
		l = r + 1;
	}
	//for (int i = 1; i <= n; ++i) printf("%d %d\n",d[i][0],d[i][1]); 
	for (int i = 1; i <= n; ++i)
		if (d[i][0] > ans) ans = d[i][0];
	printf("%d",ans);
}