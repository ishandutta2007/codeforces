#include <cstdio>
int main() {
    int n, i;
    scanf("%d", &n);
    for(i=1; (1<<i)-1 < n; i++);
    printf("%d\n", i);
    return 0;
}