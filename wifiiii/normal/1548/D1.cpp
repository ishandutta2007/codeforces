#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    map<pair<int,int>, int> mp;
    for(int i = 0; i < n; ++i) {
        mp[{a[i].first % 4, a[i].second % 4}]++;
    }
    auto C2 = [](ll x) {
        return x * (x - 1) / 2;
    };
    auto C3 = [](ll x) {
        return x * (x - 1) / 2 * (x - 2) / 3;
    };
    ll ans = 0;
    for(auto [p1, c1] : mp) {
        int x1 = p1.first, y1 = p1.second;
        for(auto [p2, c2] : mp) {
            int x2 = p2.first, y2 = p2.second;
            for(auto [p3, c3] : mp) {
                int x3 = p3.first, y3 = p3.second;
                int s = abs(((y3 - y1) * (x2 - x1) - (x3 - x1) * (y2 - y1)) / 2);
                int g1 = gcd(x2 - x1, y2 - y1);
                int g2 = gcd(x3 - x1, y3 - y1);
                int g3 = gcd(x3 - x2, y3 - y2);
                if((s + (g1 + g2 + g3) / 2 + 1) % 2 == 1) {
                    if(p1 == p2 && p2 == p3) ans += 6 * C3(c1); // 1
                    else if(p1 == p2) ans += 2 * C2(c1) * c3; // 3
                    else if(p2 == p3) ans += 2 * c1 * C2(c2); // 3
                    else if(p1 == p3) ans += 2 * C2(c1) * c2; // 3
                    else ans += 1ll * c1 * c2 * c3; // 6
                }
            }
        }
    }
    cout << ans / 6 << endl;
}