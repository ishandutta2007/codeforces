#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<map>
#include<set>
using namespace std;
char a[111][111];
int cnt[111][111];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i(0); i < n; i++) {
        scanf("%s", a[i]);
    }
    //n = 100; m = 100;
    int ans(0);
    for(int i(n - 1); i >= 0; i--) {
        for(int j(m - 1); j >= 0; j--) {
            int dest;
            //a[i][j] = rand() % 2 ? 'W' : 'B';
            if(a[i][j] == 'W') {
                dest = 1;
            }else {
                dest = -1;
            }

            if(cnt[i][j] != dest) {
                int delta = dest - cnt[i][j];
                //printf("%d\n", delta);
                ans++;
                for(int i1(0); i1 <= i; i1++) {
                    for(int j1(0); j1 <= j; j1++) {
                        cnt[i1][j1] += delta;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
}