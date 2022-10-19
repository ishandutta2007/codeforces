#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/10/20, 18:18:56
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
char C[300005];
int S[300005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> C + 1;
    int mn = 0, cnt = 0, L = 0, R = n;
    for (int i = 1; i <= n; ++i) {
        S[i] = S[i - 1] + (C[i] == '(' ? 1 : -1);
        if (S[i] < mn) mn = S[i], cnt = 1, L = R = i;
        else if (S[i] == mn) ++cnt, R = i;
    }
    pair<int, pii> ans;
    ans.fs = cnt;
    ans.se = pii(1, 1);
    if (S[n] != 0) {
        printf("0\n1 1\n");
        return 0;
    }
    for (int i = 1; i <= n; ) {
        if (C[i] == ')') {
            ++i;
            continue;
        }
        int j = i, last = -1;
        while (j + 1 <= n && S[j] >= mn + 2) {
            ++j;
            if (C[j] == ')') last = j;
        }
        if (last != -1) {
            int mcnt = cnt;
            for (int k = i; k < last; ++k) {
                if (S[k] == mn + 2) ++mcnt;
            }
            ans = max(ans, pair(mcnt, pii(i, last)));
        }
        i = j + 1;
    }
    for (int i = 1; i <= n; ) {
        if (C[i] == ')') {
            ++i;
            continue;
        }
        int j = i, last = -1;
        while (j + 1 <= n && S[j] >= mn + 1) {
            ++j;
            if (C[j] == ')') last = j;
        }
        if (last != -1) {
            int mcnt = 0;
            for (int k = i; k < last; ++k) {
                if (S[k] == mn + 1) ++mcnt;
            }
            ans = max(ans, pair(mcnt, pii(i, last)));
        }
        i = j + 1;
    }
    if (0 < L && R < n) {
        int mn = 0, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int x = S[i];
            if (L <= i && i <= R) x += 2;
            if (x < mn) mn = x, cnt = 1;
            else if (x == mn) ++cnt;
        }
        ans = max(ans, pair(cnt, pii(L, R + 1)));
    }
    for (int i = 1; i <= n; ++i) if (S[i] == mn + 1) L = min(L, i), R = max(R, i);
    while (L > 0 && C[L] != ')') --L;
    while (R < n && C[R + 1] != '(') ++R;
    if (0 < L && R < n) {
        int mn = 0, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int x = S[i];
            if (L <= i && i <= R) x += 2;
            if (x < mn) mn = x, cnt = 1;
            else if (x == mn) ++cnt;
        }
        ans = max(ans, pair(cnt, pii(L, R + 1)));
    }
    printf("%d\n%d %d\n", ans.fs, ans.se.fs, ans.se.se);
    return 0;
}