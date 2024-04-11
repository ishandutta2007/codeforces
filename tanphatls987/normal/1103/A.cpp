#include <bits/stdc++.h>

using namespace std;

int main() {
    int h[2] = {0, 0};
    string s;
    cin >> s;
    for(auto ch : s) {
        int type = ch - '0';
        int x = 4, y = h[type] * 2 + 1;
        if (type == 0) swap(x, y);
        cout << x << " " << y << '\n';
        h[type] ^= 1;
    }
}