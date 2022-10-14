#include <stdio.h>

int main() {
    int n, m, z;
    scanf("%d%d%d", &n, &m, &z);

    int ans = 0;
    int t = n;
    while(t <= z) {
        if(t % m == 0) {
            ans++;
        }
        t += n;
    }
    printf("%d", ans);
}