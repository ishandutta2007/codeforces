#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e9 + 1;
char s[100];

int main() {
    vector<int> z;
    for (int i = 1; i * i < maxn; ++i) z.push_back(i * i);
    scanf("%s", s);
    int ans = maxn;
    for (int i = 0; i < z.size(); ++i) {
        vector<int> d;
        int k = z[i];
        while (k) d.push_back(k % 10), k /= 10;
        reverse(d.begin(), d.end());
        int p = 0, c = 0;
        for (int j = 0; j < strlen(s); ++j) {
            if (p < d.size() && d[p] == s[j] - '0') ++p;
        }
        if (p == d.size()) ans = min(ans, (int)strlen(s) - (int)d.size());
    }
    if (ans == maxn) ans = -1;
    printf("%d\n", ans);
}