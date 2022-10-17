#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        // 2b = a + c
        if((a + c) % (2 * b) == 0 || (2 * b > c && (2 * b - c) % a == 0) || (2 * b > a && (2 * b - a) % c == 0)) cout << "YES\n";
        else cout << "NO\n";
    }
}