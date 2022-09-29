#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int main() {
    int nm, nc, y0, y1; cin >> nm >> nc >> y0 >> y1;
    int m[nm], c[nc+1] = { -(1<<30) };
    for (int i = 0; i < nm; i++) scanf(" %d", m+i);
    for (int i = 0; i < nc; i++) scanf(" %d", c+i+1);
    int target[nm];
    memset(target, -1, sizeof(target));
    int ans = 0;
    for (int i = 0, j = 0; i < nm; i++) {
        while (j < nc && c[j+1] <= m[i]) j++;
        if (j == nc) {
            ans += nm - i - 1;
            if (i > 0 && target[i-1] == c[j] &&
                m[i] - c[j] != c[j] - m[i-1])
                ans++;
            break;
        }
        if (m[i] - c[j] < c[j+1] - m[i]) {
            target[i] = c[j];
            if (i > 0 && target[i-1] == target[i] &&
                m[i] - c[j] != c[j] - m[i-1]) ans++;
        } else if (m[i] - c[j] > c[j+1] - m[i]) {
            target[i] = c[j+1];
            if (i > 0 && target[i-1] == c[j+1]) ans++;
        } else {
            if (i > 0 && target[i-1] == c[j]) {
                if (m[i] - c[j] == c[j] - m[i-1]) {
                    target[i] = c[j];
                } else {
                    target[i] = c[j+1];
                }
            } else {
                target[i] = c[j];
            }
        }
    }
    cout << ans << endl;
}