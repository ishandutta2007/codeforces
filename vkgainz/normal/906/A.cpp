#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int n; cin >> n;
    int msk = (1 << 26) - 1;
    int end = -1;
    bool countShock = false;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        string w; cin >> w;
        if (c == '.') {
            for (char x : w) {
                int cmp = (1 << 26) - 1 - (1 << (x - 'a'));
                msk &= cmp;
            }
        } else if (c == '!') {
            int must = 0;
            for (char x : w) {
                must |= (1 << (x - 'a'));
            }
            if (countShock) ++ans;
            msk &= must;
        } else if (c == '?') {
            if (i < n - 1)
                msk &= ((1 << 26) - 1 - (1 << (w[0] - 'a')));
            if (i < n - 1 && countShock) ++ans;
        }
        if (__builtin_popcount(msk) == 1 && end == -1) {
            end = i;
            countShock = true;
        }
    }
    cout << ans;
}