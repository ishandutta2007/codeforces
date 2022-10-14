#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 998244353
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[300500], b[300500], c[300500];
vector<pii> ans;
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
void try_move(ll x, ll y) {
    if (x != y) {
        ans.push_back(mp(x,y));
    }
}
bool g(ll x) {
    return (x == 0 || x >= n/2);
}
bool f(ll s, ll x, ll y, ll p) {
    if (g(Abs(x - s)) && g(Abs(x - y)) && g(Abs(y - p))) {
        vector<ll> f1 = {s, x, y, p};
        vector<ll> f2;
        for (int i : f1) {
            if (f2.size() == 0 || f2.back() != i) {
                f2.push_back(i);
            }
        }
        if (f2.size() == 4) {
            try_move(s, x);
            try_move(x, y);
            try_move(y, p);
            try_move(y, x);
            try_move(s, x);
        } else if (f2.size() == 3) {
            try_move(f2[0], f2[1]);
            try_move(f2[1], f2[2]);
            try_move(f2[0], f2[1]);
        } else if (f2.size() == 2) {
            try_move(f2[0], f2[1]);
        }

        return true;
    }
    return false;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[a[i]] = i;
        c[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == i) {
            continue;
        }
        if (i == 1) {
            if (b[i] >= n / 2 + 1) {
                try_move(i, b[i]);
            } else {
                try_move(i, n);
                try_move(n, b[i]);
                try_move(i, n);
            }

            ll p = b[i];
            swap(a[i], a[p]);
            b[a[p]] = p;
            b[a[i]] = i;
            continue;
        }
        bool x = f(b[i], 1, n, i) ||
                f(b[i], n, 1, i) ||
                f(b[i], 1, 1, i) ||
                f(b[i], n, n, i);

        //assert(x);
        ll p = b[i];
        swap(a[i], a[p]);
        b[a[p]] = p;
        b[a[i]] = i;
    }
    /*for (int i = 1; i <= n; i++) {
        assert(a[i] == i);
    }*/
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].X, ans[i].Y);
        swap(c[ans[i].X], c[ans[i].Y]);
    }
    /*for (int i = 1; i <= n; i++) {
        assert(c[i] == i);
    }*/
    return 0;
}