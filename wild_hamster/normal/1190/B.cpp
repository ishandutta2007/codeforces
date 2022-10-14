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
ll n, m, k, x, y, z;
ll a[200500];
string ans[2] = {"sjfnb", "cslnb"};
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {

        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && a[i] == a[i+1]) {
            a[i]--;
            break;
        }
    }
    if (a[0] == -1) {
        cout << ans[1] << endl;
        return 0;
    }
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] == a[i+1]) {
            cout << ans[1] << endl;
            return 0;
        }
    }
    cout << ans[(sum - (n*(n-1)/2) + 1) & 1] << endl;
    return 0;
}