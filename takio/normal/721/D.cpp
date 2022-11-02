#include <cstdio>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
#define xx first
#define yy second
#define pii pair <LL, LL>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

const int N = 200010, INF = 0x3f3f3f3f;
LL a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k, x, c = 0, id1, id2;
    LL mn1 = INF, mn2 = INF, flag = 0;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) {
        scanf ("%I64d", &a[i]);
        if (a[i] > 0 && mn1 > a[i]) {
            mn1 = a[i];
            id1 = i;
        }
        if (a[i] < 0 && mn2 > -a[i]) {
            mn2 = -a[i];
            id2 = i;
        }
        if (a[i] == 0) flag = 1;
        if (a[i] < 0) c ^= 1;
    }
//    cout << mn1 << ' ' << mn2 << endl;
    if (flag) {
        for (int i = 1; i <= n && k; i++) {
            if (a[i] == 0) {
                if (c == 0) a[i] -= x, c ^= 1;
                else a[i] += x;
                k--;
            }
        }
    } else if (c == 0) {
        if (mn1 < mn2) {
            while (a[id1] >= 0 && k) {
                a[id1] -= x;
                k--;
            }
        } else {
            while (a[id2] <= 0 && k) {
                a[id2] += x;
                k--;
            }
        }
    }
    priority_queue <pii, vector <pii>, greater <pii> > q;
    for (int i = 1; i <= n; i++) q.push (pii (abs (a[i]), i));
    while (k--) {
        pii u = q.top();
        q.pop();
        if (a[u.yy] < 0) a[u.yy] -= x;
        else a[u.yy] += x;
        q.push (pii (abs (a[u.yy]), u.yy));
    }
    for (int i = 1; i <= n; i++) {
        printf ("%I64d ", a[i]);
    }
}