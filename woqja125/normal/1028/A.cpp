#include <cstdio>
char tmp[1001];
int main() {
    int n, m, c=0, sx=0, sy=0;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%s", tmp+1);
        for(int j=1; j<=m; j++) {
            if(tmp[j] == 'B') {
                sx += i;
                sy += j;
                c++;
            }
        }
    }
    printf("%d %d\n", sx/c, sy/c);
    return 0;
}