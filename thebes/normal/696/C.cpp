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

const ll MN = 1e5+5, mod = 1e9+7;
ll k, x, n=1, m[2][2], b[2][2], t[2][2];

inline void mul(bool dbl=1){
    memset(t,0,sizeof(t));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                if(dbl) t[i][j]+=m[i][k]*m[k][j];
                else t[i][j]+=m[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            m[i][j]=t[i][j]%mod;
    }
}

ll qpow(ll b,ll exp){
    if(exp<=0) return 1LL;
    else if(exp&1) return b*qpow(b,exp-1)%mod;
    else{ll r=qpow(b,exp>>1); return r*r%mod;}
}

void matpow(ll exp){
    if(exp<=0) return;
    else if(exp&1) matpow(exp-1),mul(0);
    else matpow(exp>>1),mul();
}

int main(){
    b[0][1]=b[1][1]=1; b[1][0]=2;
    scanf("%lld",&k);
    for(int i=1;i<=k;i++){
        scanf("%lld",&x);
        m[0][0]=m[1][1]=1;
        m[0][1]=m[1][0]=0;
        matpow(x);
        x%=(mod-1);
        n=x*n%(mod-1);
        for(int j=0;j<2;j++){
            for(int l=0;l<2;l++)
                b[j][l]=m[j][l];
        }
    }
    ll res=(m[0][0]*qpow(2,mod-2))%mod;
    ll div=qpow(2,(n-1+mod-1)%(mod-1));
    printf("%lld/%lld\n",res,div);
    return 0;
}