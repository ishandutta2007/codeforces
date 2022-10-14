#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, p;
ll pr[1005000], a[100500];
vector<ll> divis, divis1;
ll dp[1005000];
int main() {
    //freopen("input.txt","r",stdin);
    for (int i = 2; i <= 1000000; i++)
        pr[i] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (pr[i]) {
            for (int j = i*2; j <= 1000000; j += i)
                pr[j] = 0;
        }
    }

    dp[0] = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        divis.clear();
        divis1.clear();

        for (int j = 1; j*j <= x; j++) {
            if (x % j == 0) {
                divis.push_back(j);
                if (j * j != x)
                    divis1.push_back(x/ j);
            }
        }
        reverse(divis.begin(), divis.end());
        for (int j = 0; j < divis1.size(); j++) {
            ll v = divis1[j];
            dp[v] += dp[v-1];
            if (dp[v] >= MOD)
                dp[v] -= MOD;
        }

        for (int j = 0; j < divis.size(); j++) {
            ll v = divis[j];
            dp[v] += dp[v-1];
            if (dp[v] >= MOD)
                dp[v] -= MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dp[i];
    cout << ans % MOD << endl;



    return 0;
}