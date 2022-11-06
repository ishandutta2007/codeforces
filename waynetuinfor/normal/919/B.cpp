#include <bits/stdc++.h>
using namespace std;

int main() {
    int k; cin >> k;
    int cnt = 0, now = -1;
    for (int i = 1; cnt < k; ++i) {
        int n = i, dig = 0;
        while (n) dig += n % 10, n /= 10;
        if (dig == 10) ++cnt, now = i;
    }
    cout << now << endl;
}