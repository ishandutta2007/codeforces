#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, bsl, bsm, bsu, d;
string s;
vector<int> v1, v2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        v1.clear();
        v2.clear();
        cin >> n >> s;
        check1 = 0;
        for (i = 0; i < n; i++) {
            d = (int)s[i];
            d -= 48;
            if (check1 == 0) {
                v1.push_back(d / 2);
                v2.push_back((d + 1) / 2);
            } else {
                v1.push_back(d);
                v2.push_back(0);
            }
            if (d % 2 != 0) {
                check1 = 1;
            }
        }
        for (auto u : v1) {
            cout << u;
        }
        cout << endl;
        for (auto u : v2) {
            cout << u;
        }
        cout << endl;
    }

    return 0;
}