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
const int N = 100009;
int a[N], b[N], mx[N][21];
int get(int i, int j) {
        int e = 31 - __builtin_clz(j - i + 1);
        if(b[mx[i][e]] > b[mx[j - (1 << e) + 1][e]])
                return mx[i][e];
        else return mx[j - (1 << e) + 1][e];
}

ll solve(int i, int j) {
        if(j < i) return 0;
        int k = get(i, j);
        return ll(b[k]) * ll(k - i + 1) * ll(j - k + 1) + solve(i, k - 1) + solve(k + 1, j);
}

int main() {
        int i, n, q, l, r, j;
        scanf("%d %d", &n, &q);
        for(i = 0; i < n; i++)
                scanf("%d", &a[i]);
        for(i = 0; i < n - 1; i++)
                b[i] = abs(a[i + 1] - a[i]);
        n--;
        for(i = 0; i < n; i++)
                mx[i][0] = i;
        for(j = 1; j < 20; j++)
                for(i = 0; i < n; i++) {
                        if(i + (1 << (j - 1)) >= n) { mx[i][j] = mx[i][j - 1]; continue; }
                        if(b[mx[i][j-1]] > b[mx[i + (1 << (j - 1))][j-1]])
                                mx[i][j] = mx[i][j-1];
                        else
                                mx[i][j] = mx[i + (1 << (j - 1))][j - 1];
                }
        for(i = 0; i < q; i++) {
                scanf("%d %d", &l, &r); l--; r--;
                printf("%I64d\n", solve(l, r - 1));
        }
}