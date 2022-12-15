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

const int MN = 2e5+5, mod = 1e9+7;
int fac[MN]={1}, inv[MN]={1}, f, w, h, i, k, ans;

int qpow(int b,int exp){
    if(exp<=0) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}

inline int C(int n,int r){
    return (n>=r)?1LL*fac[n]*inv[r]%mod*inv[n-r]%mod:0;
}

int main(){
    for(i=1;i<MN;i++){
        fac[i]=1LL*i*fac[i-1]%mod;
        inv[i]=1LL*qpow(i,mod-2)*inv[i-1]%mod;
    }
    scanf("%d%d%d",&f,&w,&h);
    if(!w){
        pr(1);
        return 0;
    }
    for(i=1;i*(h+1)<=w;i++){
        if(i<=f){
            int df = C(f-1,i-1);
            int dw = C(w-i*h-1,i-1);
            ans = (1LL*ans+1LL*df*dw)%mod;
        }
        if(i+1<=f){
            int df = C(f-1,i);
            int dw = C(w-i*h-1,i-1);
            ans = (1LL*ans+1LL*df*dw)%mod;
        }
        if(i<=f){
            int df = C(f-1,i-1);
            int dw = C(w-i*h-1,i-1);
            ans = (1LL*ans+1LL*df*dw)%mod;
        }
        if(i-1<=f){
            if(i-1==0&&!f){
                int dw = C(w-i*h-1,i-1);
                ans = (ans+dw)%mod;
            }
            else{
                int df = C(f-1,i-2);
                int dw = C(w-i*h-1,i-1);
                ans = (1LL*ans+1LL*df*dw)%mod;
            }
        }
    }
    int tot = 0;
    for(i=1;i<=w;i++){
        if(i<=f){
            int df = C(f-1,i-1);
            int dw = C(w-1,i-1);
            tot = (1LL*tot+1LL*df*dw)%mod;
        }
        if(i+1<=f){
            int df = C(f-1,i);
            int dw = C(w-1,i-1);
            tot = (1LL*tot+1LL*df*dw)%mod;
        }
        if(i<=f){
            int df = C(f-1,i-1);
            int dw = C(w-1,i-1);
            tot = (1LL*tot+1LL*df*dw)%mod;
        }
        if(i-1<=f){
            if(i-1==0&&!f){
                int dw = C(w-1,i-1);
                tot = (tot+dw)%mod;
            }
            else{
                int df = C(f-1,i-2);
                int dw = C(w-1,i-1);
                tot = (1LL*tot+1LL*df*dw)%mod;
            }
        }
    }
    printf("%d\n",1LL*ans*qpow(tot,mod-2)%mod);
    return 0;
}