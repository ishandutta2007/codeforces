#include <cstdio>
int a[1001], b[1001]; // a lift, b land
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d%d", a+i, b+i);
        if(a[i] == 1 || b[i] == 1) {
            printf("-1\n");
            return 0;
        }
    }
    double M = m;
    for(int i=n-1; i>=0; i--) {
        M = M * b[(i+1)%n] / (b[(i+1)%n] - 1);
        M = M * a[i] / (a[i] - 1);
    }
    printf("%.10lf\n", M - m);
    return 0;
}