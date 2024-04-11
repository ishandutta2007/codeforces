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
#define OFF 400001
#define C 13000
#define NN 1000000
#define MOD 1000000007
ll n, k, z, m, pos, q, ans_v, y, root, xx;
ll ii, r1, r2, r3, l;
ll a[2005005];
vector<pii> ans;
void do_bullshit(ll l, ll r) {
    if (l + 2 == r) {
        ans.push_back(mp(l, l + 1));
        return;
    }
    ll mid = (l + r) / 2;
    do_bullshit(l, mid);
    do_bullshit(mid, r);
    for (int i = l; i < mid; i++) {
        ans.push_back(mp(i, i + (r - l) / 2));
    }
}
void print() {
    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x.X << " " << x.Y << "\n";
    }
}
map<pii, ll> hyu;
void check() {
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    ll zalupa = 100000;
    for (auto x : ans) {
        pii h = mp(a[x.X], a[x.Y]);
        if (hyu.find(h) == hyu.end()) {
            hyu[h] = zalupa++;
        }
        ll p = hyu[h];
        a[x.X] = p;
        a[x.Y] = p;
    }
    ll lo = 0;
    for (int i = 1; i + 1 <= n; i++) {
        if (a[i + 1] != a[i]) {
            lo += 1;
        }
    }
    if (lo == 1) {
        cout << "chlen" << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    if (n <= 2) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i < 20; i++) {
        if ((1 << i) <= n) {
            k = i;
        }
    }
    if ((1 << k) == n) {
        do_bullshit(1, n + 1);
        print();
        return 0;
    }
    ll pshe = n - (1 << k);
    pshe = (1 << k) - pshe;
    ll kurwa = (1 << k);
    do_bullshit(1, kurwa + 1);
    for (int i = 0; i < k; i++) {
        if ((pshe >> i) & 1) {
            kurwa -= (1 << i);
            do_bullshit(kurwa + 1, kurwa + 1 + (1 << (i + 1)));
        }
    }
    do_bullshit(n - (1 << k) + 1, n + 1);
    print();
    //check();

    return 0;
}