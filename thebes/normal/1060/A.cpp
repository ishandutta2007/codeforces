#include <bits/stdc++.h>
using namespace std;

int wtf, wts, n, i, x, ans;
int main(){
    for(scanf("%d",&n),getchar(),i=1;i<=n;i++){
        if(getchar()=='8') wts++;
        else wtf++;
    }
    while(1){
        if(wts&&(wts-1+wtf)>=10){
            ans ++;
            wts--;
            int r = min(wtf, 10);
            wtf -= r;
            wts -= 10-r;
        }
        else break;
    }
    printf("%d\n",ans);
    return 0;
}