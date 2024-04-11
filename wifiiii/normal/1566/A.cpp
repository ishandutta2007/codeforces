#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        cout << s / (n / 2 + 1) << '\n';
    }
}