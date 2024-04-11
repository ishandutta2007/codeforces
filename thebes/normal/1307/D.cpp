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

const int MN = 2e5+5;
int n, m, k, i, j, x, y, ok[MN], d[MN][2];
vi adj[MN]; queue<int> q;
vi a, b;

int main(){
    for(scanf("%d%d%d",&n,&m,&k),i=1;i<=k;i++){
        scanf("%d",&x);
        ok[x]=1;
    }
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    q.push(1);
    while(q.size()){
        x = q.front(); q.pop();
        for(auto v : adj[x]){
            if(!d[v][0]&&v!=1){
                d[v][0]=d[x][0]+1;
                q.push(v);
            }
        }
    }
    q.push(n);
    while(q.size()){
        x = q.front(); q.pop();
        for(auto v : adj[x]){
            if(!d[v][1]&&v!=n){
                d[v][1]=d[x][1]+1;
                q.push(v);
            }
        }
    }
    int ans = d[1][1];
    int tt = 0;
    for(i=1;i<=n;i++) if(ok[i]) a.pb(i),b.pb(i);
    sort(a.begin(),a.end(),[](int i,int j){return d[i][0]<d[j][0];});
    multiset<int> s;
    for(i=1;i<=n;i++) if(ok[i]) s.insert(d[i][1]);
    for(auto v : a){
        int t = d[v][1];
        s.erase(s.find(t));
        if(s.size()){
            auto it = s.end();
            it--;
            tt = max(tt,d[v][0]+1+*it);
        }
    }
    printf("%d\n",min(tt,ans));
    return 0;
}