#include <string>
#include <time.h>
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

#define MOD 1000000007
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef int ll;
using namespace std;
#define MAXN 1488228
ll x, y, n;
ll a[150005], b[150005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b, b+n);
    for (int i = 0; i < n; i++) {
        for (int j = max(b[i]-1, 1); j <= b[i]+1; j++) {
            if (!a[j]) {
                a[j] = 1;
                break;
            }
        }
    }
    ll x = 0;
    for (int i = 0; i < 150003; i++) {
        x += a[i];
    }
    cout << x << endl;
    return 0;
}