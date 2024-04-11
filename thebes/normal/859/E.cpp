#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 200005;
ll N, ds[MN], sz[MN], h[MN], vis[MN], c[MN], i, x, y, ans=1;
ll ld(ll x){return(x==ds[x])?x:ld(ds[x]);}

int main(){
    for(scanf("%I64d",&N),i=1;i<=2*N;i++){
        ds[i] = i; sz[i] = 1;
    }
    for(i=1;i<=N;i++){
        scanf("%I64d%I64d",&x,&y);
        if(ld(x) == ld(y) && x==y) c[ld(x)] = -1;
        else if(ld(x) == ld(y)) c[ld(x)] = 1;
        else if(ld(x) != ld(y)){
            x = ld(x); y = ld(y);
            if(h[y] > h[x]) swap(x,y);
            sz[x] += sz[y]; ds[y] = x;
            if(c[y] == 1) c[x] = 1;
            if(c[y] == -1) c[x] = -1;
            h[x] += (h[y]==h[x]);
        }
    }
    for(i=1;i<=2*N;i++){
        if(!vis[ld(i)]){
            if(c[ld(i)] == -1) continue;
            else if(c[ld(i)]) ans = (ans*2)%1000000007;
            else ans = (ans*sz[ld(i)])%1000000007;
            vis[ld(i)] = 1;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}