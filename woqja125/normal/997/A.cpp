
#include <cstdio>

char a[300010];

int main() {
    int n, cnt=0, x, y;
    scanf("%d%d%d%s", &n, &x, &y, a);
    if(a[0] == '0') cnt++;
    for(int i=1; i<n; i++) {
        if(a[i] == '0' && a[i-1] == '1') cnt++;
    }
    if(cnt == 0) printf("0\n");
    else if(x < y) {
        printf("%lld\n", 1ll*(cnt-1)*x+y);
    }
    else {
        printf("%lld\n", 1ll*(cnt)*y);
    }
    return 0;
}