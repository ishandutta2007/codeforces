#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int calc(int x) {
    if(x % 4 == 0) return x;
    if(x % 4 == 1) return 1;
    if(x % 4 == 2) return x + 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int x = calc(a - 1);
        if(x == b) cout << a << '\n';
        else if((x ^ b) != a) cout << a + 1 << '\n';
        else cout << a + 2 << '\n';
    }
}