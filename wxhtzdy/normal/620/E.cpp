#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N=400050;
const int M=2*N;

vector<int> E[N];
int col[N],lid[N],rid[N],tid,id[N];
void DFS(int u,int p){
    lid[u]=++tid;
    id[tid]=u;
    for(int v:E[u])if(v!=p)DFS(v,u);
    rid[u]=tid;
}

ll st[M],lzy[M];
int ls[M],rs[M],root,tsz;
void push(int c){
    if(lzy[c]>0){
        st[c]=lzy[c];
        lzy[ls[c]]=lzy[c];
        lzy[rs[c]]=lzy[c];
        lzy[c]=0;
    }
}
void Build(int&c,int ss,int se){
    c=++tsz;
    if(ss>se)return;
    if(ss==se){
        st[c]=(1LL<<col[id[ss]]);
        return;
    }
    int mid=ss+se>>1;
    Build(ls[c],ss,mid);
    Build(rs[c],mid+1,se);
    st[c]=st[ls[c]]|st[rs[c]];
}
void Update(int c,int ss,int se,int qs,int qe,int val){
    push(c);
    if(ss>se||ss>qe||se<qs)return;
    if(qs<=ss&&se<=qe){
        lzy[c]=(1LL<<val);
        push(c);
        return;
    }
    int mid=ss+se>>1;
    Update(ls[c],ss,mid,qs,qe,val);
    Update(rs[c],mid+1,se,qs,qe,val);
    st[c]=st[ls[c]]|st[rs[c]];
}
ll Get(int c,int ss,int se,int qs,int qe){
    push(c);
    if(ss>se||se<qs||ss>qe)return 0LL;
    if(qs<=ss&&qe>=se)return st[c];
    int mid=ss+se>>1;
    return Get(ls[c],ss,mid,qs,qe)|Get(rs[c],mid+1,se,qs,qe);
}

int main(){
    int n,q;scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++)scanf("%i",&col[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%i%i",&u,&v);
        E[u].pb(v);
        E[v].pb(u);
    }
    DFS(1,0);
    Build(root,1,n);
    while(q--){
        int type;scanf("%i",&type);
        if(type==1){
            int v,c;scanf("%i%i",&v,&c);
            Update(root,1,n,lid[v],rid[v],c);
        }else{
            int x;scanf("%i",&x);
            ll res=Get(root,1,n,lid[x],rid[x]);
            int ans=0;
            for(int i=1;i<=60;i++)if(res&(1LL<<i))ans++;
            printf("%i\n",ans);
        }
    }
    return 0;
}