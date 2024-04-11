#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        string S;
        cin >> S;
        int ans = 2;
        int C = 0;
        char last = '1';
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '0' && last == '1') {
                C++;
            }
            last = S[i];
        }

        ans = min(ans, C);
        cout << ans << "\n";
    }
}