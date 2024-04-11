#include<cstdio>
#include<queue>
using namespace std;
const int MAXN = 100000;
struct node{
	int cost, ind;
	node(int _c=0, int _i=0):cost(_c), ind(_i){}
};
bool operator < (node a, node b) {
	return (a.cost == b.cost) ? a.ind > b.ind : a.cost > b.cost;
}
int a[MAXN + 5], c[MAXN + 5];
priority_queue<node>que;
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=1;i<=n;i++) {
		scanf("%d", &c[i]);
		que.push(node(c[i], i));
	}
	for(int i=1;i<=m;i++) {
		long long res = 0;
		int t, d, p; scanf("%d%d", &t, &d);
		p = min(d, a[t]);
		res += 1LL*p*c[t];
		a[t] -= p;
		d -= p;
		if( d > 0 ) {
			while( !que.empty() && d > 0 ) {
				t = que.top().ind;
				if( a[t] == 0 ) {
					que.pop();
					continue;
				}
				p = min(d, a[t]);
				res += 1LL*p*c[t];
				a[t] -= p;
				d -= p;
			}
		}
		if( d > 0 ) puts("0");
		else printf("%I64d\n", res);
	}
}