#include <bits/stdc++.h>
using namespace std;
const int N=1050;
int n,m,q,sz[N*N],g[N][N];
char s[N][N];
bool was[N][N];
pair<int,int> dir[4]={{1,0},{-1,0},{0,1},{0,-1}};
void DFS(int i,int j,int id){
    was[i][j]=1;g[i][j]=id;
    for(auto c:dir){
        int x=i+c.first,y=j+c.second;
        if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='.'&&!was[x][y])DFS(x,y,id);
    }
}
int main(){
    scanf("%i %i %i",&n,&m,&q);
    for(int i=0;i<n;i++)scanf("%s",&s[i]);
    int id=1;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(s[i][j]=='.'&&g[i][j]==0)DFS(i,j,id),id++;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(s[i][j]=='*'){
        multiset<int> all;
        for(auto c:dir){
            int x=i+c.first,y=j+c.second;
            if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='.')all.insert(g[x][y]);
        }
        for(int c:all)sz[c]++;
    }
    while(q--){
        int l,r;scanf("%i %i",&l,&r);
        printf("%i\n",sz[g[l-1][r-1]]);
    }
    return 0;
}