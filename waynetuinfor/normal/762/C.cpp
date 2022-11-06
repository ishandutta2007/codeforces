#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
string a, b, opt;
int l[maxn], r[maxn];

bool check(int len) {
    for (int i = 0; i <= b.length() - len; ++i) {
        if (i) {
            if (i + len >= b.length() && l[i - 1] < a.length()) {
                opt = b.substr(0, b.length() - len);
                return true;
            }
            if (l[i - 1] < r[i + len]) {
                opt = ""; 
                for (int j = 0; j < i; ++j) opt += b[j];
                for (int j = i + len; j < b.length(); ++j) opt += b[j];
                return true;
            }
        } else {
            if (r[len] >= 0) {
                opt = b.substr(len, b.length() - len);
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b;
    int p = 0;
    for (int i = 0; i < b.length(); ++i) {
        while (p < a.length() && a[p] != b[i]) ++p;
        l[i] = p; ++p;
    }
    p = a.length() - 1;
    for (int i = b.length() - 1; i >= 0; --i) {
        while (p >= 0 && a[p] != b[i]) --p;
        r[i] = p; --p;
    }
    int d = 1, ans = (int)b.length(); while (d <= (int)b.length()) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    if (ans == (int)b.length()) cout << "-" << endl;
    else cout << opt << endl;
    return 0;
}