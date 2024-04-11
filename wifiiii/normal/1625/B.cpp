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
        map<int, int> lst;
        int ans = -1;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(lst.count(x)) {
                ans = max(ans, n - (i - lst[x]));
            }
            lst[x] = i;
        }
        cout << ans << '\n';
    }
}