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

const int MN = 2e5+5;
int Q, i, x, y, val, last;
map<int,int> ds, rnk, xr;
int fnd(int x){return ds[x]==x?x:fnd(ds[x]);}
int pathxr(int x){
    if(ds[x]==x) return 0;
    else return xr[x]^pathxr(ds[x]);
}

int main(){
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d%d",&i,&x,&y);
        x ^= last, y ^= last;
        if(x>y) swap(x,y);
        x--;
        if(!ds.count(x)){
            ds[x]=x;
            rnk[x]=1;
        }
        if(!ds.count(y)){
            ds[y]=y;
            rnk[y]=1;
        }
        if(i==1){
            scanf("%d",&val);
            val ^= last;
            if(fnd(x)!=fnd(y)){
                val ^= pathxr(x)^pathxr(y);
                x=fnd(x), y=fnd(y);
                if(rnk[x]<rnk[y]) swap(x,y);
                ds[y] = x;
                if(rnk[x]==rnk[y]) rnk[x]++;
                xr[y] = val;
            }
        }
        else{
            if(fnd(x)==fnd(y)){
                last=pathxr(x)^pathxr(y);
                printf("%d\n",last);
            }
            else{
                printf("-1\n");
                last=1;
            }
        }
    }
}