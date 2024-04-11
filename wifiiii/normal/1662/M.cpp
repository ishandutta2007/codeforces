#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int ma = 0, mb = 0;
        for(int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            ma = max(ma, a);
            mb = max(mb, b);
        }
        if(ma + mb > n) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << string(ma, 'R') + string(n - ma, 'W') << '\n';
        }
    }
}