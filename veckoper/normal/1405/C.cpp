#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int Case, n, k, cho[N];
char s[N];
int main() {
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d%d%s", &n, &k, s);
        for (int i = 0; i < k; ++i) cho[i] = -1;
        bool valid = 1;
        for (int i = 0; i < n; ++i) if (s[i] != '?') {
            int id = i % k;
            if (cho[id] == -1) { cho[id] = s[i] - '0'; continue; }
            if (cho[id] != s[i] - '0') { valid = 0; break; }
        }
        if (count(cho, cho + k, 0) * 2 > k || count(cho, cho + k, 1) * 2 > k) valid = 0;
        puts(valid ? "YES" : "NO");
    }
    return 0;
}