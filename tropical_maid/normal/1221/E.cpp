#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/20, 01:04:23
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int a, b;
char S[300001];

bool solve() {
    cin >> a >> b >> S;
    int pr = 0;
    vector<int> P;
    for (int i = 0; S[i]; ++i) {
        if (S[i] == '.') ++pr;
        else {
            if (pr > 0) P.push_back(pr);
            pr = 0;
        }
    }
    P.push_back(pr);
    int val, all = 0;
    {
        int cnt = 0;
        for (int i : P) {
            if (i < b) continue;
            if (b <= i && i < a) return 0;
            if (b + b <= i) {
                ++cnt;
                val = i;
            }
            ++all;
        }
        if (cnt > 1) return 0;
        if (cnt == 0) return all & 1;
    }
    bool pos = 0;
    if (val <= a + 2 * b - 2 && (all & 1) == 1) pos = 1;
    if (2 * a <= val && val <= a + 3 * b - 2 && (all & 1) == 0) pos = 1;
    if (3 * a <= val && val <= a + 4 * b - 2 && (all & 1) == 1) pos = 1;
    return pos;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf(solve() ? "YES\n" : "NO\n");
    return 0;
}