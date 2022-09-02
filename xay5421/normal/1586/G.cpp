// author: xay5421
// created: Sun Oct 17 19:52:07 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
    int k3=1;
    for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
    return k3;
}
const int N=4e5+5;
set<int>r;
int a[N],b[N],c[N],id[N],f[N];
int n,m,ans;
int lowbit(int x){return x&-x;}
void add(int x,int y){while(x<=n*2)f[x]=ad(f[x],y),x+=lowbit(x);}
int qry(int x){int ans=0;while(x)ans=ad(ans,f[x]),x-=lowbit(x);return ans;}
bool cmp(int i,int j){return a[i]<a[j];}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d",&a[i],&b[i]),id[i]=i;
    sort(id+1,id+n+1,cmp);
    scanf("%d",&m);
    rep(i,1,m)scanf("%d",&c[i]),r.insert(b[c[i]]);
    rep(i,1,n){
        int t=qry(b[id[i]]);
        if(r.size()&&b[id[i]]<=*(--r.end()))t=ad(t,1);
        ans=ad(ans,t);add(1,t);add(b[id[i]]+1,su(0,t));
        if(r.find(b[id[i]])!=r.end())r.erase(b[id[i]]);
    }
    printf("%d\n",ans);
    return 0;
}