#include<bits/stdc++.h>
using namespace std;
#define db double
const int N = 4e2+9;
int n,m,g[N][N],f[N][N],deg[N],vis[N];
db a[N],c[N],e[N];
vector<int >v;

int main(){
    memset(f,0x3f,sizeof(f));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);g[u][v]=1,g[v][u]=1;
        f[u][v]=1,f[v][u]=1;deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    }
    db ans=0;
    for(int i=1;i<=n;i++){
        db t=0;
        for(int j=0;j<=n;j++){
            for(int k=1;k<=n;k++) a[k]=0,vis[k]=0;
            db h=0;v.clear();
            for(int b=1;b<=n;b++)
                if(f[i][b]==j){
                    h++;
                    for(int k=1;k<=n;k++)
                        if(g[b][k]==1){
                            if(!vis[k]) v.push_back(k);vis[k]=1;
                            a[k]+=(db)1/(db)deg[b]/(db)n;
                        }
                }
            if(h){
                h=(db)1/n;
                for(int k=1;k<=n;k++){
                    db p=0;
                    for(int u=0;u<v.size();u++){
                        int x=v[u];
                        c[f[x][k]]=max(c[f[x][k]],a[x]);
                    }
                    for(int u=0;u<v.size();u++){
                        int x=v[u];
                        p+=c[f[x][k]];
                        c[f[x][k]]=0;
                    }
                    h=max(h,p);

                }
                t+=h;
            }
        }
        ans=max(ans,t);
    }
    printf("%.10lf\n",ans);
    return 0;
}
/*
4 4
1 2
1 3
2 3
1 4

*/