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
    int tt;
    cin >> tt;
    while (tt--) {
        int x = 1;
        int y = 1;
        string s;
        int c;
        int q = 0;
        function<int()> output = [&]() {
            assert(q++ < 130);
            assert(x < 8);
            cout << x << " " << y << endl;
            cin >> s;
            if (s == "Done") {
                return c = 1;
            }
            if (q > 1 && s.find("Down") != string::npos) {
                x++;
                return output();
            }
            return c = 0;
        };
        output();
        while (c != 1) {
            if (y != 1) {
                y = 1;
                output();
            }
            int ok = 1;
            int px = x;
            for (int i = 0; i < 7; i++) {
                y++;
                output();
                if (c == 1 || x != px) {
                    ok = 0;
                    break;
                }
                if (s.find("Up") != string::npos) {
                    ok = 0;
                }
            }
            if (ok) {
                x++;
                output();
            }
        }
    }
    return 0;
}