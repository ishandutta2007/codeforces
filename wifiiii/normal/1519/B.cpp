#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        cout << (n * m - 1 == k ? "YES" : "NO") << '\n';
    }
}