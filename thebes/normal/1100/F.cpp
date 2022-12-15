#include <bits/stdc++.h>
using namespace std;

namespace debug{
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
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const set<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T,class T2>
    void __(const map<T,T2>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(make_pair(v.first,v.second)),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}
}

using namespace debug;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 5e5+5;
int N, Q, i, x, y, arr[MN], ans[MN];
struct qur{int l, r, id;}; vector<qur> q;
class basis{
    int a[20];
    public:
    basis(){memset(a,0,sizeof(a));}
    int fnd(){
        int ret = 0;
        foxr(i,0,19) ret=max(ret,ret^a[i]);
        return ret;
    }
    void add(int x){
        foxr(i,0,19){
            if((1<<i)&x){
                if(a[i]) x^=a[i];
                else{
                    a[i]=x;
                    return;
                }
            }
        }
    }
    vi elem(){
        vi ret;
        fox(i,0,19) if(a[i]) ret.pb(a[i]);
        return ret;
    }
    void clr(){memset(a,0,sizeof(a));}
};

void solve(int l,int r,vector<qur> vec){
    if(vec.empty()) return;
    int m = (l+r)/2;
    vector<qur> L, R, M;
    for(auto v : vec){
        if(v.r<m) L.pb(v);
        else if(v.l>m) R.pb(v);
        else M.pb(v);
    }
    solve(l,m,L);
    solve(m+1,r,R);
    basis x;
    vector<basis> a, b;
    foxr(i,l,m){
        x.add(arr[i]);
        a.pb(x);
    }
    x.clr();
    fox(i,m,r){
        x.add(arr[i]);
        b.pb(x);
    }
    for(auto v : M){
        int nl = m-v.l, nr = v.r-m;
        vi el = a[nl].elem(), er = b[nr].elem();
        basis y;
        for(auto w : el)
            y.add(w);
        for(auto w : er)
            y.add(w);
        ans[v.id] = y.fnd();
    }
}

int main(){
    scanf("%d",&N);
    fox(i,1,N) scanf("%d",&arr[i]);
    scanf("%d",&Q);
    fox(i,1,Q){
        scanf("%d%d",&x,&y);
        q.pb({x,y,i});
    }
    solve(1,N,q);
    fox(i,1,Q) printf("%d\n",ans[i]);
    return 0;
}