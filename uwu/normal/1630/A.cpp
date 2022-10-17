#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        if (K == N - 1){
            if (N == 4) cout << -1 << '\n';
            else{
                for (int i = 3; i < N / 2; ++i){
                    if (i == K || (N - i - 1) == K) continue;
                    cout << i << " " << N - i - 1 << '\n';
                }
                cout << N - 1 << " " << N - 2 << '\n';
                cout << N - 3 << " " << 1 << '\n';
                cout << 2 << " " << 0 << '\n';
            }
            continue;
        }
        if (K == 0){
            for (int i = 0; i < N / 2; ++i){
                cout << i << " " << N - i - 1 << '\n';
            }
            continue;
        }
        for (int i = 1; i < N / 2; ++i){
            if (i == K || (N - i - 1) == K) continue;
            cout << i << " " << N - i - 1 << '\n';
        }
        cout << K << " " << N - 1 << '\n';
        cout << 0 << " " << (N - K - 1) << '\n';
    }
}