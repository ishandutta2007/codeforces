#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
const int MAX = 100009;
int n;
int a[MAX], win[2][MAX];

int test_t(int t) {
    int play = 0;
    int w[2] = {0, 0};
    while(true) {
        int nxt[2] = {(int)(lower_bound(win[0], win[0] + n + 1, win[0][play] + t) - win[0]),
                      (int)(lower_bound(win[1], win[1] + n + 1, win[1][play] + t) - win[1])};
        if(nxt[0] == nxt[1] && nxt[0] == n + 1) return 0;
        bool won = nxt[1] < nxt[0];
        w[won]++;
        if((play = min(nxt[0], nxt[1])) == n) {
            if(w[won] > w[!won]) return w[won];
            return 0;
        }
    }
}

int main() {
    int i;
    scanf(" %d", &n);
    for(i = 1; i <= n; i++) {
        scanf(" %d", &a[i]);
        win[--a[i]][i]++;
        win[0][i] += win[0][i - 1];
        win[1][i] += win[1][i - 1];
    }
    vector<pii> sols;
    for(i = 1; i <= n; i++)
        if(int aux = test_t(i))
            sols.pb(pii(aux, i));
    printf("%d\n", (int) sols.size());
    sort(sols.begin(), sols.end());
    for(pii p : sols)
        printf("%d %d\n", p.fst, p.snd);
    return 0;
}