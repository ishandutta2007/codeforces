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

const int MN = 1e5+5, MM = 1e6+5;
set<int> pos, use;
int n, i, arr[MN], a, b, jmp[MM];
queue<int> q;

int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    scanf("%d%d",&a,&b);
    for(i=1;i<=n;i++){
        if(use.count(arr[i])) continue;
        use.insert(arr[i]);
        int c = ceil(b/(double)arr[i])*arr[i];
        while(c<=a){
            jmp[c-b]=max(jmp[c-b],arr[i]);
            c += arr[i];
        }
    }
    for(i=1;b+i<=a;i++)
        pos.insert(i);
    q.push(0);
    int dis = 0, dn = 0;
    while(q.size()&&!dn){
        int sz = q.size();
        while(sz--){
            int x=q.front(); q.pop();
            if(x==a-b){
                dn = 1;
                break;
            }
            if(pos.count(x+1)){
                pos.erase(x+1);
                q.push(x+1);
            }
            if(jmp[x]){
                int y = x+jmp[x]-1;
                auto it=pos.lower_bound(x);
                while(it!=pos.end()&&*it<=y){
                    q.push(*it);
                    auto it2=it; it++;
                    pos.erase(it2);
                }
            }
        }
        dis++;
    }
    printf("%d\n",dis-1);
    return 0;
}