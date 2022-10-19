#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
const int mod = 1e9 + 7;

void sub(int &x , int y);

void add(int &x , int y) {
    sub(y , 0);
    x = (x + y); if(x >= mod) x -= mod;
}

void sub(int &x , int y) {
    x -= y; if(x < 0) x += mod;
}

vector <int> G[N];

int dp[N] , n , k;

int Pow(int x , int y) {
    if(!y) return 1;
    if(y == 1) return x;
    int it = Pow(x , y >> 1);
    it = it * 1ll * it % mod;
    if(y & 1) it = it * 1ll * x % mod;
    return it;
}

int main(void) {
    scanf("%d%d" , &n , &k);
    for(int i = 1;i <= k;++ i) {
	for(int j = i * 2;j <= k;j += i) {
	    G[j].push_back(i);
	}
    }
    dp[1] = 1; int ans = 0 , S = 0;
    for(int i = 2;i <= k;++ i) {
	dp[i] = Pow(i , n);
	for(int j = 0;j < (int) G[i].size();++ j) add(S , dp[G[i][j]] - dp[G[i][j] - 1]);
	sub(dp[i] , S);
	add(ans , dp[i] ^ i);
    }
    cout << ans;
}