#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a[1010], b, c[1010];
vector<long long> pr;
map<long long, long long> f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    pr = {-1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        f.clear();
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        k = 1;
        for (i = 0; i < n; i++) {
            for (j = 1; j <= 11; j++) {
                if (a[i] % pr[j] == 0) {
                    if (f[j] == 0) {
                        f[j] = k;
                        k++;
                    }
                    c[i] = f[j];
                    break;
                }
            }
        }
        cout << k - 1 << endl;
        for (i = 0; i < n; i++) {
            cout << c[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}