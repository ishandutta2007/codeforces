#include <bits/stdc++.h>
using namespace std;

const int N=100050;
const int M=20*N;

int root[N],ls[M],rs[M],st[M],tsz;

void Set(int&c,int ss,int se,int qi,int val){
    if(!c)c=++tsz;
    if(ss==se){
        st[c]=max(st[c],val);
        return;
    }
    int mid=ss+se>>1;
    if(qi<=mid)Set(ls[c],ss,mid,qi,val);
    else Set(rs[c],mid+1,se,qi,val);
    st[c]=max(st[ls[c]],st[rs[c]]);
}

int Get(int c,int ss,int se,int qs,int qe){
    if(ss>se||ss>qe||se<qs)return 0;
    if(qs<=ss&&se<=qe)return st[c];
    int mid=ss+se>>1;
    return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}

int main(){
    int n,m;scanf("%i%i",&n,&m);
    int ans=1;
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%i%i%i",&u,&v,&w);
        int best=Get(root[u],0,N,0,w-1);
        Set(root[v],0,N,w,best+1);
        ans=max(ans,best+1);
    }
    printf("%i",ans);
    return 0;
}