#include <cstdio>
int b[150001];
long long a[150001];
int max(int x, int y){ return x>y?x:y; }
long long divideup(long long a, long long b) {
    if(a%b == 0) return a/b;
    else return a/b+1;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", b+i);
    for(int i=1; i<=n; i++) if(b[i] != 0) goto normal;
    printf("YES\n");
    for(int i=1; i<=n; i++) printf("1 ");
    printf("\n");
    return 0;
    normal:
    b[0] = b[n]; b[n+1] = b[1];
    int x = -1;
    for(int i=1; i<=n; i++) {
        if(b[i-1] < b[i]) a[i] = b[i], x = i;
        else a[i] = -1;
    }
    if(x == -1) {
        printf("NO\n");
        return 0;
    }
    for(int i=n-1; i>0; i--) {
        int l = (x+i)%n;
        if(l == 0) l = n;
        if(a[l] != -1) continue;
        int m = max(b[l-1]+1, b[l]);
        long long a1 = a[l+1];
        if(l == n) a1 = a[1];
        a[l] = divideup(m - b[l], a1)*a1 + b[l];
    }
    printf("YES\n");
    for(int i=1; i<=n; i++) printf("%lld ", a[i]);
    printf("\n");
    return 0;
}