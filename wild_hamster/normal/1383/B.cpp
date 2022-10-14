
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
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii;
ll a[100500], used[30], b[30][30], u[30], hyu[30][30], hyu2[30][30];
void solve() {
    cin >> n;
    for (int i = 0 ;i < 30; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 30; j++) {
            if ((a[i] >> j) & 1) {
                used[j]++;
            }
        }
    }
    for (int j = 29; j >= 0; j--) {
        if (used[j] % 2 == 1) {
           if (used[j] % 4 == 1 || n % 2 == 0) {
               cout << "WIN\n";
           }  else {
               cout << "LOSE\n";
           }
           return;
        }
    }
    cout << "DRAW\n";
    return;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}