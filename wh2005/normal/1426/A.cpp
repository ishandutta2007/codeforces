#include<bits/stdc++.h>
using namespace std;
int t,n,x;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&x);
        if(n==1||n==2){
            printf("1\n");
            continue;
        }
        n-=2;
        printf("%d\n",(n-1)/x+2);
    }
    return 0;
}