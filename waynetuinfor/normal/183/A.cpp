#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int a = 1, b = 1;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        if (s.size() == 4) a++, b++;
        if (s == "UR" || s == "DL") a++;
        if (s == "UL" || s == "DR") b++;
    }
    cout << a * 1ll * b << endl;
    return 0;
}