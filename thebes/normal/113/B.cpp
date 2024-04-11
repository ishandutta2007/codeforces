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

const ll MN = 2002;
ll n, i, j, x, hsh[MN]={0}, pw[MN]={1}, A, B, aa[MN], bb[MN];
vector<ll> heh; string s, a, b;
ll get(ll x,ll y){
    return hsh[y]-1LL*(hsh[x-1]*pw[y-x+1]);
}
int main(){
    cin >> s; n = s.size();
    s.insert(s.begin(),'0');
    for(i=1;i<=n;i++){
        pw[i]=(1LL*pw[i-1]*131);
        hsh[i]=(1LL*hsh[i-1]*131+s[i]-'a'+1);
    }
    cin >> a >> b;
    int t = max(a.size(),b.size());
    for(auto c : a) A=(1LL*A*131+c-'a'+1);
    for(auto c : b) B=(1LL*B*131+c-'a'+1);
    for(i=1;i<=n-t+1;i++){
        if(get(i,i+a.size()-1)==A) aa[i]=1;
    }
    for(j=t;j<=n;j++){
        if(get(j-b.size()+1,j)==B) bb[j]=1;
    }
    for(i=1;i<=n;i++){
        for(j=i+t-1;j<=n;j++){
            if(aa[i]&&bb[j]) heh.pb(get(i,j));
        }
    }
    sort(heh.begin(),heh.end());
    heh.erase(unique(heh.begin(),heh.end()),heh.end());
    printf("%d\n",heh.size());
    return 0;
}