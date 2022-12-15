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
#define F first
#define S second

const int MN = 2e5+5, MM = 26, mod = 1e9+3;
int n, m, i, j, fs[MM], p[MM], pos[MM], hsh[MN], pw[MN]={1};
inline int get(int l,int r){
    int ret=(hsh[r]-1LL*hsh[l-1]*pw[r-l+1])%mod;
    if(ret<0) ret+=mod;
    return ret;
}
string s, t;
vi ans;

int main(){
    cin >> n >> m >> s >> t;
    n=(int)s.size(), m=(int)t.size();
    for(i=1;i<=n;i++){
        hsh[i]=(hsh[i-1]*133LL+s[i-1]-'a'+1)%mod;
        pw[i]=pw[i-1]*133LL%mod;
    }
    memset(fs,-1,sizeof(fs));
    for(i=1;i<=m;i++){
        for(j=0;j<MM;j++)
            pos[j]=133LL*pos[j]%mod;
        int cur=t[i-1]-'a';
        if(fs[cur]==-1) fs[cur]=i-1;
        pos[cur]=(pos[cur]+1)%mod;
    }
    for(i=1;i<=n-m+1;i++){
        memset(p,-1,sizeof(p));
        int hh = 0;
        for(j=0;j<MM;j++){
            if(fs[j]!=-1){
                int ot=s[i+fs[j]-1]-'a';
                if(p[ot]!=-1&&p[ot]!=j) break;
                if(p[j]!=-1&&p[j]!=ot) break;
                p[ot]=j, p[j]=ot;
                hh=(hh+1LL*(ot+1)*pos[j])%mod;
            }
        }
        if(hh==get(i,i+m-1)) ans.pb(i);
    }
    printf("%d\n",(int)ans.size());
    for(auto v : ans)
        printf("%d ",v);
    printf("\n");
    return 0;
}