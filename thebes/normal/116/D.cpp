#include <bits/stdc++.h>
using namespace std;

const int MN = 200;
int l[MN], r[MN], N, M, i, j, ans, x, mx;

int main(){
    for(scanf("%d%d",&N,&M),i=1;i<=N;i++){
        l[i]=M; r[i]=1;
        for(getchar(),j=1;j<=M;j++){
            char ch = getchar();
            if(ch=='W') l[i]=min(l[i],j),r[i]=max(r[i],j),mx=i;
        }
    }
    x = 1;
    for(i=1;i<mx;i++){
        if(i&1){
            ans += max(r[i],max(r[i+1],x))-x;
            x = max(max(x,r[i]),r[i+1]);
        }
        else{
            ans += x-min(x,min(l[i],l[i+1]));
            x = min(min(x,l[i]),l[i+1]);
        }
    }
    if(mx){
        if(mx&1) ans += max(x,r[mx])-x;
        else ans += x-min(x,l[mx]);
    }
    printf("%d\n",ans+max(mx-1,0));
    return 0;
}