#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
#define pii pair<ll,ll>

typedef long long ll;
using namespace std;
#define MAXN 1488228
#define LOG 21
ll x, y, n, m, k, i, j, q, w, N;
ll cur[MAXN * 2], pres[MAXN], a[MAXN], t[MAXN * 2];

vector<ll> f;

ll process(ll x) {
    ll sum = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        if (((x >> i) & 1) == 0 && cur[(1<<i) | sum] >= 2) {
            sum |= (1<<i);
        }
    }
    return (x | sum);
}

void add(ll x, ll pos) {
    if (cur[x] == 2) {
        return;
    }
    cur[x]++;
    while (pos < LOG) {
        if ((x >> pos) & 1) {
            add(x ^ (1<<pos), pos + 1);
        }
        pos++;
    }
}

int main() {
    cin.tie(0);  ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (i < n - 2) {
            ans = max(ans, process(a[i]));
        }
        add(a[i], 0);
    }
    cout << ans << endl;
    return 0;
}