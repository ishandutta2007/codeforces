#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5;
int n, i, x, y, ds[MN], nxt, ans[MN], nxt2;
pair<int,int> p[MN];
int fnd(int x){return ds[x]=ds[x]==x?x:fnd(ds[x]);}
void rec(int x){
    if(x<=n){ans[++nxt2]=x;}
    else rec(p[x].first),rec(p[x].second);
}
int main(){
    for(scanf("%d",&n),i=1;i<=2*n;i++)
        ds[i] = i;
    nxt = n;
    for(i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        x = fnd(x), y = fnd(y);
        ds[x] = ++nxt;
        ds[y] = nxt;
        p[nxt]={x,y};
    }
    rec(nxt);
    for(i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}