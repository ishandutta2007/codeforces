#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; scanf("%d%d", &n, &q);
    string s; cin >> s;

    for(int i = 1; i <= q; ++i) {
        int l, r;
        char c1, c2;
        cin >> l >> r >> c1 >> c2;
        for(int i = l-1; i < r; ++i)
            if (s[i] == c1) s[i] = c2;
    }

    cout << s;
}