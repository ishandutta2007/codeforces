#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int s1 = (1 << n);
        int k = n / 2;
        for (int j = 1; j <= k - 1; j++) s1 += (1 << j);
        for (int j = k; j < n; j++) s1 -= (1 << j);
        cout << s1 << endl;
    }
}