#include <iostream>
#include <map>
#define int long long

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    int ans = 0;
    cin >> n;
    map <int, int> res;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res[x - i] += x;
        ans = max(ans, res[x - i]);
    }
    cout << ans << endl;
}