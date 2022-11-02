#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 200100, M = 1000010, mod = 1e9 + 7;
LL f[N], inv[N], f2[N], mu[M], vis[M], prime[N], c[M], s[M];
vector <int> g[M];

LL C (int x, int y) {
    if (x < y) return 0;
    return f[x] * f2[y] % mod * f2[x - y] % mod;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k, q;
    cin >> n >> k >> q;
    f[0] = f[1] = inv[0] = inv[1] = f2[0] = f2[1] = 1;
    for (int i = 2; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        f2[i] = f2[i - 1] * inv[i] % mod;
    }
    for (int i = 1; i < M; i++) {
        for (int j = i; j < M; j += i) {
            g[j].push_back (i);
        }
    }
//    return 0;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf ("%d", &a);
        for (int j = 0; j < g[a].size(); j++) {
            c[g[a][j]]++;
        }
    }
    mu[1]=1;
    int primes=0;
    for(int i=2;i<M;i++)
    {
        if(!vis[i])
            prime[primes++]=i,mu[i]=-1;
        for(int j=0;j<primes&&i*prime[j]<M;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j])
                mu[i*prime[j]]=-mu[i];
            else
            { mu[i*prime[j]]=0;break;}
        }
    }
//    return 0;
    LL res = 0;
    for (int i = 1; i < M; i++) {
        LL tmp = 0;
        for (int j = 1; i * j < M; j++) if (mu[j]) {
            s[i * j] += mu[j] * i;
            s[i * j] %= mod;
        }
    }
//    res = 0;
    for (int i = 1; i < M; i++) {
        res += s[i] * C (c[i], k) % mod;
    }
    while (q--) {
        int a;
        scanf ("%d", &a);
        for (int j = 0; j < g[a].size(); j++) {
            res -= s[g[a][j]] * C (c[g[a][j]], k) % mod;
            c[g[a][j]]++;
            res += s[g[a][j]] * C (c[g[a][j]], k) % mod;
        }
        res = (res % mod + mod) % mod;
        printf ("%d\n", res);
    }
//    cout << res << endl;
//    for (int i = 1; i <= 10; i++) cout << s[i] << ' ' << mu[i] << endl;
//    for (int i = )
//    cout <<res << endl;
}