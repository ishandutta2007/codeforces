#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <ctime>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

char s[4][100] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
char k, t[110];

void solve (char c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (s[i][j] == c) {
                if (k == 'R') cout << s[i][j - 1];
                else cout << s[i][j + 1];
                return;
            }
        }
    }
}

int main () {
    cin >> k;
    scanf ("%s", t);
    int len = strlen (t);
    for (int i = 0; i < len; i++) {
        solve (t[i]);
    }
}