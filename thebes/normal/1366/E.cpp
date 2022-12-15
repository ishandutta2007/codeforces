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
#define F first
#define S second

const int MN = 2e5+5, mod = 998244353;
int n, m, i, j, x, y, lb, a[MN], mn[MN], nxt, ans=1;
vi pos[MN];
map<int,int> mp;

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!mp.count(a[i])) mp[a[i]]=++nxt;
        pos[mp[a[i]]].pb(i);
    }
    mn[n] = a[n];
    for(i=n-1;i>=1;i--)
        mn[i]=min(mn[i+1],a[i]);
    lb = 1;
    int fst=0;
    for(i=1;i<=m;i++){
        scanf("%d",&x);
        if(!mp.count(x)||lb>n){
            printf("0\n");
            return 0;
        }
        int id = mp[x];
        int f = pos[id][0], s = pos[id].back();
        if(s<lb){
            printf("0\n");
            return 0;
        }
        int lo=lb, hi=n+1;
        while(lo<hi){
            int mid=lo+hi>>1;
            if(mn[mid]>=x) hi=mid;
            else lo=mid+1;
        }
        if(lo>s){
            printf("0\n");
            return 0;
        }
        if(fst) ans=1LL*ans*(s-lo+1)%mod;
        else{
            fst=1;
            if(lo!=1){
                printf("0\n");
                return 0;
            }
        }
        lb=s+1;
    }
    printf("%d\n",ans);
    return 0;
}