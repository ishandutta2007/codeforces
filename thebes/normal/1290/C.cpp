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
    template<class T>
    void __(const multiset<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
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

const int MN = 3e5+5;
int N, M, K, i, j, x, y, h[MN], ds[MN], c[MN], sz[MN], a[MN], f[MN], ans;
string s; vi id[MN];

int cc(int x){return x==ds[x]?c[x]:c[x]^cc(ds[x]);}
int fnd(int x){return ds[x]==x?x:fnd(ds[x]);}

int main(){
    scanf("%d%d",&N,&K); cin >> s;
    for(i=1;i<=K;i++){
        scanf("%d",&M);
        for(j=1;j<=M;j++){
            scanf("%d",&x);
            id[x-1].pb(i);
        }
        ds[i]=i; sz[i]=1;
    }
    for(i=0;i<N;i++){
        int col = s[i]-'0';
        for(auto v : id[i]) col ^= cc(v);
        if(id[i].size()==2){
            x = fnd(id[i][0]), y = fnd(id[i][1]);
            if(x!=y){
                if(col){
                    if(sz[x]+sz[y]-a[x]-a[y]<a[x]+a[y]&&!f[x]&&!f[y]){
                        ans -= a[x]+a[y];
                        a[x] = sz[x]-a[x];
                        a[y] = sz[y]-a[y];
                        ans += a[x]+a[y];
                        c[x] ^= 1; c[y] ^= 1;
                    }
                    if(h[x]<h[y]) swap(x,y);
                    if(h[x]==h[y]) h[x]++;
                    c[y] ^= c[x];
                    sz[x] += sz[y];
                    a[x] += a[y];
                    f[x] |= f[y];
                    ds[y] = x;
                }
                else{
                    if(!f[x]&&!f[y]){
                        if(sz[x]-a[x]+a[y]<sz[y]-a[y]+a[x]){
                            ans -= a[x];
                            a[x] = sz[x]-a[x];
                            ans += a[x];
                            c[x] ^= 1;
                        }
                        else{
                            ans -= a[y];
                            a[y] = sz[y]-a[y];
                            ans += a[y];
                            c[y] ^= 1;
                        }
                    }
                    else if(!f[x]){
                        ans -= a[x];
                        a[x] = sz[x]-a[x];
                        ans += a[x];
                        c[x] ^= 1;
                    }
                    else{
                        ans -= a[y];
                        a[y] = sz[y]-a[y];
                        ans += a[y];
                        c[y] ^= 1;
                    }
                    if(h[x]<h[y]) swap(x,y);
                    if(h[x]==h[y]) h[x]++;
                    c[y] ^= c[x];
                    sz[x] += sz[y];
                    a[x] += a[y];
                    f[x] |= f[y];
                    ds[y] = x;
                }
            }
        }
        else if(id[i].size()==1){
            x = fnd(id[i][0]);
            if(!col){
                ans -= a[x];
                a[x] = sz[x]-a[x];
                ans += a[x];
                c[x] ^= 1;
            }
            f[x] = 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}