#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int N = 59;
int w[N];

int dist[N][N][2];
int k, nAA, nBB;
struct no {
    int nA, nB;
    bool right;
};
int solve() {
    memset(dist, -1, sizeof dist);
    queue<no> q;
    dist[nAA][nBB][false] = 0;
    q.push(no({nAA, nBB, false}));
    while(!q.empty()) {
        no x = q.front(); q.pop();
        if(x.nA == 0 && x.nB == 0) return dist[x.nA][x.nB][x.right];
        if(!x.right) {
            for(int a = 0; a <= x.nA && a <= k; a++)
                for(int b = 0; b <= x.nB && a + 2*b <= k; b++)
                    if((a || b) && dist[x.nA - a][x.nB - b][true] == -1) {
                        dist[x.nA - a][x.nB - b][true] = dist[x.nA][x.nB][x.right] + 1;
                        q.push(no({x.nA - a, x.nB - b, true}));
                    }
        } else {
            for(int a = 0; a <= nAA - x.nA && a <= k; a++)
                for(int b = 0; b <= nBB - x.nB && a + 2*b <= k; b++)
                    if((a || b) && dist[x.nA + a][x.nB + b][false] == -1) {
                        dist[x.nA + a][x.nB + b][false] = dist[x.nA][x.nB][x.right] + 1;
                        q.push(no({x.nA + a, x.nB + b, false}));
                    }
        }
    }
    return -1;
}

ll c[N][N];
ll comb(int n, int p) {
    if(n < 0 || p < 0 || p > n) return 0;
    if(p == 0) return 1;
    ll &r = c[n][p];
    if(r != -1) return r;
    r = mod(comb(n - 1, p) + comb(n - 1, p - 1));
    return r;
}

ll countr[N][N][2], countl[N][N][2];
int main() {
    memset(c, -1, sizeof c);
    int i, n;
    scanf("%d %d", &n, &k); k /= 50;
    for(i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        w[i] /= 50;
        if(w[i] == 1) nAA++;
        else nBB++;
    }
    int mn = solve();
    if(mn < 0) { printf("-1\n0\n"); return 0; }
    else printf("%d\n", mn);
    countl[0][0][0] = countr[0][0][0] = 1;
    for(int mv = 1; mv <= mn; mv++)
        for(int nA = 0; nA <= nAA; nA++)
            for(int nB = 0; nB <= nBB; nB++) {
                countl[nA][nB][mv&1] = countr[nA][nB][mv&1] = 0;
                for(int a = 0; a <= nA && a <= k; a++)
                    for(int b = 0; b <= nB && a + 2*b <= k; b++)
                        if(a || b)
                            countl[nA][nB][mv&1] += mod(comb(nA, a) * mod(comb(nB, b) * countr[nA - a][nB - b][!(mv&1)]));
                for(int a = 0; a <= nAA - nA && a <= k; a++)
                    for(int b = 0; b <= nBB - nB && a + 2*b <= k; b++)
                        if(a || b)
                            countr[nA][nB][mv&1] += mod(comb(nAA - nA, a) * mod(comb(nBB - nB, b) * countl[nA + a][nB + b][!(mv&1)]));
                countl[nA][nB][mv&1] %= modn; countr[nA][nB][mv&1] %= modn;
            }
    printf("%d\n", (int) countl[nAA][nBB][mn&1]);
}