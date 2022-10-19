#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        ll N, K; cin >> N >> K;
        vector<ll> a(N + 1);
        for (int i = 1; i <= N; ++i){
            cin >> a[i];
            a[i] += a[i - 1];
        }
        ll ans = 0, add = 0;
        if (K > N){
            ans += K * (K - 1) / 2;
            ans -= (K - N) * (K - N - 1) / 2;
            K = N;
        }
        else{
            ans += K * (K - 1) / 2;
        }
        for (int i = K; i <= N; ++i){
            add = max(add, a[i] - a[i - K]);
        }
        cout << ans + add << '\n';
    }
}