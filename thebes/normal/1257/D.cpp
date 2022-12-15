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

const int MN = 2e5+5;
int t, n, m, i, x, y, a[MN], b[MN], mx[3*MN], st[3*MN], lo, hi, ans, f;
void bld1(int i,int s,int e){
    if(s!=e){
        bld1(2*i,s,(s+e)/2); bld1(2*i+1,(s+e)/2+1,e);
        mx[i]=max(mx[2*i],mx[2*i+1]);
    }
    else mx[i]=a[s];
}
void bld2(int i,int s,int e){
    if(s!=e){
        bld2(2*i,s,(s+e)/2); bld2(2*i+1,(s+e)/2+1,e);
        st[i]=max(st[2*i],st[2*i+1]);
    }
    else st[i]=b[s];
}
int qu1(int i,int s,int e,int ss,int se){
    if(s>=ss&&e<=se) return mx[i];
    else if((s+e)/2<ss) return qu1(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu1(2*i,s,(s+e)/2,ss,se);
    else return max(qu1(2*i,s,(s+e)/2,ss,se),qu1(2*i+1,(s+e)/2+1,e,ss,se));
}
int qu2(int i,int s,int e,int ss,int se){
    if(ss>se) return 0;
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu2(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu2(2*i,s,(s+e)/2,ss,se);
    else return max(qu2(2*i,s,(s+e)/2,ss,se),qu2(2*i+1,(s+e)/2+1,e,ss,se));
}
int main(){
    for(scanf("%d",&t);t;t--){
        for(scanf("%d",&n),i=1;i<=n;i++)
            scanf("%d",&a[i]),b[i]=0;
        bld1(1,1,n);
        for(scanf("%d",&m),i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            b[y]=max(b[y],x);
        }
        bld2(1,1,n);
        int p = 1; ans = 0;
        while(p<=n){
            lo=0, hi=n-p+1;
            while(lo<hi){
                int m = (lo+hi)/2;
                int req = qu1(1,1,n,p,p+m);
                if(qu2(1,1,n,m+1,n)>=req) lo=m+1;
                else hi=m;
            }
            if(lo==0){
                ans = -1;
                break;
            }
            p += lo;
            ans++;
        }
        printf("%d\n",ans);
    }
}