#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 1e3 + 5;
const int M = N * (N - 1);

struct Edge {
    int u , v , w , id;
    friend bool operator < (Edge xxx , Edge yyy) {
	return xxx.w > yyy.w;
    }
    void input(void) {
	scanf("%d%d%d" , &u, &v , &w);
    }
}E[M];

int fa[N] , n , m , l , r , q , dep[N] , Tf[N] , S[N];

int getf(int x) {
    if(fa[x] == x) return x;
    int sy = getf(fa[x]);
    dep[x] = dep[fa[x]] ^ Tf[x];
    fa[x] = sy; Tf[x] = dep[fa[x]] ^ dep[x];
    return sy;
}

int main(void) {
    scanf("%d%d%d" , &n , &m , &q);
    for(int i = 1;i <= m;++ i) {
	E[i].input(); E[i].id = i;
    }
    sort(E + 1 , E + m + 1);
    for(;q--;) {
	scanf("%d%d" , &l , &r);
	for(int i = 1;i <= n;++ i) fa[i] = i , dep[i] = 0 , Tf[i] = 0 , S[i] = 1;
	int ans = -1;
	for(int i = 1;i <= m;++ i) if(E[i].id >= l && E[i].id <= r) {
		int x = E[i].u , y = E[i].v , z = E[i].w;
		if(getf(x) == getf(y)) {
		    if(dep[x] == dep[y]) {
			printf("%d\n" , z); ans = z;
			break;
		    }
		}
		else {
		    int fx = getf(x) , fy = getf(y);
		    if(S[fx] > S[fy]) swap(x , y) , swap(fx , fy);
		    Tf[fx] = dep[x] ^ dep[y] ^ 1;
		    fa[fx] = fy; S[fy] += S[fx];
		}
	}
	if(ans == -1) puts("-1");
    }
}