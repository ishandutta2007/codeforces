#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define mp make_pair
#define MOD 1000000007
#define X first
#define Y second
using namespace std;

typedef int ll;
typedef pair<ll, ll> pii;

ll maxx, maxy, n;
int main() {
    ll x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll l, r, d;
        cin >> l >> r >> d;
        if (l > d) {
            cout << d << endl;
        } else {
            cout << d*((r+d)/d) << endl;
        }
    }

    return 0;
}