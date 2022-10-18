#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    cin >> s;
    cin >> s;

    vector<bool> avail(10, true);

    for(char c: s) {
        if (c == 'L') {
            for(int i = 0; i < 10; ++i) {
                if (avail[i]) {
                    avail[i] = false;
                    break;
                }
            }
        } else if (c == 'R') {
            for(int i = 9; i >= 0; --i) {
                if (avail[i]) {
                    avail[i] = false;
                    break;
                }
            }
        } else
            avail[c - '0'] = true;
    }

    for(int i = 0; i < 10; ++i)
        cout << ((avail[i]) ? '0' : '1');

    return 0;
}