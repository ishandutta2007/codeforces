#include <iostream>
#include <vector>

using namespace std;

int dp[5010][5010];
vector<int> c;

int rec(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r] > 0) return dp[l][r];

    if (c[l] == c[r]) {
        dp[l][r] = rec(l + 1, r - 1) + 1;
    } else {
        dp[l][r] = min(rec(l + 1, r), rec(l, r - 1)) + 1;
    }

    return dp[l][r];
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int d;
        cin >> d;
        if (c.empty() || d != c.back()) c.push_back(d);
    }
    N = c.size();

    cout << rec(0, N - 1) << endl;
    return 0;
}