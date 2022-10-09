// 1322B
// xor delle somme a coppie

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a[400010], b, p[400010];

long long twop(long long s) {
    long long i, l, r, res;
    // cout << "s = " << s << endl;
    l = 0;
    r = n - 1;
    res = 0;
    while (l < n && r >= 0) {
        // cout << l << ' ' << r << ' ' << p[l] + p[r] << endl;
        if (p[l] + p[r] >= s) {
            r--;
        } else {
            l++;
            res += (n - r - 1);
            // cout << "res = " << res << endl;
        }
    }
    if (r == -1) {
        res += (n * (n - l));
    }
    // cout << "res_f = " << res << endl;
    for (i = 0; i < n; i++) {
        if (2 * p[i] >= s) {
            res--;
        }
    }
    // cout << "res_f = " << res << endl;
    res /= 2;
    // cout << "res = " << res << endl;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    res = 0;
    for (i = 0; i < 28; i++) {
        for (j = 0; j < n; j++) {
            p[j] = a[j] % (2 << i);
        }
        sort(p, p + n);
        k = twop(1 << i) - twop(2 << i) + twop(3 << i);
        if (k % 2 == 1) {
            res += (1 << i);
        }
    }

    cout << res;

    return 0;
}