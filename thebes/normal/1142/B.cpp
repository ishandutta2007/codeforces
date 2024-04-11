#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5, LG = 20;
int n, m, q, p[MN], lst[MN], lol[MN], arr[MN], ans[MN], i, x, y, mx, sp[MN][LG];
vector<pair<int,int>> qu[MN];
int adv(int x,int d){
    for(int i=LG-1;i>=0;i--){
        if((1<<i)<=d){
            d -= (1<<i);
            x = sp[x][i];
        }
    }
    return x;
}
int main(){
    for(scanf("%d%d%d",&n,&m,&q),i=1;i<=n;i++)
        scanf("%d",&p[i-1]);
    for(i=0;i<n;i++) lol[p[i]]=p[(i+n-1)%n];
    for(i=1;i<=m;i++) scanf("%d",&arr[i]);
    for(i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        qu[y].push_back({x,i});
    }
    for(i=1;i<=m;i++){
        for(int j=0;j<LG;j++) sp[i][j]=adv(lst[lol[arr[i]]],(1<<j)-1);
        mx = max(mx, adv(i,n-1));
        lst[arr[i]]=i;
        for(auto v : qu[i]){
            if(v.first<=mx) ans[v.second]=1;
        }
    }
    for(i=1;i<=q;i++)
        printf("%d",ans[i]);
    printf("\n");
    return 0;
}