#include <bits/stdc++.h>
#define int long long

using namespace std;

string s;

int get_val(int pos) {
    int n = s.length();
    if (pos < 0 || pos + 2 >= n)
        return 0;
    if (s[pos] == 'a' && s[pos + 1] == 'b' && s[pos + 2] == 'c')
        return 1;
    return 0;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    cin >> s;
    int res = 0;
    for (int i = 0; i < n; i++)
        res += get_val(i);
    for (int i = 0; i < q; i++) {
        int pos;
        char n;
        cin >> pos >> n;
        pos--;
        for (int j = 0; j < 3; j++) {
            res -= get_val(pos - j);
        }
        s[pos] = n;
        for (int j = 0; j < 3; j++) {
            res += get_val(pos - j);
        }
        cout << res << "\n";
    }
    return 0;
}