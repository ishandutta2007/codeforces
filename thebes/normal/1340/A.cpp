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

const int MN = 1e5+5;
int t, n, i, arr[MN], pos[MN], ds[MN], len[MN], fl, dn[MN];
int fnd(int x){return ds[x]=x==ds[x]?x:fnd(ds[x]);}
multiset<int> cnt;

int main(){
    for(scanf("%d",&t);t;t--){
        for(scanf("%d",&n),i=1;i<=n;i++)
            scanf("%d",&arr[i]),pos[arr[i]]=i;
        cnt.clear();
        for(i=1;i<=n;i++)
            ds[i]=i,len[i]=1,cnt.insert(1),dn[i]=0;
        ds[n+1]=n+1;
        fl=0;
        for(i=1;i<=n;i++){
            int x = pos[i];
            auto it=cnt.end(); it--;
            if(len[x]!=*it){
                fl=1; break;
            }
            cnt.erase(it);
            int rt=fnd(x+1);
            if(rt<=n){
                cnt.erase(cnt.find(len[rt]));
                len[rt]+=len[x];
                cnt.insert(len[rt]);
            }
            ds[fnd(x)]=rt;
        }
        if(fl) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}