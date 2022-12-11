#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int tri[N][2],tot,a[N];
void init(){
    for(int i=0;i<=tot;i++)tri[i][0]=tri[i][1]=0;
    tot=0;
}
void ins(int x){
    for(int u=0,i=19;i>=0;i--){
        u=tri[u][!!(x&(1<<i))]?tri[u][!!(x&(1<<i))]:tri[u][!!(x&(1<<i))]=++tot;
    }
}
int qmx(int x){
    int res=0;
    for(int u=0,i=19;i>=0;i--){
        if(tri[u][!(x&(1<<i))])res+=1<<i,u=tri[u][!(x&(1<<i))];
        else u=tri[u][!!(x&(1<<i))];
    }
    return res;
}
int qmi(int x){
    int res=0;
    for(int u=0,i=19;i>=0;i--){
        if(tri[u][!!(x&(1<<i))])u=tri[u][!!(x&(1<<i))];
        else res+=1<<i,u=tri[u][!(x&(1<<i))];
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        int l,r,n;
        scanf("%d%d",&l,&r);
        n=r-l+1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ins(a[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int now=l^a[i];
            if(qmi(now)==l&&qmx(now)==r)ans=now;
        }
        printf("%d\n",ans);
    }
    return  0;
}