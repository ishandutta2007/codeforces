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
ll a[1000500];
double ans[1000500];
pii f[1005000];
ll sz;
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    //cout.precision(10);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        a[i] = t;
    }
    for (int i = n-1; i >= 0; i--) {
        ll sum = a[i];
        ll x = 1;
        while (sz > 0 && (sum + f[sz-1].X) * f[sz-1].Y >= f[sz-1].X * (x + f[sz-1].Y)) {
            x += f[sz-1].Y;
            sum += f[sz-1].X;
            sz--;
        }
        f[sz++] = mp(sum, x);
    }
    reverse(f, f+sz);
    for (int i = 0; i < sz; i++) {
        auto x = f[i];
        double ans = 1. * x.X / x.Y;
        for (int i = 0; i < x.Y; i++) {
            printf("%.12f\n", ans);
        }
    }
    return 0;
 
}