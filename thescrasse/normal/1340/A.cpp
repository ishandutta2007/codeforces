#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a[100010], b, pos;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        check1 = 1;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        k = n;
        pos = 0;
        for (i = 1; i < n; i++) {
            if (a[i] - a[i - 1] != 1) {
                if (a[i - 1] == k) {
                    k = a[pos] - 1;
                    pos = i;
                } else {
                    check1 = 0;
                }
            }
        }
        if (check1 == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}