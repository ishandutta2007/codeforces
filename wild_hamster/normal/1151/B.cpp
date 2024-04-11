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
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
map<ll, ll> f;
ll a[505][505];
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        l ^= a[i][0];
    }
    if (l != 0) {
        cout << "TAK" << endl;
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        return 0;
    } else {
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++) {
                if (a[i][j] != a[i][0]) {
                    cout << "TAK" << endl;
                    for (int k = 0; k < n; k++)
                        if (i != k) {
                            cout << 1 << " ";
                        } else {
                            cout << j+1 << " ";
                        }
                    return 0;
                }
            }
        cout << "NIE" << endl;
    }
    return 0;
}