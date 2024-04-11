#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        string S, T;
        
        cin >> S >> T;
        // we claim that taking mexes of length at most two works
    
        auto query = [&](int left, int right) -> int {
            vector<bool> have(3);
            int mex = 0;
            for(int i = left; i <= min(N - 1, right); i++) {
                have[S[i] - '0'] = 1;
                have[T[i] - '0'] = 1;
            }

            while(have[mex]) mex++;
            assert(mex <= 2);
            return mex;
        };


        vector<int> dp(N + 2);
        for(int i = 0; i < N; i++) {
            if(i + 1 <= N) dp[i + 1] = max(dp[i + 1],dp[i]+query(i, i)); 
            if(i + 2 <= N && i < N) dp[i + 2] = max(dp[i + 2],dp[i]+query(i, i + 1));
        }

        cout << dp[N] << "\n";
    }
}