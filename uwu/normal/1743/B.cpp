#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> ans(N);
        int T = 0;
        for (int i = 0; i < N; i += 2){
            ans[i] = ++T;
        }
        int s = N-1;
        if (s % 2 == 0) s--;
        for (int i = s; i >= 1; i -= 2){
            ans[i] = ++T;
        }
        for (int i = 0; i < N; ++i){
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}