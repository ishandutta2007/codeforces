#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        int ans = a[N-1] - a[0];
        for (int i = 1; i < N; ++i){
            ans = max(ans, a[i-1] - a[i]);
        }
        ans = max(ans, *max_element(a.begin(), a.end()) - a[0]);
        ans = max(ans, a[N-1] - *min_element(a.begin(), a.end()));
        cout << ans << '\n';
    }
}