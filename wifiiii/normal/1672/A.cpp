#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int s = 0;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            s += x - 1;
        }
        cout << (s & 1 ? "errorgorn" : "maomao90") << '\n';
    }
}