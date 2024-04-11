#include <bits/stdc++.h>

using namespace std;

int const P = 1234567;
int primes[P], np[P];

int const N = 1234567;
long long d[N];
pair<long long, long long> zd[N];
long long dp[N], ndp[N];


int main() {
    long long a;
    cin >> a;
    int cn = 0;
    for (long long i = 1; i * i <= a; i++) {
        if (a % i != 0) continue;
        d[cn++] = i;
        if (i * i != a) d[cn++] = a / i;
    }
    for (int i = 2; i * i < P; i++) {
        if (!np[i]) {
            for (int j = i * i; j < P; j += i) np[j] = 1;
        }
    }
    int pc = 0;
    for (int i = 2; i < P; i++) {
        if (!np[i])
            primes[pc++] = i;
    }
    sort(d, d + cn);
    fill(dp, dp + cn, 0);
    dp[0] = 1;
    int edgecount = 0;
    for (int i = 0; i < cn; i++) {
        if (d[i] <= 2) continue;
        long long f = d[i] - 1;
        int bad = 0;
        long long prime = -1;
        for (int j = 0; j < pc; j++) {
            if (f % primes[j] == 0) {
                while (f % primes[j] == 0) {
                    f /= primes[j];
                }
                bad = f != 1;
                prime = primes[j];
                break;
            }
        }
        if (prime < 0) prime = f;
        if (!bad) {
            zd[edgecount++] = {prime, d[i]};
        }
    }
    sort(zd, zd + edgecount);
    for (int i = 0; i < edgecount;) {
        int j = i;
        while (j < edgecount && zd[i].first == zd[j].first) ++j;
        for (int e = 0; e < cn; e++) ndp[e] = dp[e];
        while (i < j) {
            long long t = zd[i].second;
            for (int old = 0, where = 0; old < cn; old++) {
                if (1. * (double) d[old] * (double) t > 1e13) break;
                long long newValue = d[old] * t;
                while (where < cn && d[where] < newValue) ++where;
                if (where >= cn) break;
                if (d[where] == newValue) {
                    ndp[where] += dp[old];
                }
            }
            i++;
        }
        for (int e = 0; e < cn; e++) dp[e] = ndp[e];
    }
    cout << dp[cn - 1] << endl;
}