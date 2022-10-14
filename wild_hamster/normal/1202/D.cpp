#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 1000000007
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 4005
ll x, y;
ll a[15][15];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll x;
        for (int i = 1; i <= n + 100; i++) {
            if (i * (i+1) / 2 > n) {
                x = i;
                break;
            }
        }
        ll diff = n - x * (x - 1) / 2;
        cout << 133;
        for (int i = 0; i < diff; i++) {
            cout << 7;
        }
        for (int i = 0; i < x-2; i++) {
            cout << 3;
        }
        cout << 7 << endl;
    }
    return 0;
}