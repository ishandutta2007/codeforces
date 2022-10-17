#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        int c0 = 0, c1 = 0;
        for (int i = 0; i < N; ++i){
            int x; cin >> x; x = abs(x);
            if (x % 2 == 0) c0++;
            if (x % 2 == 1) c1++;
        }
        vector<vector<vector<int>>> dp(c0+1,
                                    vector<vector<int>>(c1+1,
                                    vector<int>(2, -1)));
        
        auto solve = [&](auto self, int c0, int c1, int val, int turn) -> int{
            int &cur = dp[c0][c1][val];
            if (cur != -1) return cur;
            cur = 0;

            if (turn == 0){
                if (c0) cur |= self(self, c0-1, c1, val, turn^1) == 0;
                if (c1) cur |= self(self, c0, c1-1, val^1, turn^1) == 0;
            }
            if (turn == 1){
                if (c0) cur |= self(self, c0-1, c1, val, turn^1) == 0;
                if (c1) cur |= self(self, c0, c1-1, val, turn^1) == 0;
            }
            if (c0 == 0 && c1 == 0){
                if (val == turn) cur = 1;
            }
            return cur;
        };
        cout << (solve(solve, c0, c1, 0, 0) ? "Alice" : "Bob") << '\n';

    }
}