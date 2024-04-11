#include <bits/stdc++.h>
 
#define debug(...) fprintf(stderr ,__VA_ARGS__)
#define __FILE(x)\
	freopen(#x".in" ,"r" ,stdin);\
	freopen(#x".out" ,"w" ,stdout)
#define LL long long
 
const int MX = 2000 + 23;
 
LL MOD;
 
using namespace std;
 
int read(){
	char k = getchar(); int x = 0;
	while(k < '0' || k > '9') k = getchar();
	while(k >= '0' && k <= '9') x = x * 10 + k - '0' ,k = getchar();
	return x;
}
 
int head[MX] ,tot = 1;
struct edge{
	int node ,next;
}h[MX << 1];
void addedge(int u ,int v ,int flg = 1){
	// if(flg) debug("%d %d\n" ,u ,v);
	h[++tot] = (edge){v ,head[u]} ,head[u] = tot;
	if(flg) addedge(v ,u ,false);
}
 
int n ,dp[MX][MX] ,S[MX][MX] ,suf[MX][MX] ,pre[MX][MX];
void dapai(int x ,int f){
	int ch = 0;
	for(int i = head[x] ,d ; i ; i = h[i].next){
		if((d = h[i].node) == f) continue;
		dapai(d ,x);
	}
	for(int i = head[x] ,d ; i ; i = h[i].next){
		if((d = h[i].node) == f) continue;
		++ch;
		for(int j = 0 ; j <= n ; ++j){
			suf[ch][j] = pre[ch][j] = S[d][j];
		}
	}
 
	if(!ch){
		for(int i = 1 ; i <= n ; ++i){
			dp[x][i] = 1 % MOD;
			S[x][i] = (S[x][i - 1] + dp[x][i]) % MOD;
		}
		return ;
	}
	for(int j = 0 ; j <= n ; ++j){
		for(int i = 1 ; i <= ch ; ++i)
			pre[i][j] = 1LL * pre[i][j] * pre[i - 1][j] % MOD;
		for(int i = ch ; i >= 1 ; --i)
			suf[i][j] = 1LL * suf[i][j] * suf[i + 1][j] % MOD;
	}
	for(int i = 1 ; i <= n ; ++i) dp[x][i] = pre[ch][i];
	if(x != 1) for(int i = head[x] ,d ,c = 0 ; i ; i = h[i].next){
		if((d = h[i].node) == f) continue;
		++c;
		LL sum = 0;
		for(int mx = 1 ; mx <= n ; ++mx){
			dp[x][mx] = (dp[x][mx] + sum * dp[d][mx]) % MOD;
			sum = (sum + 1LL * pre[c - 1][mx] * suf[c + 1][mx]) % MOD;
		}
	}
	for(int i = 1 ; i <= ch ; ++i)
		for(int j = 0 ; j <= n ; ++j)
			suf[i][j] = pre[i][j] = 1 % MOD;
	for(int i = 1 ; i <= n ; ++i)
		S[x][i] = (S[x][i - 1] + dp[x][i]) % MOD;
}
 
int C[MX][MX];
void init(){
	for(int i = 0 ; i < MX ; ++i) C[i][0] = 1 % MOD;
	for(int i = 1 ; i < MX ; ++i)
		for(int j = 1 ; j < MX ; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
}
 
int main(){
    
    n = read() ,MOD = read();
	init();
	
	for(int i = 0 ; i < MX ; ++i)
		for(int j = 0 ; j < MX ; ++j)
			suf[i][j] = pre[i][j] = 1 % MOD;
			
	
	 
	for(int i = 2 ; i <= n ; ++i){
		addedge(read() ,read());
		// addedge(rand() % (i - 1) + 1 ,i);
	}
	
	dapai(1 ,0);
	
	for(int i = 1 ; i < n ; ++i){
		LL ans = 0;
		for(int j = 1 ; j <= i ; ++j){
			ans += ((i - j) & 1 ? -1LL : 1LL) * C[i][j] * dp[1][j] % MOD;
		}
		ans = (ans % MOD + MOD) % MOD;
		printf("%lld%c" ,ans ," \n"[i == n]);
	}
	return 0;
}