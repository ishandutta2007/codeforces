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
ll n, i, j, a[MN], b[MN], bit[2][MN], o[MN];
void upd(int id,int p,int v){for(;p<=n;p+=p&-p)bit[id][p]+=v;}
int qu(int id,int p){int r=0;for(;p;p-=p&-p)r+=bit[id][p];return r;}
set<int> ok;

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    for(i=n;i>=1;i--){
        o[i]+=qu(0,a[i]+1)+qu(1,b[i]+1);
        o[i-1]+=o[i]/(n-i+1);
        o[i]%=(n-i+1);
        upd(0,a[i]+1,1);
        upd(1,b[i]+1,1);
    }
    memset(bit,0,sizeof(bit));
    for(i=1;i<=n;i++)
        upd(0,i,1),ok.insert(i);
    for(i=1;i<=n;i++){
        int lo=1, hi=n;
        while(lo<hi){
            int m=(lo+hi)>>1;
            auto it=ok.lower_bound(m);
            if(it!=ok.end()){
                if(qu(0,*it)>o[i]) hi=m;
                else lo=m+1;
            }
            else hi=m;
        }
        lo=*(ok.lower_bound(lo));
        printf("%d ",lo-1);
        upd(0,lo,-1); ok.erase(lo);
    }
    printf("\n");
    return 0;
}