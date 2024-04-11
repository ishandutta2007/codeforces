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
#define N 10000000
#define OFF 400001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root, K;
ll ii;
ll a[200500], b[200500], c[200500];
set<ll> f;
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    ll K = 0, mx = -1;
    for (int j = 2; j < n; j++) {
        ll k = 0;
        for (int i = 1; i <= n-1; i++) {
            if (i % j != 0) {
                k++;
            }
        }
        //cout << j << " " << k - j + 1 << "\n";
        if (k - j + 1 > mx) {
            mx = k - j + 1;
            K = j;
        }
    }

    if (n <= 3) {
        cout << 0 << "\n";
        return 0;
    }
    //cout << K << "\n";
    for (int i = 1; i <= n - 1; i++) {
        if (i % K != 0) {
            f.insert(i);
        }
    }
    while (f.size() >= K) {
        cout << K;
        for (int i = 0; i < K; i++) {
            auto it = f.begin();
            cout << " " << *it;
            a[*it] = 1;
            f.erase(it);
        }
        cout << "\n";
        fflush(stdout);
        cin >> x;
        for (int j = x; j < x + K; j++) {
            ll jj = j % n;
            if (jj == 0) {
                jj = n;
            }
            if (a[jj] == 1) {
                if (jj % K != 0 && jj <= n-1) {
                    f.insert(jj);
                }
            }
            a[jj] = 0;
        }
    }
    ll sz = f.size();
    if (sz == 0) {
        cout << "0\n";
        return 0;
    } else {
        cout << K;
        for (auto x : f) {
            cout << " " << x;
            a[x] = 1;
        }
        for (int j = 0; j < K - sz; j++) {
            ll hyu = 0;
            for (int k = 1; k <= n; k++) {
                if (a[k] == 0) {
                    hyu = k;
                    a[k] = 1;
                    break;
                }
            }
            cout << " " << hyu;
        }
        cout << "\n";
        fflush(stdout);
        cin >> x;
        cout << "0\n";
        return 0;

    }

    return 0;
}