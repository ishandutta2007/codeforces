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

mt19937 mt(time(0));
int rng(int l,int r){return (mt()%(r-l+1))+l;}
int T, N, K, i, j;

vi acc(int l,int r){
    vi ret;
    for(int i=l;i<=r;i++)
        ret.pb(i);
    return ret;
}

inline int query(vi a,vi b){
    printf("? %d %d\n",(int)a.size(),(int)b.size());
    for(auto v : a) printf("%d ",v);
    printf("\n");
    for(auto v : b) printf("%d ",v);
    printf("\n");
    fflush(stdout);
    string s; cin >> s;
    if(s=="WASTED") exit(0);
    if(s=="FIRST") return 1;
    else if(s=="SECOND") return 2;
    else return 0;
}

void solve(int l,int r){
    if(l==r){
        printf("! %d\n",l);
        fflush(stdout);
        return;
    }
    int mid = (l+r)>>1;
    if(query(acc(1,mid-l+1),acc(l,mid))==1) solve(l,mid);
    else solve(mid+1,r);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&K);
        int dn = 0;
        for(i=0;i<25;i++){
            int x = rng(2,N);
            if(query(acc(1,1),acc(x,x))==2){
                printf("! 1\n");
                fflush(stdout);
                dn=1; break;
            }
        }
        if(dn) continue;
        for(i=1;(1<<i)<=N;i++){
            int r = query(acc(1,1<<(i-1)),acc((1<<(i-1))+1,1<<i));
            if(r==1){
                solve((1<<(i-1))+1,1<<i);
                dn=1; break;
            }
        }
        if(!dn) solve((1<<(i-1))+1,N);
    }
    return 0;
}