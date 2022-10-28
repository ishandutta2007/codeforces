#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        int p;
        cin >> p;
        for (int i = 1; i < n; ++i) {
            int a;
            cin >> a;
            while (d >= i && a) {
                d -= i;
                --a;
                ++p;
            }
        }
        cout << p << '\n';
    }
}