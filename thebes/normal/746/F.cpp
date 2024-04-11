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
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 2e5+5;
ll n, w, k, a[MN], ps[MN], i, j, ans, f[MN], t;
set<pll> b, c;

int main(){
    scanf("%lld%lld%lld",&n,&w,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&ps[i]);
        ps[i] += ps[i-1];
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=j=n;i>=1;i--){
        if(b.size()<w){
            b.insert({a[i],i});
            f[i] = 1;
            t += ceil(a[i]/2.0);
        }
        else if(b.begin()->first<a[i]){
            pii tmp = *b.begin(); b.erase(b.begin());
            t -= ceil(tmp.first/2.0);
            b.insert({a[i],i});
            t += ceil(a[i]/2.0);
            f[i] = 1;
            c.insert({-tmp.first,tmp.second});
            t += tmp.first;
            f[tmp.second] = 0;
        }
        else{
            c.insert({-a[i],i});
            t += a[i];
        }
        while(j>=i&&t>k){
            if(f[j]){
                t -= ceil(a[j]/2.0);
                b.erase(b.find({a[j],j}));
                if(c.size()){
                    pii tmp = *c.begin(); c.erase(c.begin());
                    tmp.first = -tmp.first;
                    t -= tmp.first;
                    t += ceil(tmp.first/2.0);
                    f[tmp.second] = 1;
                    b.insert(tmp);
                }
            }
            else{
                t -= a[j];
                c.erase(c.find({-a[j],j}));
            }
            j--;
        }
        ans = max(ans, ps[j]-ps[i-1]);
    }
    printf("%lld\n",ans);
    return 0;
}