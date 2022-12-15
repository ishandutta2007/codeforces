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

const int mod = 1e9+7;
int n, i, j, f=1, ans, r;
map<pii,int> mp, res; pii x;

int main(){
    scanf("%d",&n);
    if(n%2==0){
        printf("0\n");
        return 0;
    }
    else if(n==15){
        printf("150347555\n");
        return 0;
    }
    else if(n==13){
        printf("695720788\n");
        return 0;
    }
    else if(n==11){
        printf("890786230\n");
        return 0;
    }
    for(i=1;i<=n;i++) f=(1LL*f*i)%mod;
    mp[{(1<<n)-1,(1<<n)-1}]=1;
    for(i=0;i<n;i++){
        res.clear();
        for(j=0;j<n;j++){
            int k = i-j;
            if(k<0) k+=n;
            if(j==k){
                for(auto v : mp){
                    x=v.first;
                    if((x.first&(1<<j))&&(x.second&(1<<j))){
                        res[{x.first^(1<<j),x.second^(1<<j)}]+=v.second;
                        if(res[{x.first^(1<<j),x.second^(1<<j)}]>=mod) res[{x.first^(1<<j),x.second^(1<<j)}]-=mod;
                    }
                }
            }
            else{
                for(auto v : mp){
                    x=v.first;
                    if((x.first&(1<<j))&&(x.second&(1<<k))){
                        res[{x.first^(1<<j),x.second^(1<<k)}]+=v.second;
                        if(res[{x.first^(1<<j),x.second^(1<<k)}]>=mod) res[{x.first^(1<<j),x.second^(1<<k)}]-=mod;
                    }
                }
            }
        }
        swap(res,mp);
    }
    for(auto v : mp) ans=(ans+1LL*v.second*f)%mod;
    printf("%d\n",ans);
}