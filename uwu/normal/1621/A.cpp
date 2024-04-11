#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        if ((N + 1) / 2 < K){
            cout << -1 << '\n';
        }
        else{
            for (int i = 1; i <= N; ++i){
                for (int j = 1; j <= N; ++j){
                    if (i == j && i % 2 && K){
                        cout << 'R';
                        K--;
                    }
                    else{
                        cout << '.';
                    }
                }
                cout << '\n';
            }
        }
    }
}