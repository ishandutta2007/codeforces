#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)
#define F first
#define S second

const int MN = 2e6+6, mod = 1e9+7;
int n, i, j, f[MN], ans, c1, c2, pw[22]={1};

int qpow(int b,int exp){
    if(exp<=0) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}

inline int popcnt(int x){
    int res=0;
    while(x) x-=x&-x, res++;
    return res;
}

void transform(int l,int r){
    if(l==r) return;
    int m=(l+r)>>1;
    transform(l,m);
    transform(m+1,r);
    for(int i=0;i<=m-l;i++){
        int a=f[l+i];
        int b=f[m+1+i];
        f[l+i]=a+b;
        if(f[l+i]>=mod) f[l+i]-=mod;
        f[m+1+i]=a-b;
        if(f[m+1+i]<0) f[m+1+i]+=mod;
    }
}

int main(){
    scanf("%d\n",&n);
    for(i=0;i<(1<<n);i++)
        f[i]=getchar()=='1';
    transform(0,(1<<n)-1);
    for(i=1;i<=n;i++)
        pw[i]=pw[i-1]*2;
    for(i=0;i<(1<<n);i++)
        f[i]=(1LL*f[i]*f[i])%mod;
    transform(0,(1<<n)-1);
    int inv=qpow(qpow(2,mod-2),n);
    for(i=0;i<(1<<n);i++)
        f[i]=1LL*f[i]*inv%mod;
    for(i=0;i<(1<<n);i++)
        ans=(ans+1LL*pw[popcnt(i^((1<<n)-1))]*f[i])%mod;
    printf("%d\n",3LL*ans%mod);
    return 0;
}