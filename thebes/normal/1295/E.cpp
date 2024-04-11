#include <bits/stdc++.h>
using namespace std;

namespace debug{
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
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const set<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T,class T2>
    void __(const map<T,T2>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(make_pair(v.first,v.second)),_ffs=1;__("}");}
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
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(x);i>=(y);i--)

const int MN = 2e5+5;
ll n, i, a[MN], b[MN], ans, st[3*MN], lz[3*MN];

inline void upd_lz(int i,int s,int e){
    if(lz[i]){
        st[i]+=lz[i];
        if(s!=e){
            lz[2*i]+=lz[i];
            lz[2*i+1]+=lz[i];
        }
        lz[i]=0;
    }
}

void upd(int i,int s,int e,int ss,int se,ll val){
    if(ss>se) return;
    upd_lz(i,s,e);
    if(s>=ss&&e<=se){
        lz[i]=val; upd_lz(i,s,e);
    }
    else{
        if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val),upd_lz(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val),upd_lz(2*i+1,(s+e)/2+1,e);
        else upd(2*i,s,(s+e)/2,ss,se,val),upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        st[i]=min(st[2*i],st[2*i+1]);
    }
}

ll qu(int i,int s,int e,int ss,int se){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return min(qu(2*i,s,(s+e)/2,ss,se),qu(2*i+1,(s+e)/2+1,e,ss,se));
}

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(i=1;i<=n;i++) scanf("%lld",&b[i]);
    ans=min(b[1],b[n]);
    for(i=1;i<=n;i++){
        upd(1,1,n,a[i],n,b[i]);
    }
    for(i=1;i<n;i++){
        upd(1,1,n,a[i],n,-b[i]);
        upd(1,1,n,1,a[i]-1,b[i]);
        ans=min(ans,st[1]);
    }
    printf("%lld\n",ans);
    return 0;
}