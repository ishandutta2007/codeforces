#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    scanf("%i %i",&n,&t);
    if(t==10){
        if(n==1){
            printf("-1");
            return 0;
        }
        printf("10");
        for(int i=0;i<n-2;i++)printf("0");
        return 0;
    }
    for(int i=0;i<n;i++)printf("%i",t);
    return 0;
}