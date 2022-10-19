#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int fa[N] , u , v , n , m , sf , ans , du[N];
bool vis[N];

int getf(int x) {
	return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
}

int main(void) {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++) fa[i] = i;
	for(int i = 1;i <= m;i ++) {
		scanf("%d%d" , &u , &v);
		vis[u] = vis[v] = 1;
		fa[getf(u)] = getf(v); 
		if(u == v) sf ++;
		else du[u] ++ , du[v] ++;
	}
	for(int i = 1;i <= n;i ++) if(vis[i]) {
		if(getf(i) != getf(u)) {
			puts("0");
			return 0;
		}
	}
	long long ans = sf * 1ll * (sf - 1) / 2 + sf * 1ll * (m - sf);
	for(int i = 1;i <= n;i ++) if(vis[i]) ans += 1ll * du[i] * (du[i] - 1) / 2;
	cout<<ans;
}