#include<bits/stdc++.h>
using namespace std;
int T,n,a,b;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        a=0,b=0;
        for(int i=1;i<=n;i++){
            int x,y;scanf("%d%d",&x,&y);
            if(x&1) a++; else b++;
            if(y&1) a++; else b++;
        }
        if(a==b) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}