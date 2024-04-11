#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int flag=0,pos=0;
        if(m%2==0) flag=1;
        for(int i=1;i<=n;i++){
            int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
            if(b==c) pos=1;
        }
        if(flag&&pos) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}