#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/20, 23:36:35
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    if (s == "0" || s == "1") printf("0\n");
    else {
        for (int i = s.length(); i--; ) {
            if ((s[i] ^= 1) == '0') break;
        }
        int i = 0;
        while (s[i] == '0') ++i;
        int L = s.length() - i;
        printf("%d\n", (L + 1) / 2);
    }
    return 0;
}