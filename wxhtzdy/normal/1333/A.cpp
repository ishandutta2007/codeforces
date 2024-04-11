#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n,m;
        scanf("%i %i",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i+j)==0)printf("W");
                else printf("B");
            }
            printf("\n");
        }
    }
    return 0;
}