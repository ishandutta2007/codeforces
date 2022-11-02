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

const int N = 100100;

char s[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    scanf ("%s", s);
    int c = 0;
    vector <int> res;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') c++;
        else if (c) {
            res.push_back (c);
            c = 0;
        }
    }
    if (c) res.push_back (c);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) printf ("%d ", res[i]);
}