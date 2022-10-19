#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int MAX = 1e6 + 5;
const int M = N * N;

int n , k , a[N] , m;

int fa[N] , vis[N] , S[MAX];

int getf(int x) {
    return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
}

struct Edge {
    short x , y;
}E[M];

int fir[MAX] , ne[M] , cnt;

void add(int x , Edge y) {
    ne[++ cnt] = fir[x]; fir[x] = cnt; E[cnt] = y;
}

int main(void) {
    scanf("%d%d" , &n , &k);
    //n = 5000 , k = 3;
    for(int i = 1;i <= n;++ i) cin >> a[i];
    //for(int i = 1;i <= n;++ i) a[i] = rand() % 1000000;
    sort(a + 1 , a + n + 1);
    for(int i = 1;i <= n;++ i) {
	for(int j = i + 1;j <= n;++ j) add(a[j] - a[i] , (Edge) {(short)i , (short)j}) , ++ S[a[j] - a[i]];
    }
    for(int ans = 1;;++ ans) {
	int now = 0;
	for(int j = ans;j < MAX;j += ans) now += S[j];
	if(now > (k + 1) * k / 2) continue;
	int res = 0; now = 0;
	for(int j = ans;j < MAX;j += ans)
	    for(int i = fir[j];i;i = ne[i]) {
		Edge V = E[i];
		if(vis[V.x] != ans) ++ res , ++ now , fa[V.x] = V.x;
		if(vis[V.y] != ans) ++ res , ++ now , fa[V.y] = V.y;
	    if(getf(V.x) != getf(V.y)) fa[fa[V.x]] = fa[V.y] , -- res;
	    vis[V.x] = vis[V.y] = ans;
	}
	if(now - res > k) continue;
	cout << ans << endl;
	return 0;
    }
}