#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll a[1005][1005], rowmx[1005], rownow[1005][1005], colmx[1005], colnow[1005][1005];
map<ll, ll> f;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++) {
        f.clear();
        for (int j = 0; j < m; j++) {
            f[a[i][j]] = 0;
        }
        ll l = 1;
        for (auto it = f.begin(); it != f.end(); it++) {
            (*it).second = l++;
        }
        for (int j = 0; j < m; j++) {
            rownow[i][j] = f[a[i][j]];
        }

        rowmx[i] = f.size();
    }

    for (int j = 0; j < m; j++) {
        f.clear();
        for (int i = 0; i < n; i++) {
            f[a[i][j]] = 0;
        }
        ll l = 1;
        for (auto it = f.begin(); it != f.end(); it++) {
            (*it).second = l++;
        }
        for (int i = 0; i < n; i++) {
            colnow[i][j] = f[a[i][j]];
        }
        colmx[j] = f.size();
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            //cout << colnow[i][j] << " " << rownow[i][j] << " " << rowmx[i] << " " << colmx[j] << endl;
            ll ans = max(rowmx[i] + colnow[i][j] - rownow[i][j], rownow[i][j] + colmx[j] - colnow[i][j]);
            ans = max(ans, max(colmx[j], rowmx[i]));
            printf("%d ", ans);
        }
        cout << endl;
    }
    return 0;
}