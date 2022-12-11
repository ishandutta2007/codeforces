#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cur = 0;
    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        if (val > cur) {
            cout << i;
            return 0;
        }
        cur = max(cur, val + 1);
    }
    cout << "-1";
}