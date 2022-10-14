#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>

const int N=300050;
const int M=2*N;

int n,a[N],mn[M],g[M],root,ls[M],rs[M],tsz;
void Build(int&c,int ss,int se){
    c=++tsz;
    if(ss>se)return;
    if(ss==se){
        mn[c]=g[c]=a[ss];
        return;
    }
    int mid=ss+se>>1;
    Build(ls[c],ss,mid);
    Build(rs[c],mid+1,se);
    mn[c]=min(mn[ls[c]],mn[rs[c]]);
    g[c]=__gcd(g[ls[c]],g[rs[c]]);
}
pii Get(int c,int ss,int se,int qs,int qe){
    if(ss>se||se<qs||ss>qe)return {1e9,0};
    if(qs<=ss&&qe>=se)return {mn[c],g[c]};
    int mid=ss+se>>1;
    pii L=Get(ls[c],ss,mid,qs,qe);
    pii R=Get(rs[c],mid+1,se,qs,qe);
    return {min(L.first,R.first),__gcd(L.second,R.second)};
}

bool IsOk(int l,int r){
    pii val=Get(root,1,n,l,r);
    return val.first==val.second;
}

int main(){
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    Build(root,1,n);
    int bot=1,top=n,mx=0;
    vector<int> ans;
    while(bot<=top){
        int mid=bot+top>>1;
        vector<int> pos;
        for(int i=1;i<=n-mid+1;i++)if(IsOk(i,i+mid-1))pos.pb(i);
        if(!pos.empty()){
            ans=pos;
            mx=mid-1;
            bot=mid+1;
        }else top=mid-1;
    }
    printf("%i %i\n",ans.size(),mx);
    for(int i:ans)printf("%i ",i);
    return 0;
}