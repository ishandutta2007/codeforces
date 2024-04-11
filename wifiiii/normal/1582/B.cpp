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
        ll ans = 1, cnt = 0;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(x == 1) ++cnt;
            else if(x == 0) ans = ans * 2;
        }
        cout << ans * cnt << '\n';
    }
}