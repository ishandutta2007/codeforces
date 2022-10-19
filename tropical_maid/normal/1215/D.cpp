#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/15, 20:02:36
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
char S[200002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> S + 1;
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (i <= n / 2) {
            if (S[i] == '?') sum -= 9, ++cnt;
            else sum -= S[i] - '0';
        }
        else {
            if (S[i] == '?') sum += 0, ++cnt;
            else sum += S[i] - '0';
        }
    }
    cnt /= 2;
    if (sum + cnt * 9 != 0) printf("Monocarp\n");
    else printf("Bicarp\n");
    return 0;
}