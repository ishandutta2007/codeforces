#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int n,k;
vector<vector<pair<int,int> > >gr;
vector<int>p,leaves,d,ans;
vector<int>lca_dl,lca_h,lca_f,lca_t;
vector<char>used;

void lca_dfs(int v,int pr=-1){
    lca_dl.push_back(v);
    p[v]=pr;
    lca_h[v]=(pr==-1)? 0 : lca_h[pr]+1;
    for(size_t i=0;i<gr[v].size();i++){
        int to=gr[v][i].first;
        if(to==pr){continue;}
        lca_dfs(to,v);
        lca_dl.push_back(v);
    }
    if(gr[v].size()==1 && pr!=-1){leaves.push_back(v);}
}

void lca_build(int v,int l,int r){
    if(l==r){lca_t[v]=lca_dl[l];return;}
    int m=(r+l)>>1;
    lca_build(2*v,l,m);
    lca_build(2*v+1,m+1,r);
    int ans1=lca_t[2*v],ans2=lca_t[2*v+1];
    if(lca_h[ans1]<lca_h[ans2]){lca_t[v]=ans1;}
    else{lca_t[v]=ans2;}
}

int get(int v,int l,int r,int ul,int ur){
    if(l==ul && r==ur){return lca_t[v];}
    int m=(l+r)>>1;
    int ans1=-1,ans2=-1;
    if(ul<=m){
        ans1=get(2*v,l,m,ul,min(m,ur));
    }
    if(ur>m){
        ans2=get(2*v+1,m+1,r,max(ul,m+1),ur);
    }
    if(ans1==-1){return ans2;}
    if(ans2==-1){return ans1;}
    return (lca_h[ans1]<lca_h[ans2])? ans1 : ans2;
}

void lca_prepare(){
    lca_h.resize(n);
    lca_f.resize(n);lca_f.assign(n,-1);
    lca_dfs(0);
    lca_t.resize(lca_dl.size()*4+1);
    for(size_t i=0;i<lca_dl.size();i++){
        if(lca_f[lca_dl[i]]==-1){lca_f[lca_dl[i]]=i;}
    }
    lca_build(1,0,lca_dl.size()-1);
}

int lca(int v,int u){
  int l=lca_f[v],r=lca_f[u];
  if(l>r){swap(l,r);}
  return get(1,0,lca_dl.size()-1,l,r);
}

int dfs(int v,int pr=-1){
    int sum=d[v];
    for(size_t i=0;i<gr[v].size();i++){
        int to=gr[v][i].first;
        if(to==pr){continue;}
        int c=dfs(to,v);
        sum+=c;
        ans[gr[v][i].second]=c;
    }
    return sum;
}

int main(){
    scanf("%d",&n);
    gr.resize(n);p.resize(n);
    for(int i=0;i<n-1;i++){
        int v,u;
        scanf("%d%d",&v,&u);v--;u--;
        gr[v].push_back(make_pair(u,i));gr[u].push_back(make_pair(v,i));
    }
    lca_prepare();
    d.resize(n);
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int v,u;
        scanf("%d%d",&v,&u);v--;u--;
        d[v]++;d[u]++;d[lca(v,u)]-=2;
    }
    ans.resize(n-1);
    dfs(0);
    for(int i=0;i<n-1;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}