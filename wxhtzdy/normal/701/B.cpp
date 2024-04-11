#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    long long w=(long long)n*n,ans[m];
    map<int,int> c,r;
    int ax=0,ay=0;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%i %i",&x,&y);
        if(!c[x])w-=n,w+=ay;
        if(!r[y])w-=n,w+=(1-c[x])+ax;
        ans[i]=w,ax+=(1-c[x]),ay+=(1-r[y]),c[x]=1,r[y]=1;
    }
    for(int i=0;i<m;i++)printf("%lld ",ans[i]);
    return 0;
}