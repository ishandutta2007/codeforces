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

const int MN = 1e5+5, MM = 1.5e9, MK = 303;
int N, K, i, j, x, y, id, d, pos[MN], on[MN], p[2*MN], cnt[2*MN], len[2*MN]; ll ans[MN];
map<int,int> mp;
pii evt[2*MN];

int main(){
    scanf("%d%d",&N,&K);
    for(i=1;i<=N;i++){
        scanf("%d%d",&x,&pos[i]);
        mp[pos[i]]=mp[pos[i]+K]=0;
        evt[2*i-1]={x,i};
        evt[2*i]={x+K,i};
    }
    i=0;
    for(auto it=mp.begin();it!=mp.end();it++)
        it->second = ++i, p[i] = it->first;
    for(--i;i>=1;i--)
        len[i] = p[i+1]-p[i];
    sort(evt+1,evt+2*N+1,[](pii i,pii j){return i.F<j.F;});
    for(i=1;i<=2*N;i++){
        x = evt[i].F; id = evt[i].S;
        if(!on[id]) d = 1;
        else d = -1;
        j = mp[pos[id]];
        for(;p[j]<=pos[id]+K-1;j++){
            y = cnt[j];
            ans[y] -= 1LL*len[j]*(MM-x);
            ans[y+d] += 1LL*len[j]*(MM-x);
            cnt[j] = y+d;
        }
        on[id] = !on[id];
    }
    for(i=1;i<=N;i++)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}