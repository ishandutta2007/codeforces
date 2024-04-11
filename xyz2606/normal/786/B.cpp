#include<bits/stdc++.h>
using namespace std;
int n, q, s;
const int N(100011), LOG(18);
struct Edge {
	int y, next, p;
} edges[N * LOG * 3];
int idx[N * 9], l;
inline void bd(int x, int y, int z) {
	edges[++l].next = idx[x];
	edges[l].y = y;
	edges[l].p = z;
	idx[x] = l;
}
inline int nextInt() {
	char c(getchar());
	while(c < '0') c = getchar();
	int res(0);
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}
long long dis[N * 9], inf(1ll << 60);
void build(int k, int le, int ri) {
	if(le == ri) {
		bd(k / 2 * 2 + n, le, 0);
		bd(le, k / 2 * 2 + 1 + n, 0);
	}else {
		int mid(le + ri >> 1);
		build(k + k, le, mid);
		build(k + k + 1, mid + 1, ri);
		if(k > 1) {
			bd(k / 2 * 2 + n, k * 2 + n, 0);
			bd(k * 2 + n + 1, k / 2 * 2 + n + 1, 0);
		}
	}
}
void buildvlr(int k, int le, int ri, int v, int l, int r, int w) {
	if(l <= le && ri <= r) {
		bd(v, le == ri ? le : k * 2 + n, w);
	}else {
		int mid(le + ri >> 1);
		if(l <= mid)
			buildvlr(k + k, le, mid, v, l, r, w);
		if(r > mid)
			buildvlr(k + k + 1, mid + 1, ri, v, l, r, w);
	}
}
void buildlrv(int k, int le, int ri, int v, int l, int r, int w) {
	if(l <= le && ri <= r) {
		bd(le == ri ? le : k * 2 + n + 1, v, w);
	}else {
		int mid(le + ri >> 1);
		if(l <= mid)
			buildlrv(k + k, le, mid, v, l, r, w);
		if(r > mid)
			buildlrv(k + k + 1, mid + 1, ri, v, l, r, w);
	}
}
int main() {
	scanf("%d%d%d", &n, &q, &s);
	build(1, 1, n);
	for(int i(1); i <= q; i++) {
		int t, u, v, l, r, w;
		t = nextInt();
		if(t == 1) {
			u = nextInt();
			v = nextInt();
			w = nextInt();
			bd(u, v, w);
		}else {
			v = nextInt();
			l = nextInt();
			r = nextInt();
			w = nextInt();
			if(t == 2)
				buildvlr(1, 1, n, v, l, r, w);
			else
				buildlrv(1, 1, n, v, l, r, w);
		}
	}
	priority_queue<pair<long long, int> > pq;
	fill(dis + 1, dis + 1 + n * 9, inf);
	dis[s] = 0;
	pq.push(make_pair(-dis[s], s));
	for(;;) {
		while(!pq.empty() && pq.top().first != -dis[pq.top().second])
			pq.pop();
		if(pq.empty())
			break;
		int v(pq.top().second);
		pq.pop();
		for(int p(idx[v]); p; p = edges[p].next) {
			int y(edges[p].y);
			if(dis[y] > dis[v] + edges[p].p) {
				dis[y] = dis[v] + edges[p].p;
				pq.push(make_pair(-dis[y], y));
			}
		}
	}
	for(int i(1); i <= n; i++) {
		printf("%I64d%c", dis[i] == inf ? -1 : dis[i], i == n ? '\n' : ' ');
	}
}