//sanjao sam kako svadbu spremam
//goste imam samo dragu nemam
//zasto tvoja mladost kao ruza vene
//sto si se budalo propila zbog mene
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int ri(){int x;scanf("%i",&x);return x;}
const int N=200050;
int ls[N],rs[N],root,tsz,sum[N],tag[N],n;
void upd(int c,int ss,int se){tag[c]^=1;sum[c]=se-ss+1-sum[c];}
void push(int c,int ss,int se){
    if(!tag[c])return;
    int mid=ss+se>>1;
    upd(ls[c],ss,mid);
    upd(rs[c],mid+1,se);
    tag[c]=0;
}
void Build(int &c,int ss,int se){
    c=++tsz;if(ss==se)return;
    int mid=ss+se>>1;
    Build(ls[c],ss,mid);
    Build(rs[c],mid+1,se);
}
void Set(int c,int ss,int se,int qs,int qe){
    if(qs>qe || qs>se || ss>qe)return;
    if(qs<=ss && qe>=se){upd(c,ss,se);return;}
    push(c,ss,se);
    int mid=ss+se>>1;
    Set(ls[c],ss,mid,qs,qe);
    Set(rs[c],mid+1,se,qs,qe);
    sum[c]=sum[ls[c]]+sum[rs[c]];
}
int Get(int c,int ss,int se,int qs,int qe){
    if(qs>qe || qs>se || ss>qe)return 0;
    if(qs<=ss && qe>=se)return sum[c];
    push(c,ss,se);
    int mid=ss+se>>1;
    return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int x[N];
vector<pair<int,int>> v[N];
int main(){
    n=ri();int k=ri();
    ll ans=(ll)n*(n-1)*(n-2)/6;
    for(int i=1;i<=n;i++)x[i]=ri();
    sort(x+1,x+1+n);
    while(k--){
        int l=ri(),r=ri();
        l=lower_bound(x+1,x+1+n,l)-x;
        r=upper_bound(x+1,x+1+n,r)-x;
        v[l].pb({l,r-1});
        v[r].pb({l,r-1});
    }
    Build(root,1,n);
    for(int i=1;i<=n;i++){
        for(auto p:v[i])Set(root,1,n,p.first,p.second);
        Set(root,1,n,i,i);
        int cnt=Get(root,1,n,1,n)-Get(root,1,n,i,i);
        ans-=(ll)cnt*(cnt-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}