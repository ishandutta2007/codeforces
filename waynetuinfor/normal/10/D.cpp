#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;
int a[maxn], b[maxn], dp[maxn], fr[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int m; cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        int cur = 0, prv = 0;
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) if (cur + 1 > dp[j]) {
                dp[j] = cur + 1;
                fr[j] = prv;
            } 
            if (a[i] > b[j]) if (cur < dp[j]) {
                cur = dp[j];
                prv = j;
            }
        }
    }
    int bst = 0;
    for (int i = 1; i <= m; ++i) {
        if (dp[i] > dp[bst]) bst = i;
    }
    cout << dp[bst] << endl;
    vector<int> rec;
    while (bst) rec.push_back(b[bst]), bst = fr[bst];
    while (rec.size()) cout << rec.back() << ' ', rec.pop_back(); cout << endl;
    return 0;
}