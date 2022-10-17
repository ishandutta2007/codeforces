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
        ll sq = max(0, (int)sqrt(n) - 2), sq3 = max(0, (int)pow(n, 1.0 / 3) - 2), sq6 = max(0, (int)pow(n, 1.0 / 6) - 2);
        while(sq * sq <= n) ++sq; --sq;
        while(sq3 * sq3 * sq3 <= n) ++sq3; --sq3;
        while(sq6 * sq6 * sq6 * sq6 * sq6 * sq6 <= n) ++sq6; --sq6;
        cout << sq + sq3 - sq6 << '\n';
    }
}