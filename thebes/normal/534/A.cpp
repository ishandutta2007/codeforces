#include <bits/stdc++.h>
using namespace std;

int n, i;

int main(){
    scanf("%d",&n);
    if(n==2) printf("1\n1\n");
    else if(n==3) printf("2\n1 3\n");
    else if(n==1) printf("1\n1\n");
    else{
        printf("%d\n",n);
        if(n%2){
            printf("%d ",n);
            n --;
        }
        for(i=1;i<=n/2;i++)
            printf("%d %d ",n/2+i,i);
        printf("\n");
    }
    return 0;
}