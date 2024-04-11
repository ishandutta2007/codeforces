#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, X; cin >> N >> X;
        int lo = INT_MIN, hi = INT_MAX;
        int ans = 0;
        for (int i = 1; i <= N; ++i){
            int a; cin >> a;
            if (a - X > hi || a + X < lo){
                ans++;
                lo = a - X, hi = a + X;
            }
            else{
                lo = max(lo, a - X);
                hi = min(hi, a + X);
            }
        }
        cout << ans << '\n';
    }
}