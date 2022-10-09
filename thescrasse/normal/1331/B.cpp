#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            cout << i << n / i;
            break;
        }
    }

    return 0;
}