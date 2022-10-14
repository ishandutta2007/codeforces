#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        if(n%2==0){
            for(int i=n;i>=1;i--)printf("%i ",i);
            printf("\n");
        }else{
            for(int i=n;i>(n+1)/2;i--)printf("%i ",i);
            for(int i=1;i<=(n+1)/2;i++)printf("%i ",i);
            printf("\n");
        }
    }
}