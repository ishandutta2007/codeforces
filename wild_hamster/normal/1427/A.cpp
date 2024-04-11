
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
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 13
#define OFF 400001
#define MOD 1000000007
#define NN 1000000
ll n, m, k, x, y, w;
ll l[1005000], h[1005000], a[1005000];
ll Abs(ll x) {
    return x > 0 ? x : -x;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //srand(time(0));
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll x = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            x += a[i];
        }
        sort(a, a+n);
        if (x == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (x > 0) {
                reverse(a, a+n);
            }
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}