#include<bits/stdc++.h>
#define non {n+1,-1}
using namespace std;
const int N=5e5+10,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,q,mp[4][N],vis[4][N],sum1[N],sum2[N],ct,l[N],r[N];
pair<int,int>operator+(const pair<int,int>k1,const pair<int,int>k2){
    return {min(k1.first,k2.first),max(k1.second,k2.second)};
}
pair<int,int>dfs(int x,int y){
    if(x>3||x<1||y>n||y<1||!mp[x][y]||vis[x][y])return non;
    vis[x][y]=ct;
    pair<int,int>res={y,y};
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        res=res+dfs(nx,ny);
    }
    return res;
}
void init(){
    for(int i=1;i<=3;i++){
        for(int o=1;o<=n;o++){
            if(vis[i][o]||!mp[i][o])continue;
            ct++;
            auto [x,y]=dfs(i,o);
            sum1[y]++,sum2[x]++;
        }
    }
    for(int i=1;i<=n;i++){
        sum1[i]+=sum1[i-1];
        sum2[n-i+1]+=sum2[n-i+2];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=3;i++){
        for(int o=1;o<=n;o++){
            scanf("%1d",&mp[i][o]);
        }
    }
    init();
    memset(l,-63,sizeof l);
    memset(r,63,sizeof r);
    for(int i=2;i<=n;i++){
        if(vis[1][i]&&vis[3][i]==vis[1][i]&&!vis[2][i]){
            if(vis[1][i-1]&&vis[3][i-1]==vis[1][i-1]&&!vis[2][i-1])l[i]=l[i-1];
            if(vis[1][i-1]&&vis[3][i-1]&&vis[2][i-1])l[i]=i-1;
        }
    }
    for(int i=n-1;i>=1;i--){
        if(vis[1][i]&&vis[3][i]==vis[1][i]&&!vis[2][i]){
            if(vis[1][i+1]&&vis[3][i+1]==vis[1][i+1]&&!vis[2][i+1])r[i]=r[i+1];
            if(vis[1][i+1]&&vis[3][i+1]&&vis[2][i+1])r[i]=i+1;
        }
    }
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int res=sum1[n]-sum1[x-1]-sum2[y+1];
        if(r[x]>y&&vis[1][x]&&vis[3][x]==vis[1][x]&&!vis[2][x])res++;
        if(l[y]<x&&vis[1][y]&&vis[3][y]==vis[1][y]&&!vis[2][y])res++;
        if(r[x]==r[y]&&l[x]==l[y]&&vis[1][x]&&vis[3][x]==vis[1][x]&&!vis[2][x]&&vis[1][y]&&vis[3][y]==vis[1][y]&&!vis[2][y])res--;
        printf("%d\n",res);
    }
    return  0;
}