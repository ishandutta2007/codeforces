#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

const int maxn = 5010;

int a[maxn];
int b[maxn];
set <int> bad;
bool used[32000];

int gcd(int x, int y) {
    while (y != 0) {
        int t = x % y;
        x = y;
        y = t;
    }
    return x;
}

int go(int pos) {
    if (pos == 0) {
        return a[0];
    }
    return gcd(go(pos - 1), a[pos]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        if (b[i] < 32000) {
            used[b[i]] = true;
        } else {
            bad.insert(b[i]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int g = go(i);
        int d = g;
        int ans = 0;
        for (int j = 2; j * j <= d; j++) {
            if (d % j == 0) {
                int delta = 1;
                if (used[j]) {
                    delta = -1;
                }
                while (d % j == 0) {
                    d /= j;
                    ans += delta;
                }
            }
        }
        if (d != 1) {
            if ((d < 32000 && used[d]) || bad.count(d)) {
                ans--;
            } else {
                ans++;
            }
        }
        if (ans >= 0) {
            continue;
        }
        for (int j = 0; j <= i; j++) {
            a[j] /= g;
        }
    }
    int slim = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                int delta = 1;
                if (used[j]) {
                    delta = -1;
                }
                while (a[i] % j == 0) {
                    a[i] /= j;
                    slim += delta;
                }
            }
        }
        if (a[i] != 1) {
            if ((a[i] < 32000 && used[a[i]]) || bad.count(a[i])) {
                slim--;
            } else {
                slim++;
            }
        }
    }
    printf("%d", slim);
    return 0;
}