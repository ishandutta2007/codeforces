#include<bits/stdc++.h>
using namespace std;
#define db double
int w,b;db f[1009][1009];
db r(int x,int y){return (x*1.0)/(y*1.0);}
db dfs(int u,int x,int y){
    if(!x&&!y) return 0;
    if(!x&&y&&(u&1)) return 0;
    if(x&&!y&&(u&1)) return 1;
    if(!x&&y&&(!(u&1))) return 0;
    if(x&&!y&&(!(u&1))) return 0;
    if(f[x][y]>=0) return f[x][y];
    db ans=0;
    if(u&1){
        ans=r(x,x+y);
        if(y) ans+=r(y,x+y)*dfs(u+1,x,y-1);
        return ans;
    }
    if(y>1) ans+=r(y,x+y)*r(y-1,x+y-1)*dfs(u+1,x,y-2);
    if(x&&y) ans+=r(y,x+y)*r(x,x+y-1)*dfs(u+1,x-1,y-1);
    return f[x][y]=ans;
}

int main(){
    memset(f,-1,sizeof(f));
    scanf("%d%d",&w,&b);
    printf("%.9lf\n",dfs(1,w,b));
    return 0;
}