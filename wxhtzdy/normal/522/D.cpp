#include <bits/stdc++.h>
using namespace std;
const int N=500050;
const int M=N*20;
const int inf=1e9;
int a[N],mn[M],ls[M],rs[M],root[N],tsz;
map<int,int> lst;
void Set(int p,int&c,int ss,int se,int qi,int val){
    c=++tsz;ls[c]=ls[p];rs[c]=rs[p];mn[c]=min(mn[p],val);
    if(ss==se)return;
    int mid=ss+se>>1;
    if(qi<=mid)Set(ls[p],ls[c],ss,mid,qi,val);
    else Set(rs[p],rs[c],mid+1,se,qi,val);
}
int Get(int c,int ss,int se,int qs,int qe){
    if(ss>qe||se<qs)return inf;
    if(qs<=ss&&se<=qe)return mn[c];
    int mid=ss+se>>1;
    return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int main(){
    int n,m;scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    mn[0]=inf;
    for(int i=1;i<=n;i++){
        root[i]=root[i-1];
        if(lst[a[i]]>=1){
            Set(root[i],root[i],1,n,lst[a[i]],i-lst[a[i]]);
        }
        lst[a[i]]=i;
    }
    while(m--){
        int l,r;scanf("%i%i",&l,&r);
        int ans=Get(root[r],1,n,l,r);
        if(ans==inf)printf("-1\n");
        else printf("%i\n",ans);
    }
    return 0;
}