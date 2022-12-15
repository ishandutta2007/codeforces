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

const int MN = (1<<11)+1;
mt19937 mt(time(0));
int N, i, x, y, idx, val, p[MN];

inline int query(int x,int y,bool f=false){
    if(!f) x=p[x], y=p[y];
    printf("? %d %d\n",x+1,y+1);
    fflush(stdout);
    int r; scanf("%d",&r);
    if(r==-1) exit(0);
    return r;
}

inline int qu(int x){
    int hm = min(N-1, 13);
    int res = (1<<11)-1;
    for(int i=1;i<=hm;i++)
        res &= query(x, (x+i)%N);
    return res;
}

int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++)
        p[i]=i;
    shuffle(p,p+N,mt);
    idx = 0;
    val = qu(idx);
    for(i=1;i<N;i++){
        if(query(idx,i)==val){
            idx = i;
            val = qu(idx);
        }
    }
    idx = p[idx];
    vi ans;
    for(i=0;i<N;i++){
        if(i==idx) ans.pb(0);
        else ans.pb(query(i,idx,1));
    }
    printf("! ");
    for(auto v: ans)
        printf("%d ",v);
    printf("\n");
    fflush(stdout);
    return 0;
}