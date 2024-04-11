/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[400005][3];
vector<vector<int>> adj(400005);
int nxt;
int n, d, k;

void dfs(int currDist, int currV, int numAttached) {
    if (currDist == d || nxt > n) return;
    for (int add = 0; add < (k - numAttached) && nxt <= n; add++) {
        adj[currV].push_back(nxt);
        adj[nxt].push_back(currV);
        dfs(currDist + 1, nxt++, 1);
    }
}

int main() {
    cin >> n >> d >> k;
    if (n < d + 1) {
        cout << "NO";
        return 0;
    }
    if (k == 1) {
        if (d == 1 && n == 2) {
            cout << "YES" << "\n";
            cout << 1 << " " << 2 << "\n";
        } else {
            cout << "NO" << "\n";
        }
        return 0;
    }
    dp[d][1] = 1LL;
    dp[d][2] = 1LL;
    for (int i = d - 1; i >= 0; i--) {
        dp[i][2] = (k - 2) * 1LL * dp[i + 1][1] + 1;
        dp[i][1] = (k - 1) * 1LL * dp[i + 1][1] + 1;
        dp[i][2] = min(dp[i][2], (long long) 400005);
        dp[i][1] = min(dp[i][1], (long long) 400005);
    }
    long long num = 0LL;
    for (int i = 1; i <= d + 1; i++) {
        int dist = max(i - 1, d + 1 - i);
        num += dp[dist][2];
        num = min(num, (long long) 400005);
    }
    if (num < n) {
        cout << "NO" << "\n";
        return 0;
    }
    nxt = d + 2;
    for (int i = 2; i <= d + 1; i++) {
        adj[i].push_back(i - 1);
        adj[i - 1].push_back(i);
        if (i <= d)
            dfs(max(i - 1, d + 1 - i), i, 2);
    }
    cout << "YES" << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            if (i < j) {
                cout << i << " " << j << "\n";
            }
        }
    }
    
}