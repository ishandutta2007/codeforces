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

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> mex(n);
    int mx = 0;
    for (char c = 'y'; c >= 'a'; c--) {
        int cnt = 0;
        vector<bool> tmp(n);
        rep(i, 0, n) {
            if (s[i] == c) {
                while (tmp[cnt]) cnt++;
                mex[i] = cnt;
                mx = max(mx, cnt);
            } else if (s[i] > c) {
                tmp[mex[i]] = true;
            }
        }
    }
    cout << mx + 1 << endl;
    rep(i, 0, n) {
        cout << mex[i] + 1 << ' ';
    }
    cout << endl;

    return 0;
}