#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, p2[40];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    p2[0] = 1;
    for (i = 1; i <= 30; i++) {
        p2[i] = p2[i - 1] * 2;
    }
    while (t--) {
        cin >> n;
        cout << p2[n / 2 + 1] - 2 << endl;
    }

    return 0;
}