#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,rb,cb,rd,cd;
int dfs(int x,int y,int dx,int dy){
    if(x==rd||y==cd)return 0;
    int nx=x+dx,ny=y+dy;
    if(nx>n||nx<1)dx=-dx;
    if(ny>m||ny<1)dy=-dy;
    nx=x+dx,ny=y+dy;
    return dfs(nx,ny,dx,dy)+1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d",&n,&m,&rb,&cb,&rd,&cd);
        printf("%d\n",dfs(rb,cb,1,1));
    }
    return  0;
}