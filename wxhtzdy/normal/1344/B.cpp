#include <bits/stdc++.h>
using namespace std;

const int N=1050;

char s[N][N];
bool was[N][N];

void DFS(int x,int y){
    if(was[x][y]||s[x][y]!='#')return;
    was[x][y]=true;
    DFS(x+1,y);
    DFS(x,y+1);
    DFS(x-1,y);
    DFS(x,y-1);
}

int main(){
    int n,m;scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    int cnt=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cnt+=(s[i][j]=='#');
    bool x=false,y=false;
    for(int i=1;i<=n;i++){
        bool was=false;
        for(int j=1;j<=m;j++){
            if(j>1&&s[i][j]=='#'&&s[i][j-1]=='.'&&was)return 0*printf("-1");
            if(s[i][j]=='#')was=true;
        }
        if(!was)x=true;
    }
    for(int j=1;j<=m;j++){
        bool was=false;
        for(int i=1;i<=n;i++){
            if(i>1&&s[i][j]=='#'&&s[i-1][j]=='.'&&was)return 0*printf("-1");
            if(s[i][j]=='#')was=true;
        }
        if(!was)y=true;
    }
    if(x!=y)return 0*printf("-1");
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!was[i][j]&&s[i][j]=='#'){
                DFS(i,j);
                ans++;
            }
        }
    }
    printf("%i",ans);
    return 0;
}