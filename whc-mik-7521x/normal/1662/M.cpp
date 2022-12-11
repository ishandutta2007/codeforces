#include<bits/stdc++.h>
using namespace std;
int ct1,ct2,t,n,m;
int main(){
    scanf("%d",&t);
    while(t--){
        ct1=ct2=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            ct1=max(ct1,x);
            ct2=max(ct2,y);
        }
        if(ct1+ct2>n){
            puts("IMPOSSIBLE");
            continue;
        }
        for(int i=1;i<=ct1;i++)putchar('R');
        for(int i=ct1+1;i<=n;i++)putchar('W');
        puts("");
    }
    return  0;
}