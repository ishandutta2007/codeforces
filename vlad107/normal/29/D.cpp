#include<stdio.h>
#include<vector>
int n,d[666],x,y,q,p[666],m,a[666];
bool w[666][666];
std::vector<int>g[666],r;
void dfs(int x,int o){p[x]=o;for(int i=0;i<g[x].size();i++)if(g[x][i]!=o)dfs(g[x][i],x);}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n-1;i++){
        scanf("%d%d",&x,&y);
        x--;y--;d[x]++;d[y]++;
        g[x].push_back(y);g[y].push_back(x);
    }
    dfs(0,-1);
    for (int i=1;i<n;i++)if(d[i]==1)m++;
    for (int i=0;i<m;i++){
        scanf("%d",&x);x--;y=x;a[i]=x;
        while(y>=0){w[y][x]=true;y=p[y];}
    }
    bool vv=true;x=0;
    a[m]=-1;
    while (q<m||x>=0){
        if (vv)r.push_back(x);
        vv=true;
        if (x==a[q]){q++;vv=false;continue;}
        if (!w[x][a[q]]){x=p[x];continue;}
        int y=0;while(g[x][y]==p[x]||!w[g[x][y]][a[q]])y++;x=g[x][y];
    }
    if(r.size()!=2*n-1)
        puts("-1");
    else for (int i=0;i<2*n-1;i++)printf("%d ",1+r[i]);
}