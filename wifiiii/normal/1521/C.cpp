#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        auto ask = [&](int op, int i, int j, int x) {
            cout << "? " << op << " " << i << " " << j << " " << x << endl;
            int ret;
            cin >> ret;
            return ret;
        };
        vector<int> maybe1;
        for(int i = 1, j = n; i < j; ++i, --j) {
            int x = ask(2, i, j, 1);
            if(x == 1 || x == 2) maybe1.push_back(i), maybe1.push_back(j);
        }
        if(n % 2 == 1) maybe1.push_back((n + 1) / 2);
        int p = -1;
        for(int i : maybe1) {
            int other = 1;
            if(i == 1) other = n;
            int x = ask(2, i, other, 1), y = ask(2, other, i, 1);
            if(x == 1 && y == 2) {
                p = i;
                break;
            }
        }
        vector<int> ans(n + 1);
        ans[p] = 1;
        for(int i = 1; i <= n; ++i) {
            if(i == p) continue;
            ans[i] = ask(1, p, i, n - 1);
        }
        cout << "! ";
        for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << endl;
    }
}