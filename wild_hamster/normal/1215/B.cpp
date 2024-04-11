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
#define MAXN 30000
#define MOD 1000000007
#define LOG 18
ll n, x, k, z, m, pos, q;


ll used[100500], a[200500], b[200500];
vector<ll> g, f;
int main() {
    cin >> n;
    b[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            a[i] = -1;
        } else {
            a[i] = 1;
        }
        b[i+1] = b[i] * a[i];
    }
    ll x = 0, y = 0;
    ll sx = 0, sy = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] < 0) {
            x++;
        } else {
            y++;
        }
    }
    sx += x;
    sy += y;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            x--;
        } else {
            y--;
        }
        if (a[i] < 0) {
            swap(x, y);
        }
        sx += x;
        sy += y;
    }
    cout << sx << " " << sy << endl;

    return 0;
}