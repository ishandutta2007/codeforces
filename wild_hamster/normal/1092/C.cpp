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
ll  a[500050], b[505], pa[500500], dp[500500], ans;
ll Abs(ll x) {
    return x>0?x:-x;
}
string s[305];
vector<int> f;
int main() {
    int t;
    cin >> n;
    for (int i = 0; i < 2*n-2; i++) {
        cin >> s[i];
        if (s[i].size() == n-1) {
            f.push_back(i);
        }
    }
    for (int j = 0; j < 2; j++) {
        string suf = s[f[j]];
        string pref = s[f[j^1]];
        for (int i = 1; i < n; i++)
            a[i] = b[i] = pa[i] = -1;
        for (int i = 0; i < 2 * n - 2; i++) {
            ll sz = s[i].size();
            //cout << s[i] << " " << suf.substr(n-sz-1) << " " << pref.substr(0, sz) << endl;
            if (suf.substr(n-sz-1) == s[i]) {
                pa[i] = 0;
                a[sz] = 1;
            }
            if (pref.substr(0, sz) == s[i]) {
                pa[i] = 1;
                b[sz] = 1;
            }
        }
        ll flag = 1;
        for (int i = 1; i < n; i++)
            if (a[i] != 1 || b[i] != 1 || pa[i] == -1)
                flag = 0;
        if (!flag) {
            continue;
        }
        for (int i = 1; i < n; i++) {
            vector<ll> f;
            for (int j = 0; j < 2 * n - 2; j++)
                if (s[j].size() == i) {
                    f.push_back(j);
                }
            if (pa[f[0]] == pa[f[1]]) {
                pa[f[0]] = 1 - pa[f[1]];
            }
        }
        for (int i = 0; i < 2 * n - 2; i++)
            cout << (pa[i] ? "P" : "S");
        return 0;
    }
    return 0;
}