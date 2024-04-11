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
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 400001
#define MOD 998244353
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
string s, t;
pii a[500500];
ll b[500500], c[500500];
vector<ll> g[505000];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        a[i].Y = i+1;
        cin >> a[i].X;
        c[i+1] = a[i].X;
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        ll v = a[i].Y;
        ll val = a[i].X;
        ll sum = 0;
        for (auto to : g[v]) {
            ll cur_val = c[to];
            if (cur_val == val) {
                cout << -1 << "\n";
                return 0;
            }
            if (cur_val < val) {
                if (b[cur_val] != i+1) {
                    b[cur_val] = i+1;
                    sum++;
                }
            }
        }
        if (sum != val - 1) {
            cout << -1 << "\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i].Y << " ";
    }
    cout << "\n";

    return 0;
}