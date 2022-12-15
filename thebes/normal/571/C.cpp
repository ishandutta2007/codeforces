#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void pr(short x){cout<<x;}
    void pr(unsigned x){cout<<x;}
    void pr(int x){cout<<x;}
    void pr(long long x){cout<<x;}
    void pr(unsigned long long x){cout<<x;}
    void pr(double x){cout<<x;}
    void pr(long double x){cout<<x;}
    void pr(char x){cout<<x;}
    void pr(const char*x){cout<<x;}
    void pr(const string&x){cout<<x;}
    void pr(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void pr(const pair<S,T>&x){pr(DEBUG?"(":""),pr(x.first),pr(DEBUG?", ":" "),pr(x.second),pr(DEBUG?")":"");}
    template<class T>
    void pr(const vector<T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class T>
    void pr(const set<T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class T>
    void pr(const multiset<T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class S,class T>
    void pr(const map<S,T>&x){pr(DEBUG?"{":"");bool _=0;for(const auto&v:x)pr(_?DEBUG?", ":" ":""),pr(v),_=1;pr(DEBUG?"}":"");}
    template<class S,class... T>
    void pr(const S&a,const T&...b){pr(a);if(sizeof...(b))pr(" "),pr(b...);else pr('\n');}
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
int N, M, i, j, k, x, y, ok[MN], vis[MN], ans[MN], deg[MN];
vector<pii> t[MN]; set<pii> arr[MN]; queue<int> q, n;

int main(){
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++){
        scanf("%d",&k);
        for(j=1;j<=k;j++){
            scanf("%d",&x);
            t[abs(x)].pb({x,i});
        }
    }
    for(i=1;i<=M;i++){
        if(t[i].empty()) continue;
        if(t[i].size()==1||t[i][0].first==t[i][1].first){
            ans[i]=t[i][0].first>0?1:0;
            for(auto v : t[i]) ok[v.second]=1;
        }
        else{
            arr[t[i][0].second].insert({t[i][1].second,t[i][0].first});
            arr[t[i][1].second].insert({t[i][0].second,t[i][1].first});
        }
    }
    for(i=1;i<=N;i++){
        deg[i]=arr[i].size();
        if(ok[i]||deg[i]==1) vis[i]=1,q.push(i);
        else n.push(i);
    }
    while(1){
        while(q.size()){
            x = q.front(); q.pop();
            if(!ok[x]){
                if(arr[x].empty()){
                    printf("NO\n");
                    return 0;
                }
                pii id = *arr[x].begin();
                arr[x].erase(arr[x].begin());
                int ot = id.first;
                arr[ot].erase({x,-id.second});
                deg[ot]--;
                if(deg[ot]<=1&&!vis[ot]) vis[ot]=1,q.push(ot);
                ans[abs(id.second)]=id.second>0?1:0;
            }
            for(auto v : arr[x]){
                ok[v.first]=1;
                ans[abs(v.second)]=v.second>0?0:1;
                arr[v.first].erase({x,-v.second});
                if(!vis[v.first]){
                    vis[v.first]=1;
                    q.push(v.first);
                }
            }
        }
        while(n.size()){
            x = n.front(); n.pop();
            if(!vis[x]){
                q.push(x);
                break;
            }
        }
        if(q.empty()&&n.empty()) break;
    }
    printf("YES\n");
    for(i=1;i<=M;i++)printf("%d",ans[i]);
    printf("\n");
    return 0;
}