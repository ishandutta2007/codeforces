#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
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
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

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

const int MN = 3e5+5, MM = 101;
int a[MN][3], i, j, n, t, x, y, z, pat[MN][3], cnt; ll arr[MN], base, len, nim;

void ini(){
    for(int i=1;i<MM;i++){
        for(int j=0;j<3;j++){
            set<int> st;
            st.insert(a[max(i-x,0)][0]);
            if(j!=1) st.insert(a[max(i-y,0)][1]);
            if(j!=2) st.insert(a[max(i-z,0)][2]);
            for(int k=0;;k++){
                if(!st.count(k)){
                    a[i][j] = k;
                    break;
                }
            }
        }
    }
    base = 65;
    for(int i=base-1;i>=0;i--){
        int ok = 1;
        for(int j=0;j<=30;j++){
            for(int k=0;k<3;k++){
                if(a[i-j][k]!=a[base-j][k]){
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok){
            len = base-i;
            break;
        }
    }
}

inline ll grundy(ll n,ll l){
    if(n<=base) return a[n][l];
    else{
        n = (n-base)%len;
        return a[base+n][l];
    }
}

int main(){
    for(scanf("%d",&t);t;t--){
        scanf("%d%d%d%d",&n,&x,&y,&z);
        ini(); nim = 0; cnt = 0;
        for(i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
            nim ^= grundy(arr[i], 0);
        }
        for(i=1;i<=n;i++){
            nim ^= grundy(arr[i], 0);
            nim ^= grundy(max(0LL,arr[i]-x),0);
            if(!nim) cnt ++;
            nim ^= grundy(max(0LL,arr[i]-x),0);
            nim ^= grundy(max(0LL,arr[i]-y),1);
            if(!nim) cnt ++;
            nim ^= grundy(max(0LL,arr[i]-y),1);
            nim ^= grundy(max(0LL,arr[i]-z),2);
            if(!nim) cnt ++;
            nim ^= grundy(max(0LL,arr[i]-z),2);
            nim ^= grundy(arr[i], 0);
        }
        printf("%d\n",cnt);
    }
    return 0;
}