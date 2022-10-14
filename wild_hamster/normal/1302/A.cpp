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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 200001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
vector<pii> g[200500];
ll d[200500], used[200500], a[200500];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i <n; i++) {
        cin >> a[i];
    }
    for (int j = 30; j >= 0; j--) {
        ll x = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] >> j) & 1) {
                x++;
            }
        }
        if (x == 1) {
            for (int i = 0; i < n; i++) {
                if ((a[i] >> j) & 1) {
                    swap(a[0], a[i]);
                }
            }
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;

}