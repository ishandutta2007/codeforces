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

const int MN = 1e5+5;
ll t, n[3], arr[MN], i, j, k, x, ans, bb[3], cc[3];
inline ll sq(ll x){return x*x;}
set<ll> b, c;

int main(){
    for(scanf("%lld",&t);t;t--){
        b.clear(); c.clear();
        for(scanf("%lld%lld%lld",&n[0],&n[1],&n[2]),j=1;j<=n[0];j++)
            scanf("%lld",&arr[j]);
        for(j=1;j<=n[1];j++)
            scanf("%lld",&x), b.insert(x);
        for(j=1;j<=n[2];j++)
            scanf("%lld",&x), c.insert(x);
        sort(arr+1,arr+n[0]+1);
        ans=1LL<<62;
        for(i=1;i<=n[0];i++){
            auto it=b.upper_bound(arr[i]);
            if(it!=b.end()){bb[2]=*it;}
            else bb[2]=-1<<30;
            it=b.lower_bound(arr[i]);
            if(it!=b.end())bb[1]=*it;
            else bb[1]=-1<<30;
            if(it!=b.begin()){it--; bb[0]=*it;}
            else bb[0]=-1<<30;
            it=c.upper_bound(arr[i]);
            if(it!=c.end())cc[2]=*it;
            else cc[2]=-1<<30;
            it=c.lower_bound(arr[i]);
            if(it!=c.end())cc[1]=*it;
            else cc[1]=-1<<30;
            if(it!=c.begin()){it--; cc[0]=*it;}
            else cc[0]=-1<<30;
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                    ans=min(ans,sq(arr[i]-bb[j])+sq(arr[i]-cc[k])+sq(bb[j]-cc[k]));
                }
            }
            for(j=0;j<3;j++){
                ll mid=(arr[i]+1+bb[j])/2;
                auto it=c.lower_bound(mid);
                if(it!=c.end()) ans=min(ans,sq(arr[i]-bb[j])+sq(arr[i]-*it)+sq(bb[j]-*it));
                if(it!=c.begin()){it--; ans=min(ans,sq(arr[i]-bb[j])+sq(arr[i]-*it)+sq(bb[j]-*it));}
                mid=(arr[i]+1+cc[j])/2;
                it=b.lower_bound(mid);
                if(it!=b.end()) ans=min(ans,sq(arr[i]-cc[j])+sq(arr[i]-*it)+sq(cc[j]-*it));
                if(it!=b.begin()){it--; ans=min(ans,sq(arr[i]-cc[j])+sq(arr[i]-*it)+sq(cc[j]-*it));}
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}