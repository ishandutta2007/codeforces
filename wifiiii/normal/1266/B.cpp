#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        // n * 21 - n * 7 + a
        // 14 * n + a (1 <= a <= 6)
        ll n;
        cin >> n;
        if(n <= 14) cout << "NO\n";
        else if(n % 14 >= 1 && n % 14 <= 6) cout << "YES\n";
        else cout << "NO\n";
    }
}