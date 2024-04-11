#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

const int MN = 5e5+5, mod = 1e9+3;
int n, i, j, dep[MN], hsh[MN], sa[MN], pw[MN]={1}, len[MN], lo, hi, m, lcp[MN]; ll ans;
string s; pii arr[MN]; int bit[MN]; set<int> bad;

inline void upd(int p,int val){for(;p<=n+1;p+=p&-p)bit[p]+=val;}
inline int qu(int p){int r=0;for(;p;p-=p&-p)r+=bit[p];return r;}

inline int get(int x,int y){
    int ret=(hsh[y]-hsh[x-1]*pw[y-x+1]);
    return ret;
}

inline bool cmp(int i,int j){
    lo=0, hi=n-max(i,j)+1;
    while(lo<hi){
        m=(lo+hi)>>1;
        if(get(i,i+m)!=get(j,j+m)) hi=m;
        else lo=m+1;
    }
    return s[i+lo-1]<s[j+lo-1];
}

int main(){
    cin >> n >> s; n++;
    for(i=0;i<n;i++){
        dep[i+1]=dep[i]+(s[i]=='('?1:-1);
        arr[i+1]={dep[i],i+1};
        hsh[i+1]=(hsh[i]*133+s[i]);
        pw[i+1]=(133*pw[i]);
    }
    for(i=1;i<=n;i++)
        sa[i]=i;
    stable_sort(sa+1,sa+n+1,cmp);
    sort(arr+1,arr+n+1,[](pii i,pii j){return i.first<j.first;});
    bad.insert(n+1);
    for(i=1;i<=n;i=j){
        for(j=i;j<=n&&arr[j].first==arr[i].first;j++){
            auto it = bad.lower_bound(arr[j].second);
            len[arr[j].second]=*it-arr[j].second;
        }
        for(j=i;j<=n&&arr[j].first==arr[i].first;j++)
            bad.insert(arr[j].second);
    }
    lcp[sa[1]]=0;
    for(i=1;i<n;i++){
        lo=0, hi=min(len[sa[i]],len[sa[i+1]]);
        while(lo<hi){
            m=(lo+hi)>>1;
            if(get(sa[i],sa[i]+m)!=get(sa[i+1],sa[i+1]+m)) hi=m;
            else lo=m+1;
        }
        lcp[sa[i+1]]=lo;
    }
    for(i=1;i<=n;i=j){
        for(j=i;j<=n&&arr[j].first==arr[i].first;j++)
            upd(arr[j].second,1);
        for(j=i;j<=n&&arr[j].first==arr[i].first;j++){
            int id=arr[j].second;
            ans+=max(0,qu(id+len[id]-1)-qu(id+lcp[id]));
        }
        for(j=i;j<=n&&arr[j].first==arr[i].first;j++)
            upd(arr[j].second,-1);
    }
    printf("%lld\n",ans);
    return 0;
}