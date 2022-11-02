#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
           
#define MAXN 1111
                 
int n,m,ss[MAXN],ff[MAXN],col[MAXN];
bool g[MAXN][MAXN],imp;

inline bool contains(int sy,int ey,int sx,int ex){
    if (ex<sx)std::swap(sx,ex);
    if (sy>sx&&sy<ex&&(ey<sx||ey>ex))return true;
    std::swap(sy,ey);
    if (sy>sx&&sy<ex&&(ey<sx||ey>ex))return true;
    return false;
}

void dfs(int x,int c){
    if (imp)return;
    if (col[x]!=-1){
        if (c!=col[x])imp=true;
        return;
    }
    col[x]=c;
    for (int i=0;i<m;i++)
        if (g[x][i])dfs(i,1-c);
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
        scanf("%d%d",&ss[i],&ff[i]);
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            g[i][j]=contains(ss[i],ff[i],ss[j],ff[j]);
    memset(col,-1,sizeof(col));
    for (int i=0;i<m;i++)
        if (col[i]<0){
            imp=false;
            dfs(i,0);
            if (imp)break;
        }
    if (imp){
        printf("Impossible\n");
        return 0;
    }
    for (int i=0;i<m;i++)
        putchar(col[i]?'o':'i');
    printf("\n");
}