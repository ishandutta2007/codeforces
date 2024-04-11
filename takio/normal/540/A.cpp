#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1010;
char s[N], t[N];

int solve1 (int x, int y) {
    int res = 0;
    while (x != y) {
        x++;
        res++;
        if (x == 10) x = 0;
    }
    return res;
}

int solve2 (int x, int y) {
    int res = 0;
    while (x != y) {
        x--;
        res++;
        if (x == -1) x = 9;
    }
    return res;
}

int main () {
    int n, res = 0;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        res += min (solve1 (s[i] - '0', t[i] - '0'), solve2 (s[i] - '0', t[i] - '0'));
    }
    cout << res;
}