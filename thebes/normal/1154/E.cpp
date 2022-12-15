#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int nxt[MN][2], n, k, i, lol[MN], ans[MN], x, par;
pair<int,int> ord[MN];

int main(){
    for(scanf("%d%d",&n,&k),i=1;i<=n;i++){
        scanf("%d",&x);
        ord[i]={x,i};
        nxt[i][0]=i+1;
        nxt[i][1]=i-1;
    }
    nxt[0][0]=1; nxt[n+1][1]=n;
    sort(ord+1,ord+n+1,[](pair<int,int>i,pair<int,int>j){return i.first>j.first;});
    for(int j=1;j<=n;j++){
        if(lol[ord[j].second]) continue;
        int id = ord[j].second;
        lol[id] = 1; ans[id] = par;
        int p = nxt[id][1];
        for(i=1;i<=k&&p;i++){
            lol[p] = 1; ans[p] = par;
            p = nxt[p][1];
        }
        int l = p;
        p = nxt[id][0];
        for(i=1;i<=k&&p<n+1;i++){
            lol[p] = 1; ans[p] = par;
            p = nxt[p][0];
        }
        int r = p;
        nxt[r][1]=l;
        nxt[l][0]=r;
        par = !par;
    }
    for(i=1;i<=n;i++)printf("%d",ans[i]+1);
    printf("\n");
    return 0;
}