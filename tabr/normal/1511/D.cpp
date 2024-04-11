#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s(n, ' ');
    int id = 0;
    while (id < n) {
        for (int i = 0; i < k && id < n; i++) {
            s[id++] = (char)('a' + i);
            for (int j = i + 1; j < k && id < n; j++) {
                s[id++] = (char)('a' + i);
                if (id < n) {
                    s[id++] = (char)('a' + j);
                }
            }
        }
    }
    cout << s << '\n';
    return 0;
}