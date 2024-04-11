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
string g = "+*";

bitset<512> v[512][512];

void solve(int i) {
        if(i == 0) return;
        solve(i - 1);
        for(int j = 0; j < (1 << (i - 1)); j++)
                for(int k = 0; k < (1 << i); k++)
                        v[i][j][k] = v[i - 1][j][k >> 1];
        for(int j = 0; j < (1 << (i - 1)); j++)
                for(int k = 0; k < (1 << i); k++)
                        v[i][j + (1 << (i - 1))][k] = v[i - 1][j][k >> 1] ^ (k & 1);
}

int main() {
        int i, j, n;
        scanf("%d", &n);
        solve(n);
        for(i = 0; i < (1 << n); i++) {
                for(j = 0; j < (1 << n); j++)
                        putchar(g[v[n][i][j]]);
                putchar('\n');
        }
}