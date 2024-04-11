#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD ((1<<30)-1)
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, p, x;
ll  a[1500050], b[505000], pa[500500], dp[500500], ans;
ll Abs(ll x) {
    return x>0?x:-x;
}
string s[305];
int main() {
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i == 0)
            a[i] += (s[i] == '(' ? 1 : -1);
        else
            a[i] = a[i-1] + (s[i] == '(' ? 1 : -1);;
    }
    if (a[n-1] == 2) {
        int ans = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                flag = false;
            }
        }
        if (!flag) {
            cout << 0 << endl;
            return 0;
        }
        for (int i = n-1; i >= 0; i--) {

            if (a[i] < 2) {
                cout << ans << endl;
                return 0;
            }

            ans += (s[i] == '(');
        }
    }
    if (a[n-1] == -2) {
        int ans = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < -2) {
                flag = false;
            }
        }
        if (!flag) {
            cout << 0 << endl;
            return 0;
        }
        for (int i = 0; i < n; i++) {

            ans += (s[i] == ')');

            if (a[i] < 0) {
                cout << ans << endl;
                return 0;
            }

        }
    }
    cout << 0 << endl;
    return 0;
}