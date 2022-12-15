#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
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
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)
#define F first
#define S second

const int MN = 2e6+5, mod = 51123987;
int n, i, j, x, y, ans, a[MN], b[MN];
string s; vi res;

vi manacher(string s){
    int N = s.size();
    char *t = (char*)malloc((2*N+1)*sizeof(char));
    for(int i=0;i<2*N+1;i++)
        t[i] = '#';
    for(int i=0;i<N;i++)
        t[2*i+1] = s[i];
    vi P; P.resize(2*N+1);
    int C=0, R=-1, rad;
    for(int i=0;i<2*N+1;i++){
        if(i<=R) rad = min(P[2*C-i], R-i);
        else rad = 0;
        while(i+rad<2*N+1&&i-rad>=0&&t[i+rad]==t[i-rad])
            rad++;
        P[i]=rad-1;
        if(i+rad-1>R){
            C = i;
            R = i+rad-1;
        }
    }
    return P;
}

int main(){
    cin >> n >> s;
    res = manacher(s);
    for(i=0;i<2*n+1;i++){
        if(!res[i]) continue;
        int c=i/2, r=(i/2)+((res[i]-1)/2);
        int l=((i-1)/2)-((res[i]-1)/2), d=((i-1)/2);
        a[l]++; a[d+1]--;
        b[c]++; b[r+1]--;
        if(c-1>=0){
            b[max(0,l-1)]--;
            if(b[max(0,l-1)]<0) b[max(0,l-1)]+=mod;
            b[d]++;
            if(b[d]>=mod) b[d]-=mod;
        }
    }
    for(i=0;i<n;i++){
        a[i+1]+=a[i];
        if(a[i+1]>=mod) a[i+1]-=mod;
        b[i+1]+=b[i];
        if(b[i+1]>=mod) b[i+1]-=mod;
    }
    for(i=n-1;i>=0;i--){
        b[i]+=b[i+1];
        if(b[i]>=mod) b[i]-=mod;
        ans=(ans+1LL*a[i]*(b[i]+mod-1))%mod;
    }
    for(i=0;i<n;i++){
        ans=(ans-1LL*a[i]*(a[i]-1)/2)%mod;
        if(ans<0) ans+=mod;
    }
    printf("%d\n",ans);
    return 0;
}