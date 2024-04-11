#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
char s[maxn], t[maxn];
int dp[2][2][maxn], n;

int solve(const char *s, const char *t) {
    int fr, ba;
    for (fr = 0; s[fr] == t[fr]; ++fr);
    for (ba = n - 1; s[ba] == t[ba]; --ba);
    for (int i = fr + 1; i <= ba; ++i) if (s[i - 1] != t[i]) return 0;
    return 1;
}

int main() {
    scanf("%d", &n);
    scanf("%s", s); scanf("%s", t);
    printf("%d\n", solve(s, t) + solve(t, s));
    return 0;
}