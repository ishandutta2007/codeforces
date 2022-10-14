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
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;
#define OFF 400001
#define C 13000
#define NN 1000000
#define MOD 1000000007
ll n, k, z, m, pos, q, ans_v, y, root, xx;
ll ii, r1, r2, r3;
ll d[1005005], a[1005000], b[1005000], pb[1005000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        for (int i = 0; i < n; i++) {
            pb[i] = -1;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] != pb[(i - 1 + n) % n] && a[i] != pb[(i + 1 + n) % n]) {
                pb[i] = a[i];
            }

            if (b[i] != pb[(i - 1 + n) % n] && b[i] != pb[(i + 1 + n) % n]) {
                pb[i] = b[i];
            }

            if (d[i] != pb[(i - 1 + n) % n] && d[i] != pb[(i + 1 + n) % n]) {
                pb[i] = d[i];
            }
            cout << pb[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}