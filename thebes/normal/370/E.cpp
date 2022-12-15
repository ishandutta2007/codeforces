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

const int MN = 2e5+5;
set<int> a[MN];
int n, m, i, j, arr[MN], mn[MN], mx[MN], l[MN], r[MN];
vi ans;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        m = max(m, arr[i]);
        a[arr[i]].insert(i);
    }
    for(i=1;i<=m;i++){
        if(a[i].empty()) continue;
        auto it = a[i].begin();
        auto it2 = a[i].end(); it2--;
        l[i] = *it; r[i] = *it2;
    }
    for(i=1;i<=max(n,m);i++){
        if(!l[i]&&!r[i]){
            mn[i]=mn[i-1]+2;
            mx[i]=mx[i-1]+5;
            continue;
        }
        mn[i]=(1<<30);
        mx[i]=0;
        for(j=r[i];j<=r[i]+6;j++){
            for(int k=2;k<=5;k++){
                if(j-k+1<=l[i]&&j-k>=mn[i-1]&&j-k<=mx[i-1]){
                    mn[i]=min(mn[i],j);
                    mx[i]=max(mx[i],j);
                }
            }
        }
    }
    for(i=n;i>=1;i--){
        if(mn[i]<=n&&mx[i]>=n){
            int p = n, k = i;
            for(;i>=1;i--){
                bool f = 0;
                for(j=2;j<=5;j++){
                    if(p-j>=mn[i-1]&&p-j<=mx[i-1]&&(!l[i]||p-j+1<=l[i])){
                        for(int y=0;y<j;y++) ans.pb(i);
                        p -= j; f = 1;
                        break;
                    }
                }
                if(!f){
                    printf("-1\n");
                    return 0;
                }
            }
            reverse(ans.begin(),ans.end());
            for(i=0;i<ans.size();i++){
                if(arr[i+1]&&arr[i+1]!=ans[i]){
                    printf("-1\n");
                    return 0;
                }
            }
            if(ans.size()!=n){
                printf("-1\n");
                return 0;
            }
            printf("%d\n",k);
            for(auto v : ans) printf("%d ",v);
            printf("\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}