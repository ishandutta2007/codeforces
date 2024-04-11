#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string ans = "";
        if (n % 2 == 1 && n != 1) ans.push_back('c'), n--;
        for (int i = 1; i <= n / 2; ++i){
            ans.push_back('a');
        }
        ans.push_back('b');
        for (int i = 1; i < n / 2; ++i){
            ans.push_back('a');
        }
        cout << ans << '\n';
    }
}