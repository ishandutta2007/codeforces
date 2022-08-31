#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair

map<ll, ll> lenToCnt;
map<ll, ll> valToCnt;

void solve(ll L)
{
    lenToCnt.clear();
    valToCnt.clear();
    if (L == 0) return;
    lenToCnt[-L] = 1;
    while(!lenToCnt.empty()) {
        L = -(lenToCnt.begin()->first);
        ll cnt = lenToCnt.begin()->second;
        lenToCnt.erase(-L);
        valToCnt[(L - 1) / 2] += cnt;
        if ((L - 1) / 2 > 0)
            lenToCnt[-((L - 1) / 2)] += cnt;
        if (L / 2 > 0)
            lenToCnt[-(L / 2)] += cnt;
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (k == 2) {
        cout << n << endl;
        return 0;
    }

    k -= 3;

    solve(n - 2);
    vector<pll> vals;
    for (auto t : valToCnt)
        vals.push_back(t);
    reverse(vals.begin(), vals.end());
    ll ourVal = -1;
    for (pll t : vals) {
        if (t.second > k) {
            ourVal = t.first;
            break;
        }
        k -= t.second;
    }
    if (ourVal == -1) throw;

    ll l = 1, r = n;

    while(true) {
        //cerr << l << " " << r << "   " << k << endl;
        ll len = r - l - 1;
        if ((len - 1) / 2 == ourVal) {
            if (k == 0) {
                cout << (l + r) / 2 << endl;
                return 0;
            }
            k--;
        }
        ll mid = (l + r) / 2;
        solve(mid - l - 1);
        if (valToCnt[ourVal] <= k) {
            l = mid;
            k -= valToCnt[ourVal];
        } else {
            r = mid;
        }
    }

    return 0;
}