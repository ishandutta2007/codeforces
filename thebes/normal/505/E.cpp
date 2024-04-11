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

const ll MN = 1e5+5;
ll n, m, k, p, x, y, arr[MN], h[MN], c[MN], lo, hi, mid, i, j, mn[MN];
map<int,int> ok;

inline bool mrk(ll x){
    auto it = ok.lower_bound(x);
    if(it==ok.end()) return 0;
    it->second --;
    if(!it->second) ok.erase(it);
    return 1;
}

int main(){
    scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
    for(i=1;i<=n;i++){
        scanf("%lld%lld",&x,&y);
        arr[i]=x+y*m;
        h[i]=x, c[i]=y;
        lo=max(lo,y);
    }
    hi=1e15;
    while(lo<hi){
        mid = (lo+hi)>>1;
        ok.clear(); bool f=0;
        for(i=0;i<m;i++)
            ok[i]=k;
        for(i=1;i<=n;i++){
            ll res = arr[i]-mid, cur, idx;
            idx = max(0LL,(ll)ceil((res-h[i])/(double)c[i]));
            cur = idx?res-h[i]-(idx-1)*c[i]:res;
            while(res>0){
                res -= p;
                if(!mrk(idx)){
                    f = 1;
                    break;
                }
                if(cur>=p){
                    cur -= p;
                    if(!cur){
                        idx--;
                        if(!idx) cur=h[i];
                        else cur=c[i];
                    }
                }
                else{
                    ll jmp = ceil((p-cur)/(double)c[i]);
                    jmp = min(jmp,idx);
                    idx -= jmp;
                    ll rem=p-cur-(jmp-1)*c[i];
                    cur=idx?c[i]-rem:h[i]-rem;
                }
            }
            if(f) break;
        }
        if(f) lo=mid+1;
        else hi=mid;
    }
    printf("%lld\n",lo);
    return 0;
}