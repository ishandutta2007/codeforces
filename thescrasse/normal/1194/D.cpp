// 1328D
// carosello

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, check2, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        cin >> n >> k;
        if (k % 3 != 0) {
            if (n % 3 == 0) {
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
        } else {
            n = n % (k + 1);
            if (n % 3 == 0 && n != k) {
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
        }
    }

    return 0;
}