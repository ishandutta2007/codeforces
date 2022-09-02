#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 2e5 + 5;

struct ele {
    int l, r;
    bool operator < (const ele A) const { return l < A.l; }
} t[N * 4];

int a[N], b[N];
int n, k, tot; ll sum;

int main() {
    read(n); read(k);
    for (int i = 1; i <= k; i++) {
        read(a[i]); read(b[i]);
        sum += b[i];
    }
    if (sum > n) {
        puts("-1");
        return 0;
    }
    if (sum < n) {
        puts("1");
        return 0;
    }
    sum = 0;
    for (int i = 1; i <= k; i++) sum = (sum + 1ll * a[i] * b[i]) % n;
    if (sum == (1ll * n * (n + 1) / 2) % n) puts("1");
    else puts("-1");
    return 0;
}