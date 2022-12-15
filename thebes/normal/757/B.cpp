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
/*
const int MN = 1e6+6, mod = 1e9+7;
int fn[MN], q, n, m, i, j, c[22][22], p[MN], d[MN];
vi f[MN], r[MN];

inline int cnt(int x){
    int res = 1;
    if(d[x]){
        for(auto v : r[x]) res*=(1+v);
        return res;
    }
    d[x]=1;
    int t = x;
    for(auto v : f[x]){
        int c = 0;
        while(t%v==0){
            t /= v;
            c++;
        }
        r[x].pb(c);
        res *= (1+c);
    }
    return res;
}

int main(){
    int mx = 0;
    for(i=2;i<MN;i++){
        if(p[i]){mx = max(mx, cnt(i));continue;}
        for(j=i;j<MN;j+=i) f[j].pb(i), p[j]=1;
        p[i]=0;
        mx = max(mx, cnt(i));
    }
    printf("%d\n",mx);
    return 0;
}*/

const int MN = 1e5+5;
int cnt[MN], n, i, j, x, ans, c;

int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&x), cnt[x]++;
    for(i=2;i<MN;i++){
        c = 0;
        for(j=i;j<MN;j+=i) c += cnt[j];
        ans = max(ans, c);
    }
    printf("%d\n",max(1,ans));
    return 0;
}