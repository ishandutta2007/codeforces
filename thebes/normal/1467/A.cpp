#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int T, N, i, x, c;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        if(N==1) printf("9\n");
        else if(N==2) printf("98\n");
        else{
            printf("98"); c = 9;
            for(i=3;i<=N;i++){
                printf("%d",c);
                c = (c+1)%10;
            }
            printf("\n");
        }
    }
    return 0;
}