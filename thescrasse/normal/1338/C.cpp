#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, gruppo, riga, sezione, tot, base4[50], p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        n--;
        gruppo = n % 3;
        riga = n / 3;
        //cout << riga << endl;
        sezione = 1;
        k = 1;
        tot = 0;
        while (tot + k <= riga) {
            tot += k;
            k *= 4;
            sezione++;
        }
        riga -= tot;
        //cout << gruppo << ' ' << sezione << ' ' << riga << endl;
        k = 0;
        while (riga != 0) {
            base4[k] = riga % 4;
            riga /= 4;
            k++;
        }

        if (gruppo == 0) {
            res = 3 * tot + 1;
            for (i = 0; i < k; i++) {
                if (base4[i] == 0) {
                    base4[i] = 0;
                } else if (base4[i] == 1) {
                    base4[i] = 1;
                } else if (base4[i] == 2) {
                    base4[i] = 2;
                } else {
                    base4[i] = 3;
                }
            }
        } else if (gruppo == 1) {
            res = 6 * tot + 2;
            for (i = 0; i < k; i++) {
                if (base4[i] == 0) {
                    base4[i] = 0;
                } else if (base4[i] == 1) {
                    base4[i] = 2;
                } else if (base4[i] == 2) {
                    base4[i] = 3;
                } else {
                    base4[i] = 1;
                }
            }
        } else {
            res = 9 * tot + 3;
            for (i = 0; i < k; i++) {
                if (base4[i] == 0) {
                    base4[i] = 0;
                } else if (base4[i] == 1) {
                    base4[i] = 3;
                } else if (base4[i] == 2) {
                    base4[i] = 1;
                } else {
                    base4[i] = 2;
                }
            }
        }
        p = 1;
        for (i = 0; i < k; i++) {
            res += (p * base4[i]);
            p *= 4;
        }

        cout << res << endl;
    }

    return 0;
}