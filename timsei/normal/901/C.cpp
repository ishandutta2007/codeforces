#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 5;
const int M = 6e5 + 5;

int n , m , x , y , stk[N] , tot , cnt , l , r;
long long S[N];

struct Seg {
    int l , r , id;
    long long ans;
    friend bool operator < (Seg xxx , Seg yyy) {
	return (xxx.l == yyy.l) ? xxx.r < yyy.r : xxx.l < yyy.l;
    }
}L[N];

bool vis[N] , U[N];

int fir[N] , ne[N * 2] , to[N * 2] , Havana;

void add(int x , int y) {
    ne[++ Havana] = fir[x]; fir[x] = Havana; to[Havana] = y;
}

void link(int x , int y) {add(x , y); add(y , x);}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

void dfs(int x , int f) {
    stk[++ tot] = x; vis[x] = 1; U[x] = 1;
    Foreachson(i , x) {
	int V = to[i];
	if(V == f) continue;
	if(vis[V]) {
	    int l = 2e9 , r = 0;
	    for(int i = tot;i >= 1;-- i) {
		l = min(l , stk[i]); r = max(r , stk[i]);
		if(stk[i] == V) break;
	    }
	    L[++ cnt].l = l; L[cnt].r = r;
	}
	else if(!U[V]) dfs(V , x);
    }
    -- tot; vis[x] = 0;
}

bool used[N];

int  Min[N];

int main(void) {
    scanf("%d%d" , &n , &m);
    for(int i = 1;i <= m;++ i) {
	scanf("%d%d" , &x , &y); link(x , y);
    }
    for(int i = 1;i <= n;++ i) if(!U[i]) dfs(i , 0);
    sort(L + 1 , L + cnt + 1);
    memset(Min , 127 , sizeof(Min));
    for(int i = 1;i <= cnt; ++ i) {
	Min[L[i].l] = min(Min[L[i].l] , L[i].r);
    }
    Min[n] = min(Min[n] , n + 1); Min[n + 1] = n + 1;
    for(int i = n;i >= 1;-- i) Min[i] = min(Min[i + 1] , Min[i]) , S[i] = S[i + 1] + Min[i] - 1;
    int t;
    for(scanf("%d" , &t);t --;) {
	scanf("%d%d" , &l , &r);
	int L = l , R = r ,res = l - 1;
	long long ans = (r - l + 1) * 1ll * (r - l + 2) / 2ll;
	while(L <= R) {
	    int mid = (L + R) >> 1;
	    if(Min[mid] <= r) {
		res = mid; L = mid + 1;
	    }
	    else R = mid - 1;
	}
	ans -= r * 1ll * (res - l + 1) - (S[l] - S[res + 1]);
	printf("%lld\n" , ans);
    }
}