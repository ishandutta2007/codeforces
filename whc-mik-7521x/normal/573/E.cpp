#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10,M=1e3;
long long val[N],tr[N],pos[N];
long long n,m,l[M],r[M],bel[N],ans;
struct seg{
    long long k,b,h,t,q[M];
    long long calc(long long rt){
        return k*tr[rt]+b+val[rt];
    }
    long double slope(long long x ,long long y){
        if(tr[x]==tr[y])return val[x]>=val[y]?-1e30:1e30;
        else return 1.0*(val[y]-val[x])/(tr[y]-tr[x]);
    }
    void construct(int l,int r){
        h=0;t=1;
        for(long long i=l;i<=r;i++){
            while(h>t&&slope(q[h-1],q[h])<=slope(q[h],pos[i]))h--;
            q[++h]=pos[i];
        }
    }
    void build(long long l,long long r){
        for(int i=l;i<=r;i++)val[i]+=k*tr[i]+b;
        k=b=0;
        construct(l,r);
    }
    pair<long long,long long>query(){
        while(h>t&&calc(q[t])<=calc(q[t+1]))t++;
        return {calc(q[t]),q[t]};
    }
}blc[M];
void modi(int x){
    for(int i=1;i<bel[x];i++)blc[i].b+=tr[x];
    for(int i=bel[x]+1;i<=m;i++)blc[i].k+=1;
    for(int i=l[bel[x]];i<x;i++)val[i]+=tr[x];
    for(int i=x+1;i<=r[bel[x]];i++)val[i]+=tr[i];
    blc[bel[x]].build(l[bel[x]],r[bel[x]]);
}
bool solve(){
    pair<long long,long long>mx={0,0};
    for(int i=1;i<=m;i++)mx=max(mx,blc[i].query());
    if(!mx.first)return 0;
    int now=mx.second;
    ans+=mx.first;
    val[now]=-1e18;
    modi(now);
    return 1;
}
int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&tr[i]);
        val[i]=tr[i],pos[i]=i;
    }
    m=sqrt(n);
    long long len=n/m;
    for(long long i=1;i<=m;i++)l[i]=(i-1)*len+1,r[i]=i*len;
    r[m]=n;
    for(long long i=1;i<=m;i++){
        stable_sort(pos+l[i],pos+r[i]+1,[](int kk,int kkk){return tr[kk]<tr[kkk];});
        for(long long o=l[i];o<=r[i];o++)bel[o]=i;
    }
    for(long long i=1;i<=m;i++)blc[i].build(l[i],r[i]);
    while(solve());
    printf("%lld",ans);
    return  0;
}