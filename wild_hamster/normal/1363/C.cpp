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
vector<ll> g[200500];
string s, t;
ll a[1005], b[5];
string hyu[2] = {"Ayush", "Ashish"};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            a[i] = 0;
        }
        for (int i = 0; i < n-1; i++) {
            ll u, v;
            cin >> u >> v;
            a[u]++;
            a[v]++;
        }
        ll ans = 0;
        if (a[x] <= 1) {
            ans = 0;
        } else {
            ans = (n) % 2;
        }
        cout << hyu[ans] << "\n";
    }
    return 0;
}