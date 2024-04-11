//stavicu sutra oglas u novine
//"jedan covjek srecu trazi
//spavao bi u grazi
//sta ce mu struja, krevet i prozori
//samo si mu ti u glavi
//budi dobra pa se javi"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool was[10005][1005];
int x[10005],n,m,r,g,ans=2e9;
vector<int> q[10005];
void ckmn(int &x,int y){x=min(x,y);}
void DFS(int tme,int u,int t){
    if(u<1 || u>m || t<0 || was[u][t])return;
    was[u][t]=1;
    if(u==m)ckmn(ans,(tme-1)*(r+g)+g-t);
    if(t==0)q[tme].pb(u);
    DFS(tme,u-1,t-x[u]+x[u-1]);
    DFS(tme,u+1,t-x[u+1]+x[u]);
}
int main(){
    scanf("%i %i",&n,&m);
    for(int i=1;i<=m;i++)scanf("%i",&x[i]);
    sort(x+1,x+1+m);
    scanf("%i %i",&g,&r);
    q[0].pb(1);
    for(int i=1;i<=m;i++)for(int u:q[i-1])DFS(i,u,g);
    if(ans==2e9)printf("-1\n");
    else printf("%i\n",ans);
    return 0;
}