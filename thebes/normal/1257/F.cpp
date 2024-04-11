#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}
}

using namespace debug;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
const int MN = 105, MB = 15; const ll mod=(1e9+7)*(1e7+3);
int n, i, j, a[MN], ans, flag, hsh;
map<ll,int> st; vi b;
inline int get(int x,int b){return (a[x]&(1<<b))?1:0;}
void go(int s,int e,int k,bool chk){
    if(s<e){
        ll res=0;
        if(chk){
            for(auto v : b)
                res=(1LL*(res*131)-v+2*MB)%mod;
            if(st.count(res))
                flag=1,ans=k+st[res];
        }
        else{
            for(auto v : b)
                res=(1LL*(res*131)+v+2*MB)%mod;
            st[res]=k;
        }
    }
    else{
        int r = get(1,s);
        for(int i=1;i<=n;i++)
            b[i]+=(!get(i,s))-(!r);
        go(s-1,e,k|(1<<s),chk);
        for(int i=1;i<=n;i++){
            b[i]-=(!get(i,s))-(!r);
            b[i]+=get(i,s)-r;
        }
        go(s-1,e,k,chk);
        for(int i=1;i<=n;i++)
            b[i]-=get(i,s)-r;
    }
}

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++) scanf("%d",&a[i]);
    b.resize(n+1);
    go(MB-1,0,0,0);
    go(2*MB-1,MB,0,1);
    printf("%d\n",flag?ans:-1);
    return 0;
}