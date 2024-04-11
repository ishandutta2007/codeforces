#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, p[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    p[0] = 1;
    for (i = 1; i < 50; i++) {
        p[i] = 2 * p[i - 1] + 1;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        k = 1;
        while (n % p[k] != 0) {
            k++;
        }
        cout << n / p[k] << endl;
    }

    return 0;
}