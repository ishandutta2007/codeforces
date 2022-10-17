#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
int lis(vector<T> a) {
    vector<T> dp;
    for(auto x : a) {
        auto it = upper_bound(dp.begin(), dp.end(), x);
        if(it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, v;
    cin >> n >> v;
    vector<int> t(n), x(n);
    for(int i = 0; i < n; ++i) cin >> t[i];
    for(int i = 0; i < n; ++i) cin >> x[i];
    vector<pair<ll,ll>> a;
    for(int i = 0; i < n; ++i) {
        ll l = x[i] + 1ll * v * t[i], r = 1ll * v * t[i] - x[i];
        if(l >= 0 && r >= 0) a.push_back({l, r});
    }
    sort(a.begin(), a.end());
    vector<ll> b;
    for(auto [_, y] : a) b.push_back(y);
    cout << lis(b) << '\n';
}