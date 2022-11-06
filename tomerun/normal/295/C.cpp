#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;

int N,K,L1,L2;
const int MOD = 1000000007;
ll dp[201][51][51];
ll pascal[51][51];

int main() {
    cin >> N >> K;
    for (int i = 0; i <= N; ++i) {
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            if (pascal[i][j] >= MOD) pascal[i][j] -= MOD;
        }
    }
    for (int i = 0; i < N; ++i) {
        int W;
        cin >> W;
        if (W == 50) {
            ++L1;
        } else {
            ++L2;
        }
    }
    dp[0][L1][L2] = 1;
    int ans = 0;
    int turn = -1;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j <= L1; ++j) {
            for (int k = 0; k <= L2; ++k) {
                if (dp[2*i][j][k] == 0) continue;
                for (int mv2 = 0; mv2 <= k && mv2 * 100 <= K; ++mv2) {
                    for (int mv1 = 0; mv1 <= j && mv2*100 + mv1*50 <= K; ++mv1) {
                        if (mv1 == 0 && mv2 == 0) continue;
                        ll add = dp[2*i][j][k] * pascal[j][mv1] % MOD;
                        add *= pascal[k][mv2];
                        dp[2*i+1][j-mv1][k-mv2] += add;
                        if (dp[2*i+1][j-mv1][k-mv2] >= MOD) dp[2*i+1][j-mv1][k-mv2] -= MOD;
                    }
                }
            }
        }
        if (dp[2*i+1][0][0] != 0) {
            turn = 2*i+1;
            ans = dp[2*i+1][0][0];
            break;
        }
        for (int j = 0; j <= L1; ++j) {
            for (int k = 0; k <= L2; ++k) {
                if (dp[2*i+1][j][k] == 0) continue;
                for (int mv2 = 0; mv2 <= L2-k && mv2 * 100 <= K; ++mv2) {
                    for (int mv1 = 0; mv1 <= L1-j && mv2*100 + mv1*50 <= K; ++mv1) {
                        if (mv1 == 0 && mv2 == 0) continue;
                        ll add = dp[2*i+1][j][k] * pascal[L1-j][mv1] % MOD;
                        add *= pascal[L2-k][mv2];
                        dp[2*i+2][j+mv1][k+mv2] += add;
                        if (dp[2*i+2][j+mv1][k+mv2] >= MOD) dp[2*i+2][j+mv1][k+mv2] -= MOD;
                    }
                }
            }
        }
    }
    cout << turn << endl << ans << endl;
}