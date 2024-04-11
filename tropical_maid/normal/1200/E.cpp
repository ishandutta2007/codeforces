#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/11, 21:57:55
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
string s[100001];
int A[1000001];

int get_max(string s) {
    int n = s.length();
    int p = -1, R = -1, ret = 0;
    for (int i = 1; i < n; ++i) {
        A[i] = max(0, R - i + 1);
        if (0 <= p + p - i) A[i] = min(A[i], A[p + p - i]);
        else A[i] = 0;
        while (0 <= i - 1 - A[i] && i + A[i] < n && s[i - 1 - A[i]] == s[i + A[i]]) ++A[i];
        if (i + A[i] - 1 > R) {
            R = i + A[i] - 1;
            p = i;
        }
        if (i - A[i] == 0) ret = max(ret, i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    string all = s[1];
    for (int i = 2; i <= n; ++i) {
        string t = "";
        for (int j = 0; j < s[i].length() && j < all.length(); ++j) {
            t += s[i][j];
            t += all[all.length() - j - 1];
        }
        int ret = get_max(t);
        for (int j = ret; j < s[i].length(); ++j) all += s[i][j];
    }
    cout << all << endl;
    return 0;
}