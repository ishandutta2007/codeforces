#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<long double> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    string s;
    cin >> s;
    long double ans = 0, mana = 0, walk = 0, swim = 0, flyg = 0, flyw = 0, flyl = 0;
    int visg = 0, visw = 0;
    for(int i = 0; i < n; ++i) {
        long double p;
        if(s[i] == 'G') {
            // walk : 5
            visg = 1;

            p = min(flyw, a[i] / 2);
            flyw -= p; mana += 2 * p; ans += 2 * p;

            p = min(mana, a[i]);
            a[i] -= p; flyg += p; mana -= p; ans += p;

            walk += a[i] / 2;
            flyg += a[i] / 2;
            ans += a[i] * 3;
        } else if(s[i] == 'W') {
            // swim : 3
            visw = 1;
            swim += a[i] / 2;
            flyw += a[i] / 2;
            ans += a[i] * 2;
        } else {
            p = min(mana, a[i]);
            a[i] -= p; flyl += p; mana -= p; ans += p;

            p = min(flyw, a[i] / 2);
            flyw -= p; mana += 2 * p; ans += 2 * p;

            p = min(mana, a[i]);
            a[i] -= p; flyl += p; mana -= p; ans += p;

            p = min(flyg, a[i] / 2);
            flyg -= p; mana += 2 * p; ans += 4 * p;

            p = min(mana, a[i]);
            a[i] -= p; flyl += p; mana -= p; ans += p;

            if(visw) {
                mana += a[i];
                swim += a[i];
                ans += 3 * a[i];
            } else {
                mana += a[i];
                walk += a[i];
                ans += 5 * a[i];
            }
            p = min(mana, a[i]);
            a[i] -= p; flyl += p; mana -= p; ans += p;
        }
    }
    ans += 0.5;
    cout << (ll)ans << endl;
}