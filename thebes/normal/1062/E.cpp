#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5, LG = 19;
struct nd{int mn, mx;}st[3*MN];
int dep[MN], N, M, i, anc[MN][LG], vis[MN], nxt, x, y;
vector<int> adj[MN];
void dfs(int n,int d){
        dep[n] = d; vis[n] = ++nxt;
        for(auto v : adj[n])
                dfs(v, d+1);
}
int lca(int x,int y){
        if(dep[x]<dep[y]) swap(x,y);
        for(int i=LG-1;i>=0;i--){
                if((1<<i)<=dep[x]-dep[y])
                        x = anc[x][i];
        }
        if(x==y) return x;
        for(int i=LG-1;i>=0;i--){
                if(anc[x][i]!=anc[y][i]){
                        x = anc[x][i];
                        y = anc[y][i];
                }
        }
        return anc[x][0];
}
void upd(int i,int s,int e,int ind){
        if(s != e){
                if((s+e)/2<ind) upd(2*i+1,(s+e)/2+1,e,ind);
                else upd(2*i,s,(s+e)/2,ind);
                st[i].mn=vis[st[2*i].mn]<vis[st[2*i+1].mn]? st[2*i].mn:st[2*i+1].mn;
                st[i].mx=vis[st[2*i].mx]>vis[st[2*i+1].mx]? st[2*i].mx:st[2*i+1].mx;
        }
        else st[i].mx=st[i].mn=ind;
}
nd qu(int i,int s,int e,int ss,int se){
        if(ss>se) return st[0];
        if(s>=ss&&e<=se) return st[i];
        else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
        else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
        else{
                nd l=qu(2*i,s,(s+e)/2,ss,se),r=qu(2*i+1,(s+e)/2+1,e,ss,se), res;
                res.mn = vis[l.mn]<vis[r.mn]? l.mn:r.mn;
                res.mx = vis[l.mx]>vis[r.mx]? l.mx:r.mx;
                return res;
        }
}
int cmpA(int a,int b){return vis[a]<vis[b]?a:b;}
int cmpB(int a,int b){return vis[a]>vis[b]?a:b;}
int main(){
        for(scanf("%d%d",&N,&M),i=2;i<=N;i++)
                scanf("%d",&anc[i][0]), adj[anc[i][0]].push_back(i);
        dfs(1, 1); vis[MN-1]=1<<30;
        for(i=0;i<3*MN;i++) st[i].mn=MN-1;
        for(i=1;i<=N;i++) upd(1,1,N,i);
        for(int j=1;j<LG;j++){
                for(i=1;i<=N;i++){
                        anc[i][j]=anc[anc[i][j-1]][j-1];
                }
        }
        for(;M;M--){
                scanf("%d%d",&x,&y);
                nd tmp = qu(1,1,N,x,y);
                pair<int,int> opt(-1,-1);
                nd l = qu(1,1,N,x,tmp.mn-1), r = qu(1,1,N,tmp.mn+1,y);
                int mn = cmpA(l.mn, r.mn), mx = cmpB(l.mx, r.mx);
                int L = lca(mn, mx);
                if(dep[L]>opt.first) opt={dep[L],tmp.mn};
                l = qu(1,1,N,x,tmp.mx-1), r = qu(1,1,N,tmp.mx+1,y);
                mn = cmpA(l.mn, r.mn), mx = cmpB(l.mx, r.mx);
                L = lca(mn, mx);
                if(dep[L]>opt.first) opt={dep[L],tmp.mx};
                printf("%d %d\n",opt.second,opt.first-1);
        }
        return 0;
}