#include <bits/stdc++.h>
using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

int cif(int x) {
    int cnt = 0;
    while (x > 0) cnt++, x /= 10;
    return cnt;
}

void test_case() {
    ll a, b, c;
    cin >> a >> b >> c;
    /*int x = 0, y = 0;
    for (int i = 0; i < a - c; i++) x = x * 10 + 2;
    for (int i = 0; i < c; i++) x = x * 10 + 1;
    cout << x << " ";
    for (int i = 0; i < b - c; i++) y = y * 10 + 5;
    for (int i = 0; i < c; i++) y = y * 10 + 1;
    cout << y << '\n';*/
    ll x = 1, y = 1, g = 1;
    while (cif(g) < c) {
        g *= 5;
    }
    bool sp = false;
    if (a > b) swap(a, b), sp = true;
    x = g;
    while (cif(x) < a) x *= 3;
    y = g;
    while (cif(y) < b) y *= 2;
    if (sp) swap(x, y), swap(a, b);
    cout << x << " " << y << '\n';
    //assert(cif(x) == a && cif(y) == b && cif(__gcd(x, y)) == c);
    //int cnt = 0, z = __gcd(x, y);
    //cout << z << " ";
    //while (z > 0) cnt++, z /= 10;
    //if (cnt != c) cout << "WA" << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
        test_case();
}