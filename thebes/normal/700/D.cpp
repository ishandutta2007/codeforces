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

const int MN = 1e5+5, MS = 1300, MS2 = 330;
int n, q, i, j, k, l=1, r, arr[MN], cnt[MS], freq[MN], go[MS], ok[MN], big[MN], nxt; ll ans[MN];
struct qur{int l, r, id;}qu[MN];
priority_queue<int,vi,greater<int>> Q;

inline void inc(int n){
    if(ok[arr[n]]) freq[arr[n]]++;
    else{
        cnt[freq[arr[n]]]--;
        cnt[++freq[arr[n]]]++;
    }
}

inline void dec(int n){
    if(ok[arr[n]]) freq[arr[n]]--;
    else{
        cnt[freq[arr[n]]]--;
        cnt[--freq[arr[n]]]++;
    }
}

inline void ins(int x,int y){
    if(x>=MS){while(y--)Q.push(x);}
    else go[x]+=y;
}

inline ll solve(){
    ll res=0, w=0, r;
    for(j=1;j<MS;j++)
        go[j]=cnt[j];
    for(j=1;j<=nxt;j++){
        if(freq[big[j]]>=MS) Q.push(freq[big[j]]);
        else go[freq[big[j]]]++;
    }
    for(j=1;j<MS;j++){
        if(go[j]&&w){
            go[j]--;
            res+=j+w;
            ins(j+w,1);
            w=0;
        }
        r=go[j]/2;
        if(r){
            res+=2*j*r;
            ins(2*j,r);
            go[j]-=2*r;
        }
        if(go[j]) w=j;
    }
    if(w) Q.push(w);
    while(Q.size()>1){
        w=Q.top(); Q.pop();
        r=Q.top(); Q.pop();
        res+=r+w;
        Q.push(r+w);
    }
    if(Q.size()) Q.pop();
    return res;
}

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        freq[arr[i]]++;
        if(freq[arr[i]]==MS){
            big[++nxt]=arr[i];
            ok[arr[i]]=1;
        }
    }
    memset(freq,0,sizeof(freq));
    cnt[0]=100000;
    for(scanf("%d",&q),i=1;i<=q;i++){
        scanf("%d%d",&qu[i].l,&qu[i].r);
        qu[i].id=i;
    }
    sort(qu+1,qu+q+1,[](qur i,qur j){return i.l/MS2==j.l/MS2?i.r<j.r:i.l<j.l;});
    for(i=1;i<=q;i++){
        while(r<qu[i].r) inc(++r);
        while(r>qu[i].r) dec(r--);
        while(l<qu[i].l) dec(l++);
        while(l>qu[i].l) inc(--l);
        ans[qu[i].id]=solve();
    }
    for(i=1;i<=q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}