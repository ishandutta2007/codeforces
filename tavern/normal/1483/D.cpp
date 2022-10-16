#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double Lf;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

const int maxn = 605;
const int maxm = maxn * maxn;

int n, m, q;
int ans[maxm];
int ed[maxm][3];
ll dis[maxn][maxn], f[maxn][maxn], lim[maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	memset(dis, 0x3f, sizeof(dis));
	
	FOR(i, 0, n)
		dis[i][i] = 0;
	
	FOR(i, 0, m){
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		--u; --v;
		dis[u][v] = dis[v][u] = w;
//		printf("u = %d v = %d w = %d\n", u, v, w);
		ed[i][0] = u, ed[i][1] = v, ed[i][2] = w;
	}
	
	FOR(w, 0, n) FOR(u, 0, n) FOR(v, 0, n)
		dis[u][v] = min(dis[u][v], dis[u][w] + dis[w][v]);
		
	scanf("%d", &q);
	FOR(j, 0, q){
		int u, v, l; scanf("%d%d%d", &u, &v, &l);
		--u; --v;
		lim[u][v] = lim[v][u] = l;
	}
	
	FOR(u, 0, n) FOR(v, 0, n) FOR(w, 0, n) if(lim[u][w] && lim[u][w] >= dis[v][w])
		f[u][v] = max(f[u][v], lim[u][w] - dis[v][w]);
		
	int tot = 0;
	FOR(i, 0, m){
		int u = ed[i][0], v = ed[i][1];
		bool ok = false;
		FOR(w, 0, n){
			ok |= (dis[w][u] + ed[i][2] <= f[w][v]);
		}
		tot += ok;
	}
	
	printf("%d\n", tot);
	return 0;
}