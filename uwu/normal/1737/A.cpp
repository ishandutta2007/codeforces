#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        vector<int> cnt(26);
        for (int i = 0; i < N; ++i){
            char c; cin >> c;
            cnt[c - 'a']++;
        }
        string ans = "";
        for (int i = 0; i < K; ++i){
            int need = N/K;
            for (int j = 0; j < 26; ++j){
                if (cnt[j] == 0 || !need){
                    ans += 'a' + j;
                    break;
                }
                if (cnt[j]) need--, cnt[j]--;
            }
        }
        cout << ans << '\n';
    }
}