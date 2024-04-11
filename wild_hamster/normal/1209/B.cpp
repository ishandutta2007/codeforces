#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 300500
#define MOD 998244353
ll n, x, k, z, m, pos, q;

ll a[200500], b[200500], d[150];

set<pii> f;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    for (int i = 0 ;i < n; i++) {
        d[i] = s[i] - '0';
        ans += d[i];

    }
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= 100000; i++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            if (i >= b[j] && (i-b[j]) % a[j] == 0) {
                d[j] ^= 1;
            }
            sum += d[j];
        }
        ans = max(ans, sum);

    }
    cout << ans << endl;



    return 0;
}