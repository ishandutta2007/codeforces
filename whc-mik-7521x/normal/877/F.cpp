#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,k,a[N],c[N],q,t,ctl[N<<2],ctr[N<<2],ans[N],tot;
struct query{
    long long l,r,num;
    bool operator<(const query b)const{
        return l/t==b.l/t?((l/t)&1)?r>b.r:r<b.r:l<b.l;
    }
}qu[N];
void incl(long long x){
    ctr[a[x]]++;
    ctl[c[x]]++;
    tot+=ctr[c[x]];
}
void incr(long long x){
    ctr[a[x]]++;
    ctl[c[x]]++;
    tot+=ctl[a[x]];
}
void decl(long long x){
    tot-=ctr[c[x]];
    ctr[a[x]]--;
    ctl[c[x]]--;
}
void decr(long long x){
    tot-=ctl[a[x]];
    ctr[a[x]]--;
    ctl[c[x]]--;
}
int main(){
    scanf("%lld%lld",&n,&k);
    for(long long i=1;i<=n;i++){
        long long x;
        scanf("%lld",&x);
        a[i]=x==1?1:-1;
    }
    for(long long i=1;i<=n;i++){
        long long x;
        scanf("%lld",&x);
        a[i]*=x;
    }
    vector<long long>v;
    for(long long i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    for(long long i=1;i<=n;i++){
        c[i]=a[i-1];
        v.push_back(c[i]);
    }
    for(long long i=1;i<=n;i++){
        a[i]-=k;
        v.push_back(a[i]);
    }
    stable_sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(long long i=1;i<=n;i++){
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
        c[i]=lower_bound(v.begin(),v.end(),c[i])-v.begin();
    }
    t=sqrt(n);
    scanf("%lld",&q);
    for(long long i=1;i<=q;i++){
        scanf("%lld%lld",&qu[i].l,&qu[i].r);
        qu[i].num=i;
    }
    stable_sort(qu+1,qu+n+1);
    long long l=1,r=0;
    for(long long i=1;i<=n;i++){
        while(l>qu[i].l)incl(--l);
        while(r<qu[i].r)incr(++r);
        while(l<qu[i].l)decl(l++);
        while(r>qu[i].r)decr(r--);
        ans[qu[i].num]=tot;
    }
    for(long long i=1;i<=q;i++){
        printf("%lld\n",ans[i]);
    }
    return  0;
}