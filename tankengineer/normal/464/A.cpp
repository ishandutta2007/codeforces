#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;

int n, p;
char s[N];

char a[N];

bool check(int pos) {
    return (pos == 0 || a[pos - 1] != a[pos]) &&
           (pos <= 1 || a[pos - 2] != a[pos]);
}

bool go(int pos) {
    if (pos == n) {
        return true;
    }
    for (int j = 0; j < p; ++j) {
        a[pos] = 'a' + j;
        if (check(pos) && go(pos + 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &p);
    scanf("%s", s);
    bool find = false;
    for (int i = n - 1; i >= 0 && !find; --i) {
        for (int j = 0; j <= n; ++j) {
            a[j] = s[j];
        }
        for (int j = s[i] - 'a' + 1; j < p && !find; ++j) {
            a[i] = 'a' + j;
            if (check(i)) {
                find = go(i + 1);
            }
        }
    }
    if (find) {
        puts(a);
    } else {
        printf("NO\n");
    }
    return 0;
}