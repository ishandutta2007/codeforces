#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
typedef long long ll;
ll st[3*MN][2], dep[MN], n, m, sta[MN], en[MN], i, x, y, val[MN], t;
vector<int> adj[MN];
void dfs(int n,int p,int d){
    dep[n]=d; sta[n]=++t;
    for(auto v : adj[n])
        if(v != p) dfs(v, n, d+1);
    en[n]=t;
}
void upd(int i,int s,int e,int ss,int se,ll val,int id){
    if(s>=ss&&e<=se) st[i][id]+=val;
    else if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val,id);
    else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val,id);
    else upd(2*i,s,(s+e)/2,ss,se,val,id),upd(2*i+1,(s+e)/2+1,e,ss,se,val,id);
}
ll qu(int i,int s,int e,int idx,int id){
    if(s!=e){
        if((s+e)/2<idx) return st[i][id]+qu(2*i+1,(s+e)/2+1,e,idx,id);
        else return st[i][id]+qu(2*i,s,(s+e)/2,idx,id);
    }
    else return st[i][id];
}
int main(){
    for(scanf("%lld%lld",&n,&m),i=1;i<=n;i++)
        scanf("%lld",&val[i]);
    for(i=1;i<n;i++){
        scanf("%lld%lld",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0, 1);
    for(;m;m--){
        scanf("%lld%lld",&i,&x);
        if(i==2) printf("%lld\n",qu(1,1,n,sta[x],dep[x]%2)+val[x]);
        else{
            scanf("%lld",&y);
            upd(1,1,n,sta[x],en[x],y,dep[x]%2);
            upd(1,1,n,sta[x],en[x],-y,(dep[x]+1)%2);
        }
    }
    return 0;
}