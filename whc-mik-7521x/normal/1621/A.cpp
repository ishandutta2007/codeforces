#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        if((n+1)>>1>=k){
            for(int i=1;i<=n;i++){
                for(int o=1;o<=n;o++){
                    if(i==o&&(i&1)&&k){
                        putchar('R');
                        k--;
                    }
                    else putchar('.');
                }
                putchar('\n');
            }
        }
        else{
            puts("-1");
        }
    }
    return  0;
}