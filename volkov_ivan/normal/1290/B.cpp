#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 7;
int pref[30][N];

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    memset(pref, 0, sizeof(pref));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            pref[j][i] = pref[j][i - 1];
            if (s[i - 1] == 'a' + j) pref[j][i]++;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "Yes\n";
            continue;
        }
        int c = 0;
        for (int j = 0; j < 30; j++) {
            int now = pref[j][r] - pref[j][l - 1];
            if (now > 0) c++;
        }
        if (c >= 3) {
            cout << "Yes\n";
            continue;
        }
        if (c == 1) {
            cout << "No\n";
            continue;
        }
        if (s[l - 1] == s[r - 1]) cout << "No\n";
        else cout << "Yes\n";
    }
}