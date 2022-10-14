#include <bits/stdc++.h>
using namespace std;
const int N=200050;
const int M=N*2;
int a[N],b[N],root,ls[M],rs[M],tsz;
long long st[M],lzy[M];
void Add(int&c,int ss,int se,int qs,int qe,int val){
    if(!c)c=++tsz;
    if(ss>se||ss>qe||se<qs)return;
    if(qs<=ss&&se<=qe){
        st[c]+=val,lzy[c]+=val;
        return;
    }
    int mid=ss+se>>1;
    Add(ls[c],ss,mid,qs,qe,val);
    Add(rs[c],mid+1,se,qs,qe,val);
    st[c]=min(st[ls[c]],st[rs[c]])+lzy[c];
}
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=1;i<=n;i++)scanf("%i",&b[i]),Add(root,0,n,a[i],n,b[i]);
    long long ans=1e18;
    for(int i=1;i<n;i++){
        Add(root,0,n,a[i],n,-b[i]);
        Add(root,0,n,0,a[i]-1,b[i]);
        ans=min(ans,st[root]);
    }
    printf("%lld",ans);
    return 0;
}