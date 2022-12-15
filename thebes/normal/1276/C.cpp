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

const int MN = 4e5+5;
int n, i, j, k, ans, kk, x, y, cnt[MN];
map<int,int> mp, rev; vi arr;
vector<vi> sna;

int main(){
    scanf("%d",&n);
    fox(i,1,n){
        arr.pb(0);
        scanf("%d",&arr.back());
        mp[arr[i-1]];
    }
    i=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        it->second = ++i;
        rev[i] = it->first;
    }
    for(i=0;i<n;i++) arr[i]=mp[arr[i]], cnt[arr[i]]++;
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    int s = ceil(sqrt(n+0.0));
    fox(k,1,s){
        int sm = 0;
        for(auto v : arr){
            sm += min(k,cnt[v]);
        }
        if(k*k<=sm){
            int rr = sm/k;
            if(ans<rr*k){
                ans = rr*k;
                kk = k;
            }
        }
    }
    int rr = ans/kk;
    printf("%d\n%d %d\n",rr*kk,kk,rr);
    fox(i,1,kk){
        sna.pb(vi());
        sna.back().resize(rr);
    }
    srand(time(0));
    sort(arr.begin(),arr.end(),[](int i,int j){return cnt[i]>cnt[j];});
    int ct = rr*kk;
    for(auto v : arr){
        int cc = min(kk,cnt[v]);
        int heh = rev[v];
        while(cc--&&ct){
            sna[x%kk][y%rr]=heh;
            x++, y++;
            if(x==kk){
                x = 0;
                y -= kk-1;
            }
            ct--;
        }
    }
    for(i=0;i<kk;i++){
        for(j=0;j<rr;j++){
            printf("%d ",sna[i][j]);
        }
        printf("\n");
    }
    return 0;
}