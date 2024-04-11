#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

struct edge {
	int u, v, w;
};

int N, M, Q;
int S[610][610];
int D[610][610];
vector<pii> que[610];
edge edg[200100];

int main() {
	scanf("%d%d",&N,&M);
	memset(D,0x3f,sizeof(D));
	for (int i=0;i<M;i++) {
		int u, v, w;
		scanf("%d%d%d",&u,&v,&w); u--; v--;
		D[u][v] = w;
		D[v][u] = w;
		edg[i] = {u,v,w};
	}
	for (int i=0;i<N;i++) D[i][i] = 0;
	for (int k=0;k<N;k++) {
		for (int i=0;i<N;i++) {
			for (int j=0;j<N;j++) {
				if (D[i][j]>D[i][k]+D[k][j]) {
					D[i][j]=D[i][k]+D[k][j];
				}
			}
		}
	}
	scanf("%d",&Q);
	for (int i=0;i<Q;i++) {
		int u, v, l;
		scanf("%d%d%d",&u,&v,&l); u--; v--;
		if (u>v) swap(u,v);
		que[u].emplace_back(l,v);
	}
	for (int v=0;v<N;v++) {
		for (int u=0;u<N;u++) {
			S[v][u] = -1;
			for (pii &t : que[u]) {
				S[v][u] = max(S[v][u],t.first-D[t.second][v]);
			}
		}
	}
	int ans = 0;
	for (int i=0;i<M;i++) {
		edge e = edg[i];
		int good = 0;
		for (int u=0;u<N;u++) {
			if (e.w + D[u][e.u] <= S[e.v][u]) good = 1;
			if (e.w + D[u][e.v] <= S[e.u][u]) good = 1;
			if (good) break;
		}
		ans += good;
	}
	printf("%d\n",ans);

	return 0;
}