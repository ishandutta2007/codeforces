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
ll n, m, s, i, j, c[MN], lo, hi, ans[MN];
pll a[MN], b[MN]; 
struct pq{bool operator()(const pll&i,const pll&j){return i.first>j.first;}};
priority_queue<pll,vector<pll>,pq> q;

bool chk(ll mid){
    ll cost=0;
    while(q.size()) q.pop();
    for(i=m,j=n;i>=1;){
        while(j>=1&&b[j].first>=a[i].first){
            q.push({c[b[j].second],b[j].second});
            j--;
        }
        if(q.empty()) return 0;
        else{
            cost+=q.top().first;
            ll id=q.top().second; q.pop();
            if(cost>s) return 0;
            for(ll hm=0;hm<min(i,mid);hm++){
                ans[a[i-hm].second]=id;
            }
            i-=mid;
        }
    }
    return 1;
}

int main(){
    scanf("%lld%lld%lld",&n,&m,&s);
    for(i=1;i<=m;i++){
        scanf("%lld",&a[i].first);
        a[i].second=i;
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&b[i].first);
        b[i].second=i;
    }
    sort(a+1,a+m+1,[](pll i,pll j){return i.first<j.first;});
    sort(b+1,b+n+1,[](pll i,pll j){return i.first<j.first;});
    for(i=1;i<=n;i++)
        scanf("%lld",&c[i]);
    lo=1, hi=m+1;
    while(lo<hi){
        ll mid=(lo+hi)>>1;
        if(chk(mid)) hi=mid;
        else lo=mid+1;
    }
    if(lo==m+1) pr("NO");
    else{
        pr("YES");
        chk(lo);
        for(i=1;i<=m;i++)
            printf("%lld ",ans[i]);
        pr();
    }
    return 0;
}