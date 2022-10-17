#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d, e, f;
        cin >> a >> b >> e >> f >> c >> d;
        int ans = abs(f - b) + abs(a - e);
        if(a == c && c == e && min(b, f) <= d && d <= max(b, f)) ans += 2;
        if(b == d && d == f && min(a, e) <= c && c <= max(a, e)) ans += 2;
        cout << ans << endl;
    }
}