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
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[100500], b[100500];
ll dp[505][505];
pii se[200500], de[200500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll x, y;
        scanf("%d %d", &x, &y);
        se[i] = mp(x - 1, y - 1);
        if (se[i].X < se[i].Y) {
            swap(se[i].X, se[i].Y);
        }
    }
    sort(se, se + m);
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            for (int j = 0; j < m; j++) {
                de[j].X = (se[j].X + i) % n;
                de[j].Y = (se[j].Y + i) % n;
                if (de[j].X < de[j].Y) {
                    swap(de[j].X, de[j].Y);
                }
            }
            sort(de, de + m);
            bool cool = true;
            for (int j = 0; j < m; j++) {
                if (de[j] != se[j]) {
                    cool = false;
                    break;
                }
            }
            if (cool) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}