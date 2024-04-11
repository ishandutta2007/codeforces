#include <bits/stdc++.h>
using namespace std;

char s[20], t[20];

int calc(int a, int b) {
    int n = strlen(s), ret = 1e9;
    {
        int c = 0, x = a, y = b;
        for (int i = 0; i < n; ++i) t[i] = s[i];
        while (y < n - 1) {
            swap(t[y], t[y + 1]);
            if (y + 1 == x) --x;
            ++y, ++c;
        }
        while (y > n - 1) {
            swap(t[y], t[y - 1]);
            if (y - 1 == x) ++x;
            --y, ++c;
        }
        while (x < n - 2) {
            swap(t[x], t[x + 1]);
            if (x + 1 == y) --y;
            ++x, ++c;
        }
        while (x > n - 2) {
            swap(t[x], t[x - 1]);
            if (x - 1 == y) ++y;
            --x, ++c;
        }
        int k = 0;
        while (k < n && t[k] == '0') ++k;
        if (x == n - 2 && y == n - 1) ret = min(ret, c + k);
    }
    {
        int c = 0, x = a, y = b;
        for (int i = 0; i < n; ++i) t[i] = s[i];
        while (x < n - 2) {
            swap(t[x], t[x + 1]);
            if (x + 1 == y) --y;
            ++x, ++c;
        }
        while (x > n - 2) {
            swap(t[x], t[x - 1]);
            if (x - 1 == y) ++y;
            --x, ++c;
        }
        while (y < n - 1) {
            swap(t[y], t[y + 1]);
            if (y + 1 == x) --x;
            ++y, ++c;
        }
        while (y > n - 1) {
            swap(t[y], t[y - 1]);
            if (y - 1 == x) ++x;
            --y, ++c;
        }
        int k = 0;
        while (k < n && t[k] == '0') ++k;
        if (x == n - 2 && y == n - 1) ret = min(ret, c + k);
    }
    return ret;
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == '0' && s[j] == '0') ans = min(ans, calc(i, j));
            if (s[i] == '2' && s[j] == '5') ans = min(ans, calc(i, j));
            if (s[i] == '7' && s[j] == '5') ans = min(ans, calc(i, j));
            if (s[i] == '5' && s[j] == '0') ans = min(ans, calc(i, j));
            if (s[i] == '5' && s[j] == '2') ans = min(ans, calc(j, i));
            if (s[i] == '5' && s[j] == '7') ans = min(ans, calc(j, i)); 
            if (s[i] == '0' && s[j] == '5') ans = min(ans, calc(j, i)); 
        }
    }
    if (ans == 1e9) puts("-1");
    else printf("%d\n", ans);
    return 0;
}