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
const int N = 505;
char g[N][N];
int ar[N][N], ad[N][N];

int acc(int A[N][N], int i1, int i2, int j1, int j2) {
        int tot = A[i2][j2];
        if(i1) tot -= A[i1 - 1][j2];
        if(j1) tot -= A[i2][j1 - 1];
        if(i1 && j1) tot += A[i1 - 1][j1 - 1];
        return tot;
}

int main() {
        int i, j, n, m, q, i1, i2, j1, j2;
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
                for(j = 0; j < m; j++)
                        scanf(" %c", &g[i][j]);
        for(i = 0; i < n; i++)
                for(j = 0; j < m; j++) {
                        ar[i][j] += (g[i][j] == '.') && (g[i][j + 1] == '.');
                        ad[i][j] += (g[i][j] == '.') && (g[i + 1][j] == '.');
                        if(i) ar[i][j] += ar[i - 1][j], ad[i][j] += ad[i - 1][j];
                        if(j) ar[i][j] += ar[i][j - 1], ad[i][j] += ad[i][j - 1];
                        if(i && j) ar[i][j] -= ar[i - 1][j - 1], ad[i][j] -= ad[i - 1][j - 1];
                }
        scanf("%d", &q);
        for(i = 0; i < q; i++) {
                scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
                i1--; i2--; j1--; j2--;
                if(i1 > i2) swap(i1, i2);
                if(j1 > j2) swap(j1, j2);
                int tot = 0;
                if(j1 != j2) tot += acc(ar, i1, i2, j1, j2 - 1);
                if(i1 != i2) tot += acc(ad, i1, i2 - 1, j1, j2);
                printf("%d\n", tot);
        }
}