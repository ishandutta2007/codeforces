#include <stdio.h>
#include <vector>

#define INF 1000000000

using namespace std;

vector<pair<int,int> >g[50050];
int n,k,ans,cr;
int f[500500],fg[500500];

void dfs(int x,int px,int maxq){
    cr=min(cr,fg[x]-2*f[x]-maxq);
    for (int i=0;i<g[x].size();i++){
        int y=g[x][i].first;
        if (y==px)continue;
        k+=g[x][i].second;
        f[y]=f[x]+g[x][i].second;
        fg[y]=fg[x]+1;
        dfs(y,x,max(maxq,fg[y]-2*f[y]));
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        --x;--y;
        g[x].push_back(make_pair(y,0));
        g[y].push_back(make_pair(x,1));
    }
    ans=INF;
    for (int i=0;i<n;i++){
        f[i]=0;
        fg[i]=0;
        cr=INF;
        k=0;
        dfs(i,-1,0);
        if (k+cr<ans)ans=k+cr;
    }
    printf("%d\n",ans);
}