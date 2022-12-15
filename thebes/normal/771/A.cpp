#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n, m, i, x, y, ds[MN], sz[MN], e[MN];
int fnd(int n){return ds[n]=ds[n]==n?n:fnd(ds[n]);}

int main(){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++) ds[i]=i, sz[i]=1;
        for(i=1;i<=m;i++){
                scanf("%d%d",&x,&y);
                e[fnd(x)] ++;
                if(fnd(x) != fnd(y)){
                        sz[fnd(x)] += sz[fnd(y)];
                        e[fnd(x)] += e[fnd(y)];
                        ds[fnd(y)] = fnd(x);
                }
        }
        for(i=1;i<=n;i++){
                int lol = fnd(i);
                if(1LL*sz[lol]*(sz[lol]-1)/2 > e[lol]){
                        printf("NO\n");
                        return 0;
                }
        }
        printf("YES\n");
        return 0;
}