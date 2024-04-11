#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string a, b; cin >> a >> b;
        int ans = 0;
        int last = -1;
        for (int i = 0; i < n; ++i){
            a[i] -= '0'; b[i] -= '0';
            int cur = a[i] * 2 + b[i];
            if (cur == 0){ // 0 0
                if (last == 1) ans += 2, last = -1;
                else if (last == 0) ans++, last = 0;
                else last = 0;
            }
            if (cur == 1 || cur == 2){ // 0 1
                if (last == 0) ans++;
                ans += 2;
                last = -1;
            }
            if (cur == 3){ // 1 1
                if (last == 0) ans += 2, last = -1;
                else last = 1;
            }
        }
        if (last == 0) ans++;
        cout << ans << '\n';
    }
}