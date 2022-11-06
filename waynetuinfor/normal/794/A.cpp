#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, c; cin >> a >> b >> c;
    int n, ans = 0; cin >> n;
    while (n--) {
        int x; cin >> x;
        if (x > b && x < c) ++ans;
    } 
    cout << ans << endl;
    return 0;
}