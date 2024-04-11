#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 4e3 + 5;
const int mod = 998244353;

#define int long long

int Pow(int x , int y) {
    if(!x) return 0;
    if(!y) return 1;
    if(x < 0) x += mod;
    if(y == 1) return x;
    int it = Pow(x , y >> 1);
    it = it * it % mod;
    if(y & 1) it = it * x % mod;
    return it;
}

int ans[N] , strong[N] , cp[N][N] , Z[N] , F[N] , x , y;
bool vis[N] , vis2[N] , vis3[N][N];

int CP(int x , int y) {
    if(!y) return 1;
    if(y > x) return 0;
    if(vis3[x][y]) return cp[x][y];
    vis3[x][y] = 1;
    cp[x][y] = CP(x - 1 , y - 1) * Z[x - y] % mod + CP(x - 1 , y) * F[y] % mod;
    cp[x][y] %= mod;
    return cp[x][y];
}

int Str(int x) {
    if(vis2[x])return strong[x];
    if(x == 1) return 1;
    strong[x] = 1; vis2[x] = 1;
    for(int i = 1;i < x;++ i) strong[x] = (strong[x] + mod - Str(i) * CP(x , i) % mod) % mod;
    return strong[x];
}

#define inv(x) Pow(x , mod - 2)

int getans(int x) {
    if(x == 1 || x == 0) return 0ll;
    if(vis[x]) return ans[x];
    vis[x] = 1; ans[x] = 0;
    for(int i = 1;i < x;++ i) {
	ans[x] += Str(i) * CP(x , i) % mod *(((i - 1) * i / 2 % mod + (x - i) * i % mod + getans(i) + getans(x - i) % mod) % mod) % mod;
    }
    ans[x] = ans[x] + Str(x) % mod * (((((x - 1) * x) / 2 % mod)) % mod) % mod;
    ans[x] = ans[x] % mod * inv(mod + 1 - Str(x) * CP(x , x) % mod) % mod;
    return ans[x];
}

signed main(void) {
    int n , P;
    cin >> n >> x >> y; P = x * inv(y) % mod;
    F[0] = Z[0] = 1;
    for(int i = 1;i <= n;++ i) {
	F[i] = F[i - 1] * (mod + 1 - P) % mod;
	Z[i] = Z[i - 1] * P % mod;
    }
    cout << getans(n);
}