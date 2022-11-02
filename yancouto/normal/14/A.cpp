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

char g[100][100];
int main() {
    int i, j, n, m;
    scanf("%d %d", &n, &m);
    int mn_i = INT_MAX, mx_i = INT_MIN, mn_j = INT_MAX, mx_j = INT_MIN;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++) {
            scanf(" %c", &g[i][j]);
            if(g[i][j] != '*') continue;
            mn_i = min(mn_i, i);
            mx_i = max(mx_i, i);
            mn_j = min(mn_j, j);
            mx_j = max(mx_j, j);
        }
    for(i = mn_i; i <= mx_i; i++) {
        for(j = mn_j; j <= mx_j; j++)
            putchar(g[i][j]);
        putchar('\n');
    }
}