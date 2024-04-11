#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn (1 << 20) + 5
#define bit 20
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
using namespace std;

int n, m, d;
int line[maxn];

int num[maxn];
int now = 0;
int two[bit + 1];
int bitc[maxn];
int con;

bool vis[maxn];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("367D.in", "r", stdin);
    #endif

    two[0] = 1;
    rep(i, 1, bit) two[i] = two[i - 1] << 1;
    rep(i, 1, maxn - 1) bitc[i] = bitc[i >> 1] + (i & 1);
    
    int x, y;
    scanf("%d%d%d", &n, &m, &d);
    con = two[m] - 1;
    rep(i, 1, m){
        scanf("%d", &x);
        rep(j, 1, x) scanf("%d", &y), line[y] = i - 1;
    }

    rep(i, 1, d){
        if (!num[line[i]]) now ^= two[line[i]];
        num[line[i]]++;
    }
    vis[con - now] = 1;
    rep(i, d + 1, n){
        if (num[line[i - d]] == 1) now ^= two[line[i - d]];
        num[line[i - d]]--;
        if (!num[line[i]]) now ^= two[line[i]];
        num[line[i]]++;
        vis[con - now] = 1;
    }

    int ans = maxn;
    per(i, con, 0){
        if (vis[i]) {
            rep(j, 0, m - 1) if (i & two[j]) vis[i ^ two[j]] = 1;  
            continue;
        }
        ans = min(ans, bitc[i]);
    }

    printf("%d", ans);
    return 0;
}