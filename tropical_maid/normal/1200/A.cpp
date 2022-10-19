#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/11, 21:35:25
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

char str[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n >> str;
    int s[10] = {};
    for (int i = 0; i < n; ++i) {
        char c = str[i];
        if (c == 'L') {
            for (int j = 0; j < 10; ++j) if (s[j] == 0) {
                s[j] = 1;
                break;
            }
        }
        else if (c == 'R') {
            for (int j = 10; j--; ) if (s[j] == 0) {
                s[j] = 1;
                break;
            }
        }
        else {
            c -= '0';
            s[c] = 0;
        }
    }
    for (int i = 0; i < 10; ++i) printf("%d", s[i]);
    return 0;
}