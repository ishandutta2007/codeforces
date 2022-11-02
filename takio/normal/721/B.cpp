#include <cstdio>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
#define xx first
#define yy second
#define pii pair <int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

const int N = 110;
string s[N], t;
int n, k;

bool cmp (string s, string t) {
    return s.length() < t.length();
}

int solve () {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res++;
        if (s[i] == t) return res;
        if (i % k == 0) res += 5;
    }
    return 0;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> s[i];
    cin >> t;
    sort (s + 1, s + 1 + n, cmp);
    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == t) p = i;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i].length() == t.length()) {
            swap (s[i], s[p]);
            p = i;
            break;
        }
    }
    cout << solve () << ' ';
    for (int i = n; i >= 1; i--) {
        if (s[i].length() == t.length()) {
            swap (s[i], s[p]);
            p = i;
            break;
        }
    }
//    for (int i = 1; i <= n; i++) cout << s[i] << endl;
    cout << solve ();
}