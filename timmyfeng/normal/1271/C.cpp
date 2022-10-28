#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sx, sy;
    cin >> n >> sx >> sy;
    vector<int> freq(4);
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (y > sy) {
            ++freq[0]; //n
        } else if (y < sy) {
            ++freq[1]; //s
        }
        if (x > sx) {
            ++freq[2]; //e
        } else if (x < sx) {
            ++freq[3]; //w
        }
    }
    int ndx = max_element(freq.begin(), freq.end()) - freq.begin();
    cout << freq[ndx] << '\n';
    if (ndx == 0) {
        cout << sx << ' ' << sy + 1 << '\n';
    } else if (ndx == 1) {
        cout << sx << ' ' << sy - 1 << '\n';
    } else if (ndx == 2) {
        cout << sx + 1 << ' ' << sy << '\n';
    } else {
        cout << sx - 1 << ' ' << sy << '\n';
    }
}