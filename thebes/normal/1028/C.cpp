#include <bits/stdc++.h>
using namespace std;

struct pnt{int x,y;};
struct rec{pnt lo,hi;};
rec cmp(rec a, rec b){
    rec res;
    res.lo.x=max(a.lo.x,b.lo.x);
    res.lo.y=max(a.lo.y,b.lo.y);
    res.hi.x=min(a.hi.x,b.hi.x);
    res.hi.y=min(a.hi.y,b.hi.y);
    return res;
}
const int MN = 2e5+5;
rec pre[MN], suf[MN], c, arr[MN];
int n, i;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d%d%d%d",&c.lo.x,&c.lo.y,&c.hi.x,&c.hi.y);
        if(i==1) pre[i] = c;
        else pre[i] = cmp(pre[i-1], c);
        arr[i] = c;
    }
    for(i=n;i>=1;i--){
        if(i==n) suf[i] = arr[i];
        else suf[i] = cmp(suf[i+1], arr[i]);
    }
    rec init;
    init.lo.x=-1e9; init.lo.y=-1e9;
    init.hi.x=1e9; init.hi.y=1e9;
    for(i=1;i<=n;i++){
        rec res = init;
        if(i!=1) res = cmp(res, pre[i-1]);
        if(i!=n) res = cmp(res, suf[i+1]);
        if(res.lo.x<=res.hi.x&&res.lo.y<=res.hi.y){
            printf("%d %d\n",res.lo.x,res.lo.y);
            return 0;
        }
    }
}