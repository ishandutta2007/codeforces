#include <stdio.h>
#include <string>
#include <iostream>
#include <memory.h>

using namespace std;

const int N = 2e6;
const int BASE = 1e9 + 7;

int can[N], n, m, cnt[N], a[N], ans, l, p[N];
string s;

int main() {
//  freopen("input.txt", "r", stdin);
    cin >> n >> m;
    cin >> s;
    p[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        int j = p[i - 1];
        while ((j > 0) && (s[i] != s[j])) j = p[j - 1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
    l = s.size();
    for (int i = p[l - 1]; i != 0; i = p[i - 1]) can[i] = true;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        --a[i];
        cnt[a[i]]++;
        cnt[a[i] + l]--;
        if ((i > 0) && (a[i] - a[i - 1] < l)) {
            if (!can[a[i - 1] + l - a[i]]) {
                puts("0");
                return 0;
            }
        }
    }
    int cur = 0;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        cur += cnt[i];
        if (cur == 0) ans = (ans * 26LL) % BASE;
    }
    printf("%d\n", ans);
}