#include<bits/stdc++.h>
using namespace std;
int t,n,m,sx,sy,d;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d",&n,&m,&sx,&sy,&d);
        printf("%d\n",(sx-1>d&&m-sy>d)||(n-sx>d&&sy-1>d)?n+m-2:-1);
    }
    return 0;
}