#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/11/07, 00:06:22
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    llong n;
    cin >> n;
    vector<llong> ps;
    for (llong i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;
        ps.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ps.push_back(n);
    if ((int)ps.size() > 1) {
        printf("1\n");
    }
    else if ((int)ps.size() == 1) {
        printf("%lld\n", ps[0]);
    }
    else {
        printf("1\n");
    }
    return 0;
}