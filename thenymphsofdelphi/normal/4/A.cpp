#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if (n % 2 == 1 || n == 2){
        printf("NO");
        return 0;
    }
    printf("YES");
}