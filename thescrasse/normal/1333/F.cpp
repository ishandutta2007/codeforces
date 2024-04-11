// 1333F
// minimo gcd massimo tra coppie di un sottoinsieme grande k di {1, ..., n}

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, er[500010];
vector<long long> r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;

    for (i = 2; i <= n; i++) {
        er[i] = i;
    }
    for (i = 2; i <= n; i++) {
        if (er[i] == i) {
            for (j = 2 * i; j <= n; j += i) {
                if (er[j] == j) {
                    er[j] = i;
                }
            }
        }
    }

    for (i = 2; i <= n; i++) {
        r.push_back(i / er[i]);
    }

    sort(r.begin(), r.end());
    for (auto u : r) {
        cout << u << ' ';
    }

    return 0;
}