#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N(111111);
int fa[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i(1); i <= k; i++) {
        int x;
        scanf("%d", &x);
        int prv(0);
        for(int j(1); j <= x; j++) {
            int y;
            scanf("%d", &y);
            if(prv) {
                fa[prv] = y;
            }
            prv = y;
        }
    }
    int ans(0);
    for(int i(1); i < n; i++) {
        if(fa[i] == i + 1) {
            continue;
        }else {
            if(fa[i] != 0) {
                for(int j(i); j;) {
                    int tmp(fa[j]);
                    if(fa[j]) {
                        ans++;
                    }
                    fa[j] = 0;
                    j = tmp;
                }
            }
            if(fa[i + 1] != 0) {
                for(int j(i + 1); j; ) {
                    int tmp(fa[j]);
                    if(fa[j]) {
                        ans++;
                    }
                    fa[j] = 0;
                    j = tmp;
                }
            }
            ans++;
        }
    }
    printf("%d\n", ans);
}