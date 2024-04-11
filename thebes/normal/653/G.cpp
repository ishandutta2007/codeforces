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

const int MN = 3e5+5, mod = 1e9+7;
int N, x, cnt[MN], ok[MN], i, j, ans, fac[MN]={1}, inv[MN]={1}, ps[MN];
vi vec;

int qpow(int b,int exp){
    if(exp<=0) return 1;
    else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
    else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}

inline int C(int n,int k){return 1LL*fac[n]*inv[k]%mod*inv[n-k]%mod;}

inline void solve(){
    int left=N-vec.size();
    for(int i=0;i<vec.size();i++){
        int l=0, r=0;
        if(left) l=ps[left-1];
        if(N-left) r=(ps[N-1]-ps[left]+mod)%mod;
        ans=(ans+1LL*(l-r+mod)*vec[i])%mod;
        left++;
    }
}

int main(){
    for(i=1;i<MN;i++){
        fac[i]=1LL*i*fac[i-1]%mod;
        inv[i]=1LL*qpow(i,mod-2)*inv[i-1]%mod;
    }
    for(scanf("%d",&N),i=1;i<=N;i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    for(i=0;i<N;i++){
        ps[i]=C(N-1,i)+(i?ps[i-1]:0);
        if(ps[i]>=mod) ps[i]-=mod;
    }
    for(i=2;i<MN;i++){
        if(!ok[i]){
            vec.clear();
            int pre=N, cur, exp=0; ll pw=i;
            while(pw<MN){
                cur=0;
                for(j=pw;j<MN;j+=pw)
                    cur+=cnt[j];
                pre-=cur;
                if(exp){
                    while(pre--)
                        vec.pb(exp);
                }
                exp++; pre=cur; pw*=i;
            }
            if(exp){
                while(pre--)
                    vec.pb(exp);
            }
            solve();
        }
        for(j=i;j<MN;j+=i)
            ok[j]=1;
    }
    printf("%d\n",ans);
    return 0;
}