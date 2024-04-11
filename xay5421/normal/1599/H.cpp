#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e9;

int query(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ans; read(ans); return ans;
}

int main() {
    int l = 1, val_l = query(1, l), r = N, val_r = query(1, r);
    int mnx = 0;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        int val = query(1, mid);
        if (val_l == val_r && val_l == val) {
            mnx = val;
            break;
        }
        if (val_l > val_r) {
            l = mid; val_l = val;
        } else {
            r = mid; val_r = val;
        }
    }
    if (!mnx) mnx = min(val_l, val_r);
    ++mnx;
    int mny = query(1, 1) - mnx + 2;
    int mxy = N - (query(1, N) - mnx + 1);
    int mxx = N - (query(N, 1) - mny + 1);
    printf("! %d %d %d %d\n", mnx, mny, mxx, mxy);
    return 0;
}