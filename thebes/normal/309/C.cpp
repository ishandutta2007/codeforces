#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
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

const int MN = 1e6+6;
int N, M, i, j, x, a[MN], b[MN], sm[MN][32], cnt[32], lo, hi;
vi c;

int main(){
    scanf("%d%d",&N,&M);
    fox(i,1,N) scanf("%d",&a[i]);
    fox(i,1,M) scanf("%d",&b[i]);
    sort(b+1,b+M+1,[](int i,int j){return i<j;});
    fox(i,1,M){
        x = b[i];
        fox(j,0,30) sm[i][j]=sm[i-1][j];
        sm[i][x]++;
    }
    lo=1, hi=M+1;
    while(lo<hi){
        int m = (lo+hi)/2;
        fox(j,0,30) cnt[j]=sm[m][j];
        c.clear();
        fox(i,1,N) c.pb(a[i]);
        int f = 0, k;
        foxr(j,0,30){
            for(auto &v : c){
                k = (v>>j);
                v -= (min(cnt[j],k)<<j);
                cnt[j]-=min(cnt[j],k);
                if(!cnt[j]) break;
            }
            if(cnt[j]){
                f = 1;
                break;
            }
        }
        if(!f) lo=m+1;
        else hi=m;
    }
    printf("%d\n",lo-1);
    return 0;
}