#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a == 0) {
            cout << 1 << '\n';
        } else {
            cout << 2 * b + a + 1 << '\n';
        }
    }
}