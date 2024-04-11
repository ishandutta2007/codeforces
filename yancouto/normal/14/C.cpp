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
void imp() { puts("NO"); exit(0); }

struct pt {
    int a, b, c;
} px[4], py[4];

int main() {
    int i, x1, x2, y1, y2;
    int xn = 0, yn = 0;
    for(i = 0; i < 4; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1 != x2 && y1 != y2) imp();
        if(x1 == x2 && y1 == y2) imp();
        if(y1 > y2) swap(y1, y2);
        if(x1 > x2) swap(x1, x2);
        if(x1 == x2)
            px[xn++] = {x1, y1, y2};
        else
            py[yn++] = {y1, x1, x2};
    }
    if(xn != 2 || yn != 2) imp();
    if(px[0].b != px[1].b || px[0].c != px[1].c) imp();
    if(py[0].b != py[1].b || py[0].c != py[1].c) imp();
    if(px[0].a > px[1].a) swap(px[0], px[1]);
    if(py[0].a > py[1].a) swap(py[0], py[1]);
    if(px[0].b != py[0].a || px[0].c != py[1].a) imp();
    if(py[0].b != px[0].a || py[0].c != px[1].a) imp();
    puts("YES");
}