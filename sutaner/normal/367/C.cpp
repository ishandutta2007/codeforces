#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 3000005
#define LL long long int
#define INF 2000000005
#define rep(i, l, r) for (register int i = l; i <= r; i++)
using namespace std;

int n, m;
int line[maxn];
int ct = 0;

struct ele{
    int x, y;
    ele(int x, int y) : x(x), y(y){}
    ele(){}
    bool operator < (const ele b) const{
        return y > b.y;
    }
}save[maxn];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("367C.in", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    rep(i, 1, m) scanf("%d%d", &save[i].x, &save[i].y);
    sort(save + 1, save + 1 + m);
    rep(i, 1, INF){
        if (i & 1) line[i] = ((LL) i * i - i + 2) >> 1;
        else line[i] = (LL) i * i >> 1;
        if (line[i] >= maxn) {
            ct = i;
            break;
        }
    }
    int pos = upper_bound(line + 1, line + 1 + ct, n) - line - 1;
    LL ans = 0;
    rep(i, 1, min(m, pos)) ans += save[i].y;
    printf("%I64d", ans);
    return 0;
}