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
ll tot;
int xx[1000029], yy[1000029];
int *x, *y;
int n, m, cn, cm;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int op[256];
char s[500009];

ll t;
int px, py;
int mnx, mxx, mny, mxy;
void first() {
        int i;
        x[0] = y[0] = -1;
        for(i = 0; s[i]; i++) {
                px += dx[op[s[i]]];
                py += dy[op[s[i]]];
                if(x[px] == 0) {
                        x[px] = i + 1;
                        if(cm) tot = mod(tot + ll(cn) * ll(i + 1)), cm--;
                }
                if(y[py] == 0) {
                        y[py] = i + 1;
                        if(cn) tot = mod(tot + ll(cm) * ll(i + 1)), cn--;
                }
                mxx = max(mxx, px);
                mxy = max(mxy, py);
                mnx = min(mnx, px);
                mny = min(mny, py);
                if(!cn || !cm) { printf("%d\n", int(tot)); exit(0); }
        }
        if(px == 0 && py == 0) { puts("-1"); exit(0); }
}

void it() {
        int cx, cy, dx, dy;
        if(px >= 0) {
                dx = 1;
                cx = mxx - px + 1;
        } else {
                dx = -1;
                cx = mnx - px - 1;
        }
        if(py >= 0) {
                dy = 1;
                cy = mxy - py + 1;
        } else {
                dy = -1;
                cy = mny - py - 1;
        }
        while((cx >= mnx && cx <= mxx) || (cy >= mny && cy <= mxy)) {
                if(!(cx >= mnx && cx <= mxx) || ((cy >= mny && cy <= mxy) &&  y[cy] <= x[cx])) {
                        if(cn) tot = mod(tot + ll(cm) * ll(t + y[cy])), cn--;
                        cy += dy;
                } else {
                        if(cm) tot = mod(tot + ll(cn) * ll(t + x[cx])), cm--;
                        cx += dx;
                }
                if(!cn || !cm) { printf("%d\n", int(tot)); exit(0); }
        }
}

int main() {
        x = xx + 500009;
        y = yy + 500009;
        op['L'] = 3; op['R'] = 2;
        op['U'] = 1; op['D'] = 0;
        scanf("%d %d %d", &cn, &n, &m);
        swap(n, m);
        cn = n, cm = m;
        scanf("%s", s);
        int sn = strlen(s);
        first();
        t = sn;
        while(true) { it(); t = mod(t + sn); }
}