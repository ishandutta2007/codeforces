#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        if (n % 2) n++;
        if (n < 6) n = 6;
        cout << n / 2 * 5 << '\n';
    }
}