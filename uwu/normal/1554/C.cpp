#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        int ans = 0;
        for (int i = 30; i >= 0; --i){
            int cur = 1 << i;
            bool b = (m & cur);
            bool a = (n & cur);
            if (b && !a) ans += cur;
            else if (a && !b) break;
        }
        if ((ans ^ n) == m){
            for (int i = 0; i <= 30; ++i){
                int cur = 1 << i;
                bool b = (m & cur);
                bool a = (n & cur);
                if (!a && !b){
                    ans += cur;
                    break;
                }
                else if (ans & cur) ans -= cur;
            }
        }
        cout << ans << '\n';
    }
}

/*
10011111101111110001
   11110001001000000
10000001100110110001
*/