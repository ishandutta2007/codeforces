#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int nTest, n;
char s[MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%s", s);
        n = strlen(s);

        int ans = n;
        for(int i = 0; i <= n; ++i) {
            vector<int> cntLeft(2, 0), cntRight(2, 0);
            for(int j = 0; j < i; ++j)
                cntLeft[s[j] - '0']++;
            for(int j = i; j < n; ++j)
                cntRight[s[j] - '0']++;

            ans = min(ans, cntLeft[0] + cntRight[1]);
            ans = min(ans, cntLeft[1] + cntRight[0]);
        }

        printf("%d\n", ans);
    }


    return 0;
}