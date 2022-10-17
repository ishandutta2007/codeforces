#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e5 + 1;

int tot[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i < MN; ++i) tot[i] = tot[i - 1] ^ i;
    int t; cin >> t;
    while (t--){
        int a, b; cin >> a >> b;
        int sum = tot[a - 1];
        if (sum == b) cout << a << '\n';
        else if ((sum ^ b) != a) cout << a + 1 << '\n';
        else cout << a + 2 << '\n';
    }
}