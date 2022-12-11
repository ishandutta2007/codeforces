#include <bits/stdc++.h>
#define int long long

using namespace std;

const int K = 256;

void solve() {
    int n;
    cin >> n;
    int rest = n - 1;
    int x = 1;
    vector <int> ans;
    while (1) {
        if (2 * x >= rest) {
            ans.push_back(rest - x);
            break;
        }
        if (6 * x >= rest) {
            int a = x, b;
            if ((2 * (x + a)) > rest) {
                a = rest / 2 - x;
            }
            b = rest - 2 * (a + x);
            ans.push_back(a);
            ans.push_back(b);
            break;
        }
        ans.push_back(x);
        rest -= 2 * x;
        x *= 2;
    }
    cout << ans.size() << endl;
    for (int elem : ans) cout << elem << ' ';
    cout << endl;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}