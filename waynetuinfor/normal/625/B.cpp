#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int ans = 0;
    if (b.length() > a.length()) return cout << "0\n", 0;
    for (int i = 0; i < a.length() - b.length() + 1; ) {
        if (a.substr(i, (int)b.length()) == b) ++ans, i += b.length();
        else ++i;
    }
    cout << ans << endl;
}