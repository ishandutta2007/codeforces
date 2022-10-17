#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        auto ask = [&](int x, int y) -> ll {
            cout << "? " << x + 1 << " " << y + 1 << endl;
            ll ret;
            cin >> ret;
            return ret;
        };
        auto isprime = [&](int x) {
            if(x <= 1) return 0;
            for(int i = 2; i * i <= x; ++i) {
                if(x % i == 0) return 0;
            }
            return 1;
        };
        if(n <= 90) {
            ll mx = 0;
            ll p1 = -1, p2 = -1;
            vector<vector<ll>> res(n, vector<ll>(n));
            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    ll tmp = ask(i, j);
                    res[i][j] = res[j][i] = tmp;
                    if(tmp > mx) {
                        mx = tmp;
                        p1 = i;
                        p2 = j;
                    }
                }
            }
            ll lo = 1, hi = 200000;
            while(lo < hi) {
                ll mid = (lo + hi + 1) / 2;
                if(mid * (mid + 1) <= mx) lo = mid;
                else hi = mid - 1;
            }
            // lo + 1 - n + 1 ~ lo + 1
            vector<vector<ll>> x(n, vector<ll>(n));
            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    x[j][i] = x[i][j] = lcm(i + lo - n + 2, j + lo - n + 2);
                }
            }
            for(int i = 0; i < n; ++i) {
                sort(res[i].begin(), res[i].end());
                sort(x[i].begin(), x[i].end());
            }
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(res[i] == x[j]) {
                        a[i] = j + lo - n + 2;
                        break;
                    }
                }
            }
        } else {
            for(int i = 0; i < 100; ++i) {
                int x = mrand() % n;
                for(int j = 0; j < 50; ++j) {
                    int y = mrand() % n;
                    while(y == x) y = mrand() % n;
                    a[x] = gcd(a[x], ask(x, y));
                }
            }
            int p = -1;
            for(int i = 0; i < n; ++i) {
                if(isprime(a[i])) {
                    if(p == -1 || a[i] > a[p]) p = i;
                }
            }
            if(p != -1) {
                for(int i = 0; i < n; ++i) {
                    if(i == p) continue;
                    a[i] = ask(i, p) / a[p];
                }
            }
            ll g = 0;
            for(int i = 0; i < n; ++i) g = gcd(g, a[i]);
            for(int i = 0; i < n; ++i) a[i] /= g;
        }
        cout << "! ";
        for(int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << endl;
    }
}