#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N=100050;
const int S=(int)sqrt(N);

struct Query{
    int L,R,k,i;
    Query(){}
    Query(int _L,int _R,int _k,int _i){L=_L;R=_R;k=_k;i=_i;}
    inline bool operator <(const Query& other) const{
        if(L/S==other.L/S)return R<other.R;
        return L/S<other.L/S;
    }
}Q[N];

vector<int> E[N];
int lid[N],rid[N],tid,id[N];
void DFS(int u,int p){
    lid[u]=++tid;
    id[tid]=u;
    for(int v:E[u])if(v!=p)DFS(v,u);
    rid[u]=tid;
}

int col[N],ans[N],cnt[N],res[N];
int main(){
    int n,q;scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++)scanf("%i",&col[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%i%i",&u,&v);
        E[u].pb(v);
        E[v].pb(u);
    }
    DFS(1,0);
    for(int i=1;i<=q;i++){
        int v,k;scanf("%i%i",&v,&k);
        Q[i]=Query(lid[v],rid[v],k,i);
    }
    sort(Q+1,Q+q+1);
    int l=1,r=0;
    for(int i=1;i<=q;i++){
        while(r<Q[i].R)ans[++cnt[col[id[++r]]]]++;
        while(r>Q[i].R)ans[cnt[col[id[r--]]]--]--;
        while(l<Q[i].L)ans[cnt[col[id[l++]]]--]--;
        while(l>Q[i].L)ans[++cnt[col[id[--l]]]]++;
        res[Q[i].i]=ans[Q[i].k];
    }
    for(int i=1;i<=q;i++)printf("%i\n",res[i]);
    return 0;
}