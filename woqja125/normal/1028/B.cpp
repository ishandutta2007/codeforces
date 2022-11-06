#include <cstdio>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    n = n/9 + 1;
    for(int i=0; i<n; i++) printf("45");
    printf("\n");
    for(int i=1; i<n; i++) printf("54");
    printf("55\n");
    return 0;
}