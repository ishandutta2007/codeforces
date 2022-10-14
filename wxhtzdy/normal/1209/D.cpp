#include <bits/stdc++.h>
using namespace std;
const int N=100050;
struct DSU{
    int go[N],sz[N];
    void init(){
        for(int i=0;i<N;i++)go[i]=i;
    }
    int Get(int x){
        if(go[x]==x)return x;
        return go[x]=Get(go[x]);
    }
    bool Unite(int x,int y){
        x=Get(x),y=Get(y);
        if(x==y)return 0;
        if(sz[x]<sz[y]){
            go[x]=y;
            sz[y]+=sz[x];
        }else{
            go[y]=go[x];
            sz[x]+=sz[y];
        }
    }
}D;
int n,k,cnt[N];
int main(){
    scanf("%i%i",&n,&k);
    D.init();
    int c=0;
    for(int i=1;i<=k;i++){
        int x,y;scanf("%i%i",&x,&y);
        if(D.Unite(x,y))c++;
    }
    for(int i=1;i<=n;i++)cnt[D.Get(i)]++;
    for(int i=1;i<=n;i++){
        if(cnt[i]>=2)k-=cnt[i]-1;
    }
    printf("%i",k);
    return 0;
}