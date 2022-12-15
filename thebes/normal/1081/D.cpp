#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int n, m, k, ds[MN], crt[MN], mx[MN], i, arr[MN];
struct edge{int x,y,w;}e[MN];
int fnd(int x){return ds[x]=ds[x]==x?x:fnd(ds[x]);}

int main(){
    for(scanf("%d%d%d",&n,&m,&k),i=1;i<=k;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
    for(i=1;i<=n;i++) ds[i]=i;
    for(i=1;i<=k;i++) crt[arr[i]]++;
    sort(e+1,e+m+1,[](edge i,edge j){return i.w<j.w;});
    for(i=1;i<=m;i++){
        int x=e[i].x,y=e[i].y,w=e[i].w;
        if(fnd(x)!=fnd(y)){
            x = fnd(x), y = fnd(y);
            if(crt[x]&&crt[y]) mx[x]=w;
            else mx[x]=max(mx[x],mx[y]);
            ds[y] = x; crt[x] += crt[y];
        }
    }
    for(i=1;i<=k;i++)
        printf("%d ",mx[fnd(arr[i])]);
    return 0;
}