#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;

int where[N], a[N], b[N], n, m;
int inv[N], period;

long long calc(long long x) {
    long long ans = x;
    for (int i = 0; i < m; ++i) {
        if (where[b[i]] != -1) {
            int index = inv[((where[b[i]] - i) % n + n) % n];
            if (index != -1) {
                ans -= x / m / period + (index < x / m % period);
            }
        }
    }
    for (long long i = x - x % m; i < x; ++i) {
        ans -= a[i % n] == b[i % m];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    cin >> n >> m >> k;

    fill(where, where + N, -1);
    fill(inv, inv + N, -1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        where[a[i]] = i;
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int i = 0;
    do {
        inv[i] = period++;
        i = (i + m) % n;
    } while (i != 0);

    long long l = 1, r = k * max(n, m);
    while (l < r) {
        long long days = (l + r) / 2;
        if (calc(days) < k) {
            l = days + 1;
        } else {
            r = days;
        }
    }

    cout << l << "\n";
}