#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
char s[1010];
int ans[1010],tans[1010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        scanf("%s",s + 1);
        for (int i = 1; i <= n; i++) ans[i] = s[i] - '0';
        ans[0] = ans[n + 1] = 0;
        //m %= (2 * (n - 1));
        while(m--) {
            bool change = false;
            for (int i = 1; i <= n; i++) {
                tans[i] = ans[i] || ((ans[i - 1] + ans[i + 1]) % 2);
            }
            for (int i = 1; i <= n; i++) {
                if (ans[i] != tans[i]) change = true;
                ans[i] = tans[i];
            }
            if (!change) break;
        }
        for (int i = 1; i <= n; i++) printf("%d",ans[i]);
        puts("");
    }
}