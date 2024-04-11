#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define getm int m = (l + r) >> 1
#define LL long long
#define pii pair <int, int>

using namespace std;

char s[30];

int main () {
    cin >> s;
    int len = strlen (s);
    for (int i = 0; i < len; i++) {
        if (i == 0 && s[i] == '9') continue;
        else if (s[i] >= '5' && s[i] <= '9') {
            s[i] = '9' - s[i] + '0';
        }
    }
    cout << s;
}