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

const int MN = 105, MM = 30, MS = 5e4+5;
int n, i, j, arr[MN], p[MS], st[2*MS][MM], nxt;
map<int,int> idx;
unordered_map<int,int> nim;

int solve(int msk){
    if(!msk) return 0;
    else if(nim.count(msk)) return nim[msk];
    set<int> mex;
    int cur=0, res=0;
    for(int i=1;(1<<i)<=msk;i++){
        res=(cur|(msk>>i));
        if(res&1) res^=1;
        mex.insert(solve(res));
        cur|=(msk&(1<<i));
    }
    for(int i=0;;i++){
        if(!mex.count(i)){
            nim[msk]=i;
            return i;
        }
    }
}

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    int g=0;
    for(i=1;i<=n;i++){
        int r=arr[i];
        for(j=2;j*j<=arr[i];j++){
            if(r%j==0){
                int cnt=0;
                while(r%j==0)
                    cnt++,r/=j;
                if(!idx.count(j)) idx[j]=++nxt;
                st[idx[j]][cnt]=1;
            }
        }
        if(r!=1){
            if(!idx.count(r)) idx[r]=++nxt;
            st[idx[r]][1]=1;
        }
    }
    for(i=1;i<=nxt;i++){
        int go=0;
        for(j=1;j<MM;j++){
            if(st[i][j]){
                go|=(1<<j);
            }
        }
        g^=solve(go);
    }
    printf("%s\n",g?"Mojtaba":"Arpa");
    return 0;
}