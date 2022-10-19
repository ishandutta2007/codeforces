#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/15, 19:47:28
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
char S[200002], T[200002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> S + 1 >> T + 1;
    vector<int> ab, ba;
    for (int i = 1; i <= n; ++i) {
        if (S[i] == 'a' && T[i] == 'b') ab.push_back(i);
        if (S[i] == 'b' && T[i] == 'a') ba.push_back(i);
    }
    if (ab.size() + ba.size() & 1) {
        printf("-1\n");
        return 0;
    }
    int ans = (ab.size() + ba.size()) / 2;
    if (ab.size() & 1) ++ans;
    printf("%d\n", ans);
    if (ab.size() & 1) {
        printf("%d %d\n", ab.back(), ab.back());
        ba.push_back(ab.back());
        ab.pop_back();
    }
    for (int i = 0; i < ab.size(); i += 2) {
        printf("%d %d\n", ab[i], ab[i + 1]);
    }
    for (int i = 0; i < ba.size(); i += 2) {
        printf("%d %d\n", ba[i], ba[i + 1]);
    }

    return 0;
}