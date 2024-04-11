#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int  n , m , x , y , dp[N] , all[N] , nxt[N] , Phi;
vector <int> G[N];
bool vis[N];

int gcd(int x , int y) {
    return (!y) ? x : gcd(y , x % y);
}

int Pow(int x , int y , int mod) {
    if(x == 0) return 0;
    if(!y) return 1;
    if(y == 1) return x % mod;
    int it = Pow(x , y >> 1, mod);
    it = it * 1ll * it % mod;
    if(y &1) it = it * 1ll * x % mod;
    return it;
}

int inv[N] , phi[N] , pr[N] , cnt;

bool isp[N];

void predance(int n) {
    memset(isp , 1 , sizeof(isp));
    isp[1] = 0; phi[1] = 1;
    for(int i = 2;i <= n;++ i) {
	if(isp[i]) pr[++ cnt] = i , phi[i] = i - 1;
	for(int j = 1;j <= cnt && pr[j] * i <= n;++ j) {
	    isp[i * pr[j]] = 0;
	    if(i % pr[j] == 0) {
		phi[i * pr[j]] = phi[i] * phi[pr[j]] / (pr[j] - 1) * pr[j];
		break;
	    }
	    else {
		phi[i * pr[j]] = phi[i] * phi[pr[j]];
	    }
	}
    }
}

int Inv(int x , int y) {
    return Pow(x , phi[y] - 1 , y) % m;
}

void Go(int x , int las) {
    if(!x) return;
    for(int i = 0;i < (int)G[x].size();++ i) if(!vis[G[x][i]]) {
	    int V = G[x][i];
	    int G = gcd(las , m);
	    int p = las / G , q = V / G;
	    //cerr << V <<" ";
	    printf("%d " , Inv(p , m / G) * 1ll * q % m);
	    las = V;
    }
    Go(nxt[x] , las);
} 

int main(void) {
    scanf("%d%d" , &n , &m);
    predance(m);
    for(int i = 0;i < m;++ i) {
	++ dp[gcd(i , m)]; G[gcd(i , m)].push_back(i);
    }
    for(int i = 1;i <= n;++ i) {
	scanf("%d" , &x);
	-- dp[gcd(m , x)]; vis[x] = 1;
    }
    for(int i = m;i >= 1;-- i) if(m % i == 0){
	all[i] = dp[i]; int mx = 0;
	for(int j = 2 * i;j <= m;j += i) if(m % j == 0){
	    if(dp[j] > mx) {
		mx = dp[j]; nxt[i] = j;
	    }
	}
	dp[i] += mx;
    }
    printf("%d\n" , dp[1]);
    Go(1 , 1);
}