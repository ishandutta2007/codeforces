#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define ll long long 
const int MAXN = 100100;
int n, a, b, c; char s[MAXN];
multiset <int> S; int remL, remR, rem0, rem1;
ll ans = 0;

void solve (bool cur, ll sum) {
    ans = max(ans, sum);
    if (cur) {
        if (rem1) --rem1, sum += b;
        else { ans = max(ans, sum); return; }
    }
    else {
        if (!S.empty() || remL > 1 || remR > 1) {
            if (rem1) {
                if (!S.empty()) {
                    auto it = S.begin();
                    if ((*it) == 1) ++rem0;
                    else S.insert((*it) - 1);
                    S.erase(it);
                }
                else if (remL > 1) --remL;
                else --remR;
                sum += a;
            }
            else {
                ans = max(ans, sum + a);
                if (rem0) --rem0, ++rem1, sum -= c;
                else return;
            }
        }
        else {
            if (rem0) --rem0, ++rem1, sum -= c;
            else if (remL) --remL, sum -= c;
            else if (remR) --remR, sum -= c;
            else  { ans = max(ans, sum); return; }
        }
    }
    solve(!cur, sum);
}
void init () {
    int i, j;
    for (i = 1; i <= n && s[i] == '0'; i++) ++remL;
    for (i = n; i >= 1 && s[i] == '0'; i--) ++remR;
    if (remL == n) { ans = a; return; }
    for (i = remL + 1; i <= n - remR; i = j + 1) {
        for (j = i; j < n - remR && s[i] == s[j + 1]; j++);
        if (s[i] == '0') {
            if (i == j) ++rem0;
            else S.insert(j - i);
        }
        else rem1 += j - i;
    }
}
void clear () {
    S.clear(); rem0 = rem1 = remL = remR = 0;
}

int main () {
    int T = read();
    while (T--) {
        n = read(), a = read(), b = read(), c = read();
        scanf("%s", s + 1);
        if (n == 1) { puts("0"); continue; }
        init(); solve(0, 0); clear();
        init(); solve(1, 0); clear();
        printf("%lld\n", ans); ans = 0;
    }
    return 0;
}