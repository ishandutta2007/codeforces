#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int N, i, x, y, w[MN], d, dep[MN], ok[MN], tot, rt=1, par[MN], ff=1, m[MN];
vector<int> adj[MN];

int qu(int x,bool t){
    if(t==0) assert(dep[x]<d);
    printf("%c %d\n",t?'d':'s',x);
    fflush(stdout);
    int r; scanf("%d",&r);
    return r;
}
void idk(int n,int p);
void dfs(int n,int p,int dd,bool f=0){
    if(f) dep[n]=dd, par[n]=p;
    m[n]=0; w[n]=1; tot+=w[n];
    if(d==dd){
        if(f){for(auto v : adj[n]){if(v!=p)idk(v,n);}}
        return;
    }
    for(auto v : adj[n])
        if(v!=p&&ok[v]) dfs(v, n, dd+1, ff),w[n]+=w[v],m[n]=max(m[n],w[v]);
}

void idk(int n,int p){
    ok[n] = 0;
    for(auto v : adj[n])
        if(v != p) idk(v, n);
}

int main(){
    for(scanf("%d",&N),i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    d = qu(1, 1);
    for(i=1;i<=N;i++) ok[i]=1;
    while(1){
        tot=0; dfs(rt, 0, 0, ff); ff=0;
        pair<int,int> opt(-1,-1);
        for(i=1;i<=N;i++){
            if(!ok[i]||dep[i]>d) continue;
            if(tot-w[i]<=(tot+1)/2&&m[i]<=(tot+1)/2){
                if(dep[i]>opt.second) opt={i,dep[i]};
            }
        }
        i = opt.first;
        if(dep[i]==d){
            int ddd = qu(i,1);
            if(ddd==-1) return 0;
            if(!ddd){
                printf("! %d\n",i);
                fflush(stdout);
                return 0;
            }
            else idk(i, par[i]);
        }
        else{
            int ddd = qu(i,1);
            if(ddd==-1) return 0;
            if(ddd+dep[i]!=d){
                idk(i, par[i]);
                continue;
            }
            int dir = qu(i,0);
            if(dir==-1) return 0;
            if(par[i]==dir){
                idk(i, par[i]);
            }
            else{
                for(auto v : adj[i]){
                    if(v!=dir) idk(v, i);
                }
                rt = dir; ok[i]=0;
            }
        }
    }
    return 0;
}