#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;
bool inp1[N], inp2[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) inp1[i] = inp2[i] = 0;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (!inp2[x] && !inp1[i]) {
                inp1[i] = inp2[x] = 1;
            }
        }
    }
    pair <int, int> res = {-1, -1};
    for (int i = 1; i <= n; i++) {
        if (inp1[i]) continue;
        for (int j = 1; j <= n; j++) {
            if (!inp2[j]) {
                res = {i, j};
                break;
            }
        }
        if (res.first != -1) break;
    }
    if (res.first == -1) cout << "OPTIMAL\n";
    else {
        cout << "IMPROVE\n";
        cout << res.first << ' ' << res.second << "\n";
    }
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}