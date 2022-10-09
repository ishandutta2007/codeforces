#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a[2010], countl[2010], b, pos, digits[10], countd[10];
bitset<2010> possible[2010];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> s;
        a[i] = 0;
        countl[i] = 0;
        for (j = 0; j < 7; j++) {
            if (s[6 - j] == '1') {
                a[i] += (1 << j);
                countl[i]++;
            }
        }
    }
    string dinitial[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    for (i = 0; i < 10; i++) {
        digits[i] = 0;
        for (j = 0; j < 7; j++) {
            if (dinitial[i][6 - j] == '1') {
                digits[i] += (1 << j);
                countd[i]++;
            }
        }
    }

    possible[n][0] = 1;
    for (i = n - 1; i >= 0; i--) {
        // cout << "i = " << i << endl;
        for (j = 0; j < 10; j++) {
            if ((a[i] & digits[j]) == a[i]) {
                // cout << j << ' ' << (countd[j] - countl[i]) << endl;
                for (k1 = 0; k1 <= 2000; k1++) {
                    if (possible[i + 1][k1]) {
                        if (k1 + (countd[j] - countl[i]) <= 2000) {
                            // cout << k1 + (countd[j] - countl[i]) << endl;
                            possible[i][k1 + (countd[j] - countl[i])] = 1;
                        }
                    }
                }
                //possible[i] |= (possible[i + 1] >> (countd[j] - countl[i]));
            }
        }
        /* for (j = 0; j < 20; j++) {
            cout << possible[i][j] << ' ';
        }
        cout << endl; */
    }

    if (possible[0][k] == 0) {
        cout << -1;
        return 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 9; j >= 0; j--) {
            if ((countd[j] - countl[i]) <= k) {
                if ((a[i] & digits[j]) == a[i] && possible[i + 1][k - (countd[j] - countl[i])] == 1) {
                    cout << j;
                    k -= (countd[j] - countl[i]);
                    break;
                }
            }
        }
    }

    return 0;
}