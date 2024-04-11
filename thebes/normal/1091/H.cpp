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

const int MN = 2e5+5, MB = 200;
int n, f, i, j, x, y, w, fac[MN], sp[MN], nim[MN];
bitset<MN> msk, g[MB]; vi vec;

int main(){
    scanf("%d%d",&n,&f);
    for(i=2;i<MN;i++){
        if(!sp[i]) fac[i]=1;
        else fac[i]=1+fac[i/sp[i]];
        if(fac[i]<=2) vec.pb(i);
        if(fac[i]>1) continue;
        for(j=i;j<MN;j+=i){
            if(!sp[j]) sp[j]=i;
        }
    }
    for(i=0;i<vec.size();i++){
        if(vec[i]!=f)
            msk[vec[i]]=1;
    }
    int mx=0;
    for(i=0;i<MN;i++){
        for(j=0;j<MB;j++){
            if(!g[j][i]){
                nim[i]=j;
                break;
            }
        }
        g[nim[i]]|=(msk<<i);
    }
    int grundy = 0;
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&w);
        grundy ^= nim[y-x-1]^nim[w-y-1];
    }
    string ans[]={"Alice","Bob"};
    grundy = grundy>0;
    printf("%s\n%s\n",ans[!grundy].c_str(),ans[grundy].c_str());
    return 0;
}