#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        int now=(n%m)*(n/m+1),p=1;
        for(int i=1;i<=k;i++){
            if(now!=0){
                for(int o=p;o<=p+now-1;o+=n/m+1){
                    printf("%d ",n/m+1);
                    for(int j=o;j<o+n/m+1;j++)printf("%d ",(j-1)%n+1);
                    puts("");
                }
            }
            if(now!=n){
                for(int o=p+now;o<=p+n-1;o+=n/m){
                    printf("%d ",n/m);
                    for(int j=o;j<o+n/m;j++)printf("%d ",(j-1)%n+1);
                    puts("");
                }
            }
            p+=now;
            p=(p-1)%n+1;
        }
        puts("");
    }
    return  0;
}