#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> len(m);
    for (int i = 0; i < m; ++i) cin >> len[i];
    int last = n - 1;
    vector<int> paint(m);
    for (int i = m - 1; i >= 0; --i) {
        paint[i] = min(last, n - len[i]);
        if (paint[i] < 0) {
            cout << -1 << '\n';
            return 0;
        }
        last = paint[i] - 1;
    }
    if (paint[0] != 0) {
        int total_len = n - paint[0];
        int shift = 0;
        int next = n;
        for (int i = m - 1; i >= 0; --i) {
            paint[i] -= shift;
            while (paint[i] + len[i] != next && total_len < n) {
                --paint[i];
                ++shift;
                ++total_len;
            }
            next = paint[i];
            if (total_len == n && i != 0) {
                do {
                    --i;
                    paint[i] -= shift;
                } while (i);
            }
        }
        if (total_len != n) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < m; ++i) cout << paint[i] + 1 << '\n';
    return 0;
}