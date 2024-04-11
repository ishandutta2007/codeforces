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
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 305000
#define MOD 998244353
ll n, x, k, z, m, pos;

ll a[100500], b[100500];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c >= '0' && c <= '9') {
            a[c-'0'] = 0;
        } else {
            if (c == 'L') {
                for (int i = 0; i < 10; i++) {
                    if (!a[i]) {
                        a[i] = 1;
                        break;
                    }
                }
            } else {
                for (int i = 9; i >= 0; i--) {
                    if (!a[i]) {
                        a[i] = 1;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << a[i];
    }
    return 0;
}