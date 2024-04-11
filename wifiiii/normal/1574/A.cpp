#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cout << string(i, '(') + string(i, ')') + string((n - i + n - i) / 2, '(') + string((n - i + n - i) / 2, ')') << '\n';
        }
    }
}