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

const int MN = 2e5+5;
ll n, i, j, arr[MN]; ll ans, st[3*MN], lz[3*MN], mx[3*MN];
vl elem[MN], pos;

inline void upd_lz(int i,int s,int e){
    if(lz[i]){
        st[i]=1LL*(e-s+1)*lz[i];
        mx[i]=lz[i];
        if(s!=e) lz[2*i]=lz[2*i+1]=lz[i];
        lz[i]=0;
    }
}

void upd(int i,int s,int e,int ss,int se,ll val){
    if(ss>se) return;
    upd_lz(i,s,e);
    if(s>=ss&&e<=se){lz[i]=val; upd_lz(i,s,e);}
    else{
        if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val),upd_lz(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val),upd_lz(2*i+1,(s+e)/2+1,e);
        else upd(2*i,s,(s+e)/2,ss,se,val),upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        st[i]=st[2*i]+st[2*i+1];
        mx[i]=max(mx[2*i],mx[2*i+1]);
    }
}

ll qu(int i,int s,int e,int ss,int se){
    if(ss>se) return 0;
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return qu(2*i,s,(s+e)/2,ss,se)+qu(2*i+1,(s+e)/2+1,e,ss,se);
}

ll qu2(int i,int s,int e,int ss,int se){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) return mx[i];
    else if((s+e)/2<ss) return qu2(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu2(2*i,s,(s+e)/2,ss,se);
    else return max(qu2(2*i,s,(s+e)/2,ss,se),qu2(2*i+1,(s+e)/2+1,e,ss,se));
}

ll qu3(int ss,int se,ll val){
    int lo=ss, hi=se+1;
    while(lo<hi){
        int m=(lo+hi)>>1;
        if(qu2(1,1,n,ss,m)>=val) hi=m;
        else lo=m+1;
    }
    return lo;
}

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
        upd(1,1,n,i,i,i);
        elem[arr[i]].pb(i);
    }
    for(i=200000;i>=1;i--){
        pos.clear();
        for(j=i;j<MN;j+=i){
            for(auto v : elem[j])
                pos.pb(v);
        }
        sort(pos.begin(),pos.end());
        if(pos.size()>=2){
            ll idx=qu3(1,pos[0],pos[pos.size()-2]);
            ans += 1LL*i*((idx-1)*pos[pos.size()-2]-qu(1,1,n,1,idx-1));
            upd(1,1,n,1,idx-1,pos[pos.size()-2]);
            idx=qu3(pos[0]+1,pos[1],pos.back());
            ans += 1LL*i*((idx-1-pos[0])*pos.back()-qu(1,1,n,pos[0]+1,idx-1));
            upd(1,1,n,pos[0]+1,idx-1,pos.back());
            ans += 1LL*i*((n-pos[1])*(n+1)-qu(1,1,n,pos[1]+1,n));
            upd(1,1,n,pos[1]+1,n,n+1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}