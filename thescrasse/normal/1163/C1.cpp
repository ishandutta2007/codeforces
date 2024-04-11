// 1163C2
// numero di intersezioni tra rette

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, x[1010], y[1010], tot;
vector<array<long long, 3>> p;

long long gcd(long long a, long long b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

array<long long, 3> eq(long long A, long long B) {
    long long a, b, c, g;
    a = y[A] - y[B];
    b = x[A] - x[B];
    if (a < 0 || (a == 0 && b < 0)) {
        a *= -1; b *= -1;
    }
    g = gcd(a, b); a /= g; b /= g;
    c = (long long)a * x[A] - b * y[A];
    return {a, b, c};
}

long long binom(long long a) {
    return (a * (a - 1)) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                p.push_back(eq(i, j));
            }
        }
    }

    sort(p.begin(), p.end());

    res = 0;
    k = 1;
    tot = 1;
    for (i = 1; i < p.size(); i++) {
        if (p[i] == p[i - 1]) {
            continue;
        }
        if (p[i][0] == p[i - 1][0] && p[i][1] == p[i - 1][1]) {
            tot++; k++;
        } else {
            res -= binom(k); k = 1; tot++;
        }
    }

    res -= binom(k);
    res += binom(tot);
    cout << res;

    return 0;
}