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

const int MN = 1e6+6, LG = 21;
int N, R, C, i, j, sp[MN][LG], len[MN], lo, hi, ans, sna;
string a[MN];

int main(){
    scanf("%d%d%d",&N,&R,&C);
    fox(i,1,N){
        cin >> a[i];
        len[i]=len[i-1]+a[i].size();
    }
    foxr(i,1,N){
        lo = i, hi = N+1;
        while(lo<hi){
            int m = (lo+hi)/2;
            if(len[m]-len[i-1]+m-i<=C) lo=m+1;
            else hi=m;
        }
        if(lo>i){
            sp[i][0]=lo-i;
            fox(j,1,LG-1) sp[i][j]=sp[i][j-1]+sp[i+sp[i][j-1]][j-1];
        }
        int r = R, p = i;
        foxr(j,0,LG-1){
            if((1<<j)<=r){
                r -= (1<<j);
                p += sp[p][j];
            }
        }
        if(p-i>ans){
            ans = p-i;
            sna = i;
        }
    }
    if(ans){
        int ln = a[sna].size();
        printf("%s",a[sna].c_str());
        fox(i,sna+1,sna+ans-1){
            if(ln+1+a[i].size()>C){
                printf("\n%s",a[i].c_str());
                ln = a[i].size();
            }
            else{
                printf(" %s",a[i].c_str());
                ln += a[i].size()+1;
            }
        }
        printf("\n");
    }
    return 0;
}