#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int f[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    f[0] = -1;
    for (int i = 1, j = -1; i < n; ++i) {
        while (j != -1 && s[j + 1] != s[i]) j = f[j];
        if (s[j + 1] == s[i]) ++j;
        f[i] = j;
    }
    // for (int i = 0; i < n; ++i) cout << f[i] << ' '; cout << endl;
    for (int i = 0; i < n; ++i) {
        int c = i - f[i];
        if ((i + 1) % c == 0) {
            int cy = (i + 1) / c;
            if (cy / k >= cy % k) cout << "1";
            else cout << "0";
        } else {
            int cy = (i + 1) / c;
            if (cy / k > cy % k) cout << "1";
            else cout << "0";
        }
        // if ((i + 1) % c == 0) {
            // if (cy)
        // }
        // if () 

    }
    cout << endl;
    return 0;
}