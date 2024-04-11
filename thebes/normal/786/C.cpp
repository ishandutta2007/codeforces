#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
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
#define foxr(i,x,y) for(int i=(x);i>=(y);i--)

const int MN = 1e5+5;
int n, arr[MN], cnt[MN], r, i, j, lo, hi, lst, s; pii rg[500];

inline void add(int i){
    if(!cnt[arr[i]]) r++;
    cnt[arr[i]]++;
}

inline void ree(int l,int t){
    fox(i,l,t) cnt[arr[i]]--;
    r = 0;
}

inline int solve(int k){
    int l = 1, ret = 0;
    fox(i,1,n){
        add(i);
        if(r>k){
            ree(l,i); l=i;
            ret++;
            add(i);
        }
    }
    ree(l,n);
    return ret+1;
}

int main(){
    scanf("%d",&n);
    fox(i,1,n) scanf("%d",&arr[i]);
    s = ceil(sqrt((double)n));
    int heh;
    fox(j,1,s) heh=solve(j),printf("%d ",heh);
    lst = s+1;
    fox(i,1,s) rg[i]={s,n};
    foxr(j,s,1){
        lo=rg[j].first,hi=rg[j].second;
        while(lo+1<hi){
            int m = lo+hi>>1;
            int k = solve(m);
            fox(i,1,j){
                if(k>=i) rg[i].first=max(rg[i].first,m);
                else rg[i].second=min(rg[i].second,m-1);
            }
            lo=rg[j].first,hi=rg[j].second;
        }
        if(solve(rg[j].second)>=j) lo=hi;
        else hi=lo;
        while(lst<=lo){
            printf("%d ",j);
            lst++;
        }
    }
    printf("\n");
    return 0;
}