#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll a[10050], u[10050], dp[1050000], b[MAXN+555];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        ll mask = 0;
        for (int j = i; j < i + 20 && j < n; j++) {
            ll c = s[j] - 'a';
            if (((mask >> c) & 1) == 0) {
                mask |= (1<<c);
                dp[mask] = j - i + 1;
                b[mask] = j - i + 1;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < 20; j++) {
            if (((i >> j) & 1) == 0) {
                dp[i | (1<<j)] = max(dp[i | (1<<j)], dp[i]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < MAXN; i++) {
        ans = max(ans, dp[i] + b[MAXN - 1 - i]);
    }
    cout << ans << endl;




    return 0;
}