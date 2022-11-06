#include <cstdio>
#include <algorithm>
int a[201];
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for(int i=0; i<2*n; i++) scanf("%d", a+i);
    for(int i=0; i<2*n; i+=2) {
        int j;
        for(j=i+1; j<2*n; j++) if(a[j] == a[i]) break;
        for(; j>i+1; j--) {
            std::swap(a[j], a[j-1]);
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}