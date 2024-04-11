#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 5;
const int T = 6e5 + 5;
const int mod = 1e9 + 7;

#define int long long

int n , q , t , x , y , du[N] , have[N] , vis[N] , a[N] , dp[T];
vector <int> G[N];
queue <int> Q;

main(void) {
    scanf("%I64d%I64d%I64d" , &n , &q , &t);
    for(int i = 1;i <= n;++ i) {
	scanf("%I64d" , &a[i]);
    }
    for(int i = 1;i <= q;++ i) scanf("%I64d%I64d" , &x , &y) , G[x].push_back(y) , ++ du[y] , have[x] = 1;
    for(int i = 1;i <= n;++ i) if(!du[i]){
	    Q.push(i);
    }
    while(!Q.empty()) {
	int ind = Q.front(); Q.pop(); vis[ind] = 1;
	for(auto V : G[ind]) {
	    if(-- du[V] == 0) {
		Q.push(V);a[V] += a[ind];
	    }
	}
    }
    int tot = 0;
    for(int i = 1;i <= n;++ i) if(vis[i]) ++ tot;
    if(tot != n) return puts("0") * 0;
    for(int i = 1;i <= n;++ i) if(have[i]) t -= a[i];
    if(t < 0) return puts("0") * 0;
    dp[0] = 1;
    for(int i = 1;i <= n; ++ i) {
	for(int j = 0;j <= t - a[i];++ j) dp[j + a[i]] = (dp[j + a[i]] + dp[j]) % mod;
    }
    cout << dp[t];
}