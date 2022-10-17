#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, Q; cin >> N >> Q;
        vector<int> a(N), ans(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        int cur = 0;
        for (int i = N - 1; i >= 0; --i){
            if (a[i] > cur && cur < Q){
                cur++;
                ans[i] = 1;
            }
            else if (a[i] <= cur){
                ans[i] = 1;
            }
        }
        for (int i = 0; i < N; ++i){
            cout << ans[i];
        }
        cout << '\n';
    }
}