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

const int MN = 2e5+5, MM = 6, MS = 450;
int n, m, q, i, l, r, arr[MN], len[MS][MM], inv[MS][MM], flp[MS]; ll x;

void rebuild(int b){
    int l=max(1,b*MS), r=min(n,(b+1)*MS-1), i;
    if(flp[b]){
        flp[b]=0;
        for(i=l;i<=r;i++)
            arr[i]^=1;
    }
    for(int val=0;val<=1;val++){
        for(int off=0;off<=m;off++){
            for(i=r-off;i>=l;){
                if(arr[i]==val) i-=m+1;
                else i--;
            }
            if(val==0) inv[b][off]=l-1-i;
            else len[b][off]=l-1-i;
        }
    }
}

void upd(int l,int r){
    int b=l/MS;
    while(l<=r){
        if(l%MS==0&&min(n,l+MS-1)<=r){
            flp[l/MS]^=1;
            l+=MS;
        }
        else arr[l++]^=1;
    }
    rebuild(b);
    if(r/MS!=b) rebuild(r/MS);
}

int qu(int l,int r){
    int b, s, e;
    while(r>=l){
        b = r/MS, s = max(b*MS,1), e = min(n,(b+1)*MS-1);
        if(e-r<=m&&s>=l){
            r=s-1-(flp[b]?inv[b][e-r]:len[b][e-r]);
        }
        else if(arr[r]^flp[r/MS]) r-=m+1;
        else r--;
    }
    if(l-r==m+1) return 2;
    else return 1;
}

int main(){
    for(scanf("%d%d%d",&n,&m,&q),i=1;i<=n;i++){
        scanf("%lld",&x);
        arr[i]=(x&1);
    }
    for(i=0;i<=n/MS;i++) rebuild(i);
    for(;q;q--){
        scanf("%d",&i);
        if(i==1){
            scanf("%d%d%lld",&l,&r,&x); x&=1;
            if(x) upd(l,r);
        }
        else{
            scanf("%d%d",&l,&r);
            printf("%d\n",qu(l,r));
        }
    }
    return 0;
}