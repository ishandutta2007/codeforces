#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<pair<ll, int>> d;
    for(int a = 0; a <= 1e5; ++a) {
        for(int b = a; b <= a + 3; ++b) {
            for(int c = b; c <= b + 3; ++c) {
                ll w = 1ll * a * b + 1ll * b * c + 1ll * a * c;
                d.push_back({w * 2, a + b + c});
            }
        }
    }
    sort(d.begin(), d.end());
    int mn = 1e9;
    for(int i = d.size() - 1; i >= 0; --i) {
        d[i].second = mn = min(mn, d[i].second);
    }
    int t;
    cin >> t;
    while(t--) {
        // a <= b <= c
        // ab + bc + ac
        int n;
        cin >> n;
        cout << lower_bound(d.begin(), d.end(), pair<ll,int> {n, -1})->second << '\n';
    }
}