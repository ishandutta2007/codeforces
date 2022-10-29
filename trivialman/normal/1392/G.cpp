#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define nbit(x) __builtin_popcount(x)
const int N = (1<<20) + 5;
 
int n, m, k, x, y;
int s[N], t[N];
int l[N], r[N];
int p[30], q[30];
char str[99];
 
inline int bin2int(char *str, int n){
	int res = 0;
	rep(i,0,n-1) res = res * 2 + str[i] - '0';
	return res;
}
 
inline int swapbit(int x, int p[]){
	int y = 0;
	rep(i,1,k) y += (x>>k-p[i]&1)<<k-i;
	return y;
}
 
void dfs(int x, int idx, int dp[]){
	if (~dp[x]) return;
	dp[x] = idx;
	rep(i,0,k-1) if(x>>i&1)
		dfs(x-(1<<i), idx, dp);
}
 
int main() {
    scanf("%d%d%d\n", &n, &m, &k);
    scanf("%s\n", str), s[0] = bin2int(str, k);
    scanf("%s\n", str), t[0] = bin2int(str, k);
    
    rep(i,1,k) p[i] = i;
    rep(i,1,n){
    	scanf("%d%d",&x,&y);
    	rep(j,1,k) q[j] = j;
    	swap(q[x], q[y]);
    	rep(j,1,k) p[j] = q[p[j]];
    	
    	s[i] = swapbit(s[0], p);
    	t[i] = swapbit(t[0], p);    	
	}
	
	rep(i,0,1<<k) l[i] = r[i] = -1;
	rep(i,0,n) dfs(s[i], i, l);
	rrep(i,n,0) dfs(t[i], i, r);
	
	int ans = 0, ansl = 1, ansr = n;
	rep(i,0,(1<<k)-1) if(~l[i] && ~r[i] && r[i] - l[i] >= m && nbit(i) > ans)
		ans = nbit(i), ansl = l[i]+1, ansr = r[i];
	printf("%d\n%d %d",ans*2+k-nbit(s[0])-nbit(t[0]), ansl, ansr);
    return 0;
}