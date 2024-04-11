#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
    valarray<int> a(n + 1);
    valarray<int> b(n + 1);
    a[1] = 1;
    b[0] = 1;

    for (int i = 1; i < n; i++) {
        valarray<int> c = b + a.shift(-1);
        if (c.max() > 1 || c.min() < -1)
            c = b - a.shift(-1);
        assert(c.max() <= 1 && c.min() >= -1);
        b = a;
        a = c;
    }

    if (a[n] != 1)
        a = -a;
    if (b[n - 1] != 1)
        b = -b;

    printf("%d\n", n);
    for (int i = 0; i <= (int) n; i++)
        printf("%d%c", a[i], i == (int) a.size() - 1 ? '\n' : ' ');
    printf("%d\n", n - 1);
    for (int i = 0; i < (int) n; i++)
        printf("%d%c", b[i], i == (int) b.size() - 1 ? '\n' : ' ');
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n);
}