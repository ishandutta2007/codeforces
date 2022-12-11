#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int N = 5e5 + 7, M = 998244353;
vector <pair <int, int>> op[N], cl[N];
int dp[N];

int calc(int n, int pos) {
    int bal = 0;
    dp[0] = 1;
    int tail = 0;
    int summ = 1;
    for (int i = 1; i <= n; i++) {
        for (auto elem : op[i]) {
            if (elem.first & (1 << pos)) bal++;
        }
        if (bal == 0) dp[i] = summ, summ = (summ * 2) % M;
        else dp[i] = 0;
        for (auto elem : cl[i]) {
            if (elem.first & (1 << pos)) bal--;
            else {
                while (tail < elem.second) {
                    summ = (summ - dp[tail] + M) % M;
                    tail++;
                }
            } 
        }
    }
    return summ;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        op[l].push_back({x, r});
        cl[r].push_back({x, l});
    }
    int res = 1;
    for (int i = 0; i < k; i++) {
        //cout << calc(n, i) << endl;
        res = (res * calc(n, i)) % M;
    }
    cout << res << endl;
    return 0;
}