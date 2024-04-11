#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;
int ans;
char a[111][111];
int _(char c) {
    return 1 << (c - 'a');
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i(0); i < n; i++) {
        scanf("%s", a[i]);
    }
    int ans(0);
    for(int i(1); i < n; i++) {
        for(int j(1); j < m; j++) {
            if(_(a[i][j]) + _(a[i - 1][j - 1]) + _(a[i - 1][j]) + _(a[i][j - 1]) == _('f') + _('a') + _('c') + _('e')) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}