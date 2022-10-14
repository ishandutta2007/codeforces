#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int M=8*N;
int n,typ[N],l[N],r[N],L[N],R[N],f[N],tsz;
vector<int> Qs[M];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    L[x]=min(L[x],L[y]);
    R[x]=max(R[x],R[y]);
    f[y]=x;
}
namespace Compress{
    vector<int> v;
    void Ins(int x){v.pb(x);}
    void Build(){sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());}
    int Get(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
};
void Set(int c,int ss,int se,int qs,int qe,int x){
    if(ss>se||ss>qe||se<qs||qs>qe)return;
    if(qs<=ss&&se<=qe){Qs[c].pb(x);return;}
    int mid=ss+se>>1;
    Set(c<<1,ss,mid,qs,qe,x);
    Set(c<<1|1,mid+1,se,qs,qe,x);
}
void Update(int c,int ss,int se,int qi,int x){
    for(int i:Qs[c])unite(i,x);Qs[c].clear();
    if(ss==se)return;
    int mid=ss+se>>1;
    if(qi<=mid)Update(c<<1,ss,mid,qi,x);
    else Update(c<<1|1,mid+1,se,qi,x);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&typ[i],&l[i],&r[i]);
        if(typ[i]==1){
            Compress::Ins(l[i]);
            Compress::Ins(r[i]);
        }
    }
    for(int i=1;i<=n;i++)f[i]=i;
    Compress::Build();
    for(int i=1;i<=n;i++){
        //printf(":%d %d\n",l[i],r[i]);
        if(typ[i]==1){
            l[i]=Compress::Get(l[i]);
            r[i]=Compress::Get(r[i]);
            ++tsz;L[tsz]=l[i];R[tsz]=r[i];
            Update(1,1,N,l[i],tsz);
            Update(1,1,N,r[i],tsz);
            int root=find(tsz);
            Set(1,1,N,L[root]+1,R[root]-1,root);
        }else{
            l[i]=find(l[i]);
            r[i]=find(r[i]);
            puts((l[i]==r[i]||(L[r[i]]<=L[l[i]]&&R[l[i]]<=R[r[i]]))?"YES":"NO");
        }
    }
}