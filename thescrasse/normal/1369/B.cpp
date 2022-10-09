#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, l;
string s, o;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> s;
        l = 0; flag[0] = 0; flag[1] = 0;
        while (l < n && s[l] == '0') {
            flag[0]++; l++;
        }
        l = n - 1;
        while (l >= 0 && s[l] == '1') {
            flag[1]++; l--;
        }
        for (i = 0; i < flag[0]; i++) cout << '0';
        if (flag[0] + flag[1] < n) cout << '0';
        for (i = 0; i < flag[1]; i++) cout << '1';
        cout << nl;
    }

    return 0;
}