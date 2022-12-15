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

const int MN = 1005;
double a[MN][MN], b[MN][MN];
int n, m, i, j, x, y, arr[MN];

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(arr[i]>arr[j]) a[i][j]=1;
        }
    }
    for(;m;m--){
        scanf("%d%d",&x,&y);
        for(i=1;i<=n;i++){
            j=i;
            if(i==x) j=y;
            else if(i==y) j=x;
            b[x][j]=a[y][i];
            b[y][j]=a[x][i];
        }
        for(i=1;i<=n;i++){
            if(i==x||i==y) continue;
            b[i][x]=a[i][y];
            b[i][y]=a[i][x];
        }
        for(i=1;i<=n;i++){
            j=i;
            if(i==x) j=y;
            else if(i==y) j=x;
            a[x][i]=0.5*(b[x][i]+a[x][i]);
            a[y][i]=0.5*(b[y][i]+a[y][i]);
        }
        for(i=1;i<=n;i++){
            if(i==x||i==y) continue;
            a[i][y]=0.5*(a[i][y]+b[i][y]);
            a[i][x]=0.5*(a[i][x]+b[i][x]);
        }
    }
    double ans = 0;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            ans += a[i][j];
        }
    }
    printf("%.7lf\n",ans);
    return 0;
}