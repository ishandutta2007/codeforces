#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << min({a, b, (a + b) / 4}) << '\n';
    }
}