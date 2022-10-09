#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a, b;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    s = "qwertyuiopasdfghjklzxcvbnm";

    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        for (i = 0; i < n; i++) {
            cout << s[i % b];
        }
        cout << endl;
    }

    return 0;
}