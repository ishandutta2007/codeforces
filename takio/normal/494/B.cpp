#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int mod = 1e9 + 7;
char s[100100], t[100100];
int ok[100100], slen, tlen, nx[100100], pre[100100], sum[100100], dp[100100], sum2[100100];

void getnext () {
    int i = 0, j = -1;
    nx[0] = -1;
    while (t[i]) {
        if (j == -1 || t[i] == t[j]) i++, j++, nx[i] = j;
        else j = nx[j];
    }
}

void kmp () {
    int i = 0, j = 0;
    while (s[i]) {
        if (j == -1 || s[i] == t[j]) i++, j++;
        else j = nx[j];
        if (j == tlen) ok[i - tlen] = 1, j = nx[j];
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s%s", s, t);
    slen = strlen (s);
    tlen = strlen (t);
    getnext ();
    kmp();
    for (int i = 0; i < slen; i++) {
        if (ok[i]) pre[i] = i;
        else {
            if (i == 0) pre[i] = -1;
            else pre[i] = pre[i - 1];
        }
    }
    for (int i = tlen - 1; i < slen; i++) {
        int p = pre[i - tlen + 1];
        if (p == -1) dp[i] = 0;
        else (dp[i] = sum2[p - 1] + p + 1) %= mod;
        (sum[i] = sum[i - 1] + dp[i]) %= mod;
//        cout << pre[i - tlen + 1] << ' ' << i << ' ' << dp[i] << ' ' << sum[i] << endl;
        (sum2[i] = sum2[i - 1] + sum[i]) %= mod;
    }
    cout << sum[slen - 1];
}