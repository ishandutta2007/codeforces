#include<cstring>
#include<cstdio>
int n;
int main()
{
    scanf("%d", &n);
    if(n == 0) {printf("O-|-OOOO\n"); return 0;}
    while(n)
    {
        if(n % 10 >= 5) printf("-O|"); else printf("O-|");
        for(int i = 1; i <= n % 5; i++) printf("O");
        printf("-");
        for(int i = n % 5 + 1; i < 5; i++) printf("O");
        printf("\n");
        n /= 10;
    }
    
}