#include<bits/stdc++.h>
using namespace std;
int n,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int tot=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            tot|=x;
        }
        printf("%d\n",tot);
    }
    return  0;
}