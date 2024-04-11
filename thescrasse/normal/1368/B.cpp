#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, p2[80], q, r, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> k;
    c = 1; m = 0;
    while (c < k) {
        q = m / 10; r = m % 10;
        c /= (q + 1); c *= (q + 2); m++;
    }

    char ch[10] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
    q = m / 10; r = m % 10;
    for (j = 0; j < 10; j++) {
        for (i = 0; i < q + 1; i++) {
            cout << ch[j];
        }
        if (r > j) cout << ch[j];
    }

    return 0;
}