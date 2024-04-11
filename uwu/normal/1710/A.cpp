#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        ll N, M, K; cin >> N >> M >> K;
        vector<ll> a(K);
        for (int i = 0; i < K; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        bool can = 0;
        vector<ll> b = a;

        ll C = M;
        if (C % 2 == 1 && b[K - 1] >= 3 * N){
            b[K - 1] -= 3 * N;
            C -= 3;
        }
        if (C % 2 != 1){
            for (int i = 0; i < K; ++i){
                if (b[i] >= 2 * N){
                    C -= (b[i] / N);
                }
            }
            can |= C <= 0;
        }

        b = a;
        C = N;
        if (C % 2 == 1 && b[K - 1] >= 3 * M){
            b[K - 1] -= 3 * M;
            C -= 3;
        }
        if (C % 2 != 1){
            for (int i = 0; i < K; ++i){
                if (b[i] >= 2 * M){
                    C -= (b[i] / M);
                }
            }
            can |= C <= 0;
        }

        cout << (can ? "Yes" : "No") << '\n';
    }
}