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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 1228228
#define MOD 1000000007
ll n, x, k, z, m, pa, pb;
ll b[MAXN], cp[MAXN];

pii a[MAXN];
deque<ll> f;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X;
        a[i].Y = i * 2 + 1;
    }
    sort(a, a+n);
    reverse(a, a+n);
    for (int i = 0; i < n; i++) {
        f.push_back(a[i].Y);
        if (i + 1 < n) {
            cout << a[i].Y << " " << a[i+1].Y << "\n";
        }
    }
    for (int i = 0; i < n; i++) {
        f.pop_front();
        if (a[i].X == 1) {
            cout << a[i].Y << " " << a[i].Y + 1 << "\n";
        } else
        if (a[i].X > f.size()) {
            cout << f.back() << " " << a[i].Y + 1 << "\n";
            f.push_back(a[i].Y + 1);
        } else {
            cout << f[a[i].X - 2] << " " << a[i].Y + 1 << "\n";
        }
    }



    return 0;
}