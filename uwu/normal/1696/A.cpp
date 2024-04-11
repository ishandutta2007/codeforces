#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, Z; cin >> N >> Z;
        int ans = 0;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
            ans = max(ans, Z | a[i]);
        }
        cout << ans << '\n';
    }

}