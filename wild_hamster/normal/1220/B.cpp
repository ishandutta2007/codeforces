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
#define MAXN 30000
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q;


ll b[100500];
vector<ll> g, f;
ll a[1005][1005];

ll gcd(ll a, ll b) {
    return b == 0? a : gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    ll g = a[0][1];
    for (int i = 2; i < n; i++) {
        g = gcd(g, a[0][i]);
    }
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            ll d = i;
            if ((a[0][1] / d) * (a[0][2] / d) == a[1][2]) {
                cout << d;
                for (int i = 1; i < n; i++) {
                    cout << " " << a[0][i] / d;
                }
                cout << endl;
                return 0;
            }
            d = g / i;
            if ((a[0][1] / d) * (a[0][2] / d) == a[1][2]) {
                cout << d;
                for (int i = 1; i < n; i++) {
                    cout << " " << a[0][i] / d;
                }
                cout << endl;
                return 0;
            }
        }
    }

    return 0;
}