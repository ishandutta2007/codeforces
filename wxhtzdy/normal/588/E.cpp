#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N=100050;
const int L=17;

int par[N][L],dep[N];
vector<int> E[N];
vector<int> st[N][L],all[N];

void DFS(int u,int p){
    dep[u]=dep[p]+1;
    par[u][0]=p;
    for(int i=1;i<L;i++)if(par[u][i-1]>=1)par[u][i]=par[par[u][i-1]][i-1];
    for(int v:E[u])if(v!=p)DFS(v,u);
}

int LCA(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=L-1;i>=0;i--)if(dep[par[u][i]]>=dep[v])u=par[u][i];
    for(int i=L-1;i>=0;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
    return (u==v?u:par[u][0]);
}

vector<int> Merge(vector<int> x,vector<int> y){
    vector<int> ret;
    for(int i=0,j=0;i<x.size()||j<y.size();){
        if(i>=x.size())ret.pb(y[j++]);
        else if(j>=y.size())ret.pb(x[i++]);
        else{
            if(x[i]==y[j])ret.pb(x[i++]),j++;
            else if(x[i]<y[j])ret.pb(x[i++]);
            else ret.pb(y[j++]);
        }
    }
    if(ret.size()<=10)return ret;
    ret.resize(10);
    return ret;
}

void Preprocess(){
    for(int i=1;i<N;i++){
        st[i][0]=Merge(all[i],all[par[i][0]]);
    }
    for(int i=1;i<L;i++){
        for(int j=1;j<N;j++){
            st[j][i]=Merge(st[j][i-1],st[par[j][i-1]][i-1]);
        }
    }
}

int main(){
    int n,m,q;scanf("%i %i %i",&n,&m,&q);
    for(int i=1;i<n;i++){
        int u,v;scanf("%i %i",&u,&v);
        E[u].pb(v);
        E[v].pb(u);
    }
    for(int i=1;i<=m;i++){
        int c;scanf("%i",&c);
        if(all[c].size()<10)all[c].pb(i);
    }
    DFS(1,0);
    Preprocess();
//    printf(":D ");
//    for(int i:st[3][0])printf("%i ",i);
//    printf("   %i %i %i",par[3][0],dep[3],dep[1]);
//    puts("");
    while(q--){
        int u,v,a;scanf("%i%i%i",&u,&v,&a);
        int l=LCA(u,v);
//        printf("%i        ",l);
        if(dep[u]<dep[v])swap(u,v);
        vector<int> ans;
        ans=Merge(all[u],all[v]);
        for(int i=L-1;i>=0;i--){
            int anc=par[u][i];
            if(dep[anc]>=dep[l]){
                ans=Merge(ans,st[u][i]);
                u=anc;
            }
        }
        for(int i=L-1;i>=0;i--){
            int anc=par[v][i];
            if(dep[anc]>=dep[l]){
                ans=Merge(ans,st[v][i]);
                v=anc;
            }
        }
        int sz=min((int)ans.size(),a);
        /*set<int> res;
        for(int i=0;i<sz;i++){
            res.insert(*ans.begin());
            ans.erase(ans.begin());
        }*/
        ans.resize(sz);
        printf("%i ",sz);
        for(int i:ans)printf("%i ",i);
        printf("\n");
    }
    return 0;
}