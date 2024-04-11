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

ll a[200500], b[200500], p[50];

set<pii> f;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    for (int i = 1; i <= 100; i++) {
        if (b[i]) {
            for (int j = i; j <= 100 * i; j+=i) {
                b[j] = 0;
            }
            k++;
        }
    }
    cout << k << endl;

    return 0;
}