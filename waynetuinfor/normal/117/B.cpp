#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, mod; cin >> a >> b >> mod;
    if (b >= mod) return cout << "2" << endl, 0;
    for (int i = 0; i <= a && i <= mod; ++i) {
        long long now = 1000000000ll * i;
        if ((mod - now % mod) % mod > b) return cout << "1 " << setfill('0') << setw(9) << i << endl, 0;
    }
    cout << "2" << endl;
    return 0;
}