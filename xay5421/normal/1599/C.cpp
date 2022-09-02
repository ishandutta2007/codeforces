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

int n, pp; double p;

int main() {
    scanf("%d%lf", &n, &p); pp = (int)(p * 10000 + 0.5);
    for (int i = 0; i <= n; i++) {
        ll cnt = 1ll * n * (n - 1) * (n - 2) / 6;
        ll sum = 1ll * i * (i - 1) * (i - 2) / 3 + 1ll * i * (i - 1) * (n - i) + 1ll * i * (n - i) * (n - i - 1) / 2;
        if (5000 * sum >= cnt * pp) {
            print(i, '\n');
            return 0;
        }
    }
    return 0;
}