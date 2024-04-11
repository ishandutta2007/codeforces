#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        vector<ll> a = {(ll)2e9};
        vector<ll> s(K);
        for (int i = 0; i < K; ++i) cin >> s[i];
        bool good = 1;
        for (int i = K-1; i >= 1; --i){
            ll v = s[i] - s[i-1];
            good &= v <= a.back();
            a.push_back(v);
        }
        good &= (N-K+1) * a.back() >= s[0];
        cout << (good ? "YES" : "NO") << '\n';
    }
}