#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        string s;
        cin >> n >> s;
        int tmp = n;
        vector<int> ans1(n);
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '>') {
                ans1[i] = tmp;
                tmp--;
            } else {
                int j = i;
                while (s[j + 1] == '<') j++;
                j++;
                int k = j;
                for (; j >= i; j--) {
                    ans1[j] = tmp;
                    tmp--;
                }
                i = k;
            }
        }
        if (tmp == 1) {
            ans1[n - 1] = 1;
        }

        tmp = n;
        vector<int> ans2(n);
        rep(i, 0, n - 1) {
            if (s[i] == '>') {
                ans2[i] = tmp;
                tmp--;
            } else
                break;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '<') {
                ans2[i + 1] = tmp;
                tmp--;
            } else if (ans2[i] != 0) {
                ans2[i + 1] = tmp;
                tmp--;
                break;
            }
        }
        rep(i, 0, n) {
            if (ans2[i] == 0) {
                ans2[i] = tmp;
                tmp--;
            }
        }
        rep(i, 0, n) cout << ans1[i] << ' ';
        cout << endl;
        rep(i, 0, n) cout << ans2[i] << ' ';
        cout << endl;
    }
    return 0;
}