#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = N * 2;
int fir[N] , ne[M] , to[M] , a[N] , x , y , n , m , S[N] , have[N] , mid , ans , k , b[N] , dp[N] , cnt;
void add(int x , int y) {
    ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}
#define link(x,y) add(x , y) , add(y , x)
#define Pair pair <int , int> 
#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])
Pair sy[N];
void upd(Pair &x , int y) {
    if(y <= x.second) return;
    if(y > x.second && y <= x.first) {x.second = y; return;}
    x.second = x.first; x.first = y;
}
void dfs(int x , int f) {
    have[x] = b[x]; S[x] = 1; dp[x] = 1;sy[x] = make_pair(0 , 0);
    Foreachson(i , x) {
	int V = to[i];
	if(V == f) continue;
	dfs(V , x);have[x] += have[V];S[x] += S[V];
	if(have[V] == S[V]) dp[x] += have[V];else upd(sy[x] , dp[V]);
    }dp[x] *= b[x]; dp[x] += sy[x].first * b[x];
}
void dance(int x , int f , int fans) {
    dp[x] -= sy[x].first * b[x];int res = dp[x];
    if(fans == S[1] - S[x]) res += fans * b[x];else upd(sy[x] , fans);
    ans = max(ans , res + sy[x].first * b[x]);
    Foreachson(i , x) {
	int V = to[i];
	if(V == f) continue;int now = res + sy[x].first * b[x];
	if(S[V] == have[V]) now = res + sy[x].first * b[x] - have[V] * b[x];
	else if(dp[V] == sy[x].first) now = res + sy[x].second * b[x];dance(V , x , now);
    }
}
int main(void) {
    scanf("%d%d" , &n , &k);
    for(int i = 1;i <= n;++ i) scanf("%d" , &a[i]);for(int i = 1;i < n;++ i) scanf("%d%d" , &x , &y) , link(x , y);int l = 0 , r = 1e6, res = 0;
    while(l <= r) {
	mid = (l + r) >> 1;for(int i = 1;i <= n;++ i) b[i] = a[i] >= mid; ans = 0;
	dfs(1 , 0); dance(1 , 0 , 0);if(ans >= k) res = mid , l = mid + 1;else r = mid - 1;
    }
    cout << res;
}