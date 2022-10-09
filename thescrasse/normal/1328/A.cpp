#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

   // ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        cin >> a >> b;
        cout << (b - (a % b)) % b << endl;
    }

    return 0;
}