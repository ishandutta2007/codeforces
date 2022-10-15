#include<cstring>
#include<cstdio>
int main() {
    int n;
    scanf("%d", &n);
    if(n <= 3) 
        puts("NO");
    else {
        puts("YES");
        if(n % 2 == 0) {
            printf("1 * 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("6 * 4 = 24\n");
            for(int i(5); i <= n; i += 2) {
                printf("%d - %d = 1\n", i + 1, i);
                printf("24 * 1 = 24\n");
            }
        }else if(n % 2 == 1) {
            printf("5 - 1 = 4\n");
            printf("4 - 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("6 * 4 = 24\n");
            for(int i(6); i <= n; i += 2) {
                printf("%d - %d = 1\n", i + 1, i);
                printf("24 * 1 = 24\n");
            }   
        }
    }
}