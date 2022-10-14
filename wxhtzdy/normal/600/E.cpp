#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N=100050;
const int S=335;

struct Query{
    int L,R,i;
    Query(){}
    Query(int _L,int _R,int _i){L=_L;R=_R;i=_i;}
    inline bool operator <(const Query& other) const {
        if(L/S==other.L/S)return R<other.R;
        return L/S<other.L/S;
    }
}Q[N];

vector<int> E[N];
int col[N],lid[N],rid[N],tid,id[N];
void DFS(int u,int p){
    lid[u]=++tid;
    id[tid]=u;
    for(int v:E[u])if(v!=p)DFS(v,u);
    rid[u]=tid;
}

int cnt[N],mx;
ll sum[N],ans[N];
void Add(int x){
    if(mx==cnt[x])mx++;
    if(cnt[x])sum[cnt[x]]-=x;
    cnt[x]++;
    sum[cnt[x]]+=x;
}
void Rem(int x){
    if(mx==cnt[x]&&sum[cnt[x]]==x)mx--;
    sum[cnt[x]]-=x;
    cnt[x]--;
    if(cnt[x])sum[cnt[x]]+=x;
}

int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&col[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%i%i",&u,&v);
        E[u].pb(v);
        E[v].pb(u);
    }
    DFS(1,0);
    for(int i=1;i<=n;i++)Q[i]=Query(lid[i],rid[i],i);
    sort(Q+1,Q+n+1);
    int l=1,r=0;
    for(int i=1;i<=n;i++){
        while(r<Q[i].R)Add(col[id[++r]]);
        while(r>Q[i].R)Rem(col[id[r--]]);
        while(l<Q[i].L)Rem(col[id[l++]]);
        while(l>Q[i].L)Add(col[id[--l]]);
        ans[Q[i].i]=sum[mx];
    }
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}