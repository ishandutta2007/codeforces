
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
#define N 13
#define OFF 400001
#define MOD 1000000007
#define NN 1000000
ll n, m, k, x, y, w, r;
ll c[1005000], b[1005000], a[1005000], dp[1005000], maxdp[1005000];
vector<pii> f;
vector<ll> query;
vector<vector<ll> > queries;
ll L, R;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}

void simulate() {
    ll rr = n;
    ll pos = 1;
    for (int i = query.size() -1; i >= 0; i--) {
        for (int j = rr - query[i] + 1; j <= rr; j++) {
            b[pos++] = a[j];
        }
        rr -= query[i];
    }
    for (int j = 1; j <= n; j++) {
        a[j] = b[j];
    }
}

void magic(ll x, ll p) {

    //cout << "HYU\n";
    //cout << L << " " << R << " " << x << " " << p << "\n";
    query.clear();
    if (L > 1) {
        query.push_back(L - 1);
    }
    ll ps = 0;
    for (int j = L; j <= R; j++) {
        if (a[j] == x) {
            ps = j;
        }
    }
    if (p == 0) {
        if (ps - L > 0) {
            query.push_back(ps - L);
        }
        query.push_back(R - ps + 1);
    } else {
        query.push_back(ps - L + 1);
        if (R > ps) {
            query.push_back(R - ps);
        }
    }
    if (R < n) {
        query.push_back(n - R);
    }
    w++;
    if (p == 0) {
        L = 1 + w;
        R = n;
    } else {
        R = n - w;
        L = 1;
    }
    simulate();

    if (query.size() > 1) {
        queries.push_back(query);
    }

    /*for (auto x : query) {
        cout << x <<  " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";*/
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll x = (n + 2) / 2;
    ll l = x, r = x;
    ll p = 0;
    for (int i = 0; i < n; i++) {
        if (!p) {
            f.push_back(mp(p, r));
            l--;
        } else {
            f.push_back(mp(p, l));
            r++;
        }
        p ^= 1;
    }
    L = 1;
    R = n;
    for (auto x : f) {
        magic(x.Y, x.X);
    }
    cout << queries.size() << "\n";
    for (auto x : queries) {
        cout << x.size();
        for (auto y : x) {
            cout << " " << y;
        }
        cout << "\n";
    }


    return 0;
}