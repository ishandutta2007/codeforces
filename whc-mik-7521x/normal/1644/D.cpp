#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=998244353;
int t,n,m,k,q,rl[N],cl[N],pdr[N],pdc[N],opx[N],opy[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&k,&q);
        vector<int>cp,rp;
        for(int i=1;i<=q;i++){
            scanf("%d%d",&opx[i],&opy[i]);
            rp.push_back(opx[i]);
            cp.push_back(opy[i]);
            rl[opx[i]]=i;
            cl[opy[i]]=i;
        }
        stable_sort(rp.begin(),rp.end());
        rp.erase(unique(rp.begin(),rp.end()),rp.end());
        stable_sort(cp.begin(),cp.end());
        cp.erase(unique(cp.begin(),cp.end()),cp.end());
        int cntr=0,cntc=0,timr=1,timc=1;
        for(int i=q;i>=1;i--){
            if(!pdr[opx[i]])pdr[opx[i]]=1,cntr++;
            if(!pdc[opy[i]])pdc[opy[i]]=1,cntc++;
            if(cntr==n)timr=max(timr,i);
            if(cntc==m)timc=max(timc,i);
        }
        timr=max(timr,timc);
        vector<int>v;
        for(int i:rp){
            if(rl[i]>=timr)v.push_back(rl[i]);
        }
        for(int i:cp){
            if(cl[i]>=timr)v.push_back(cl[i]);
        }
        stable_sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int now=v.size();
        printf("%lld\n",fp(k,now));
        for(int i:rp)rl[i]=0;
        for(int i:cp)cl[i]=0;
        for(int i=1;i<=q;i++)pdr[opx[i]]=0,pdc[opy[i]]=0;
    }
    return  0;
}