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

const int MN = 333, MM = 5e4+5;
int n, m, k, i, j, x, y, a[MN], r[MN], par[MN][MN], arr[MN]; ll sm;
vi adj[MN]; queue<int> q;
struct sna{int x,y,w;};
vector<sna> ans;

inline void process(int x,int y,int sh){
    int cur=y, nxt=0;
    while(cur!=0){
        arr[++nxt]=cur;
        cur=par[x][cur];
    }
    vector<sna> edd;
    for(int i=2,j;i<=nxt;i=j+1){
        for(j=i;j<=nxt&&a[arr[j]]<sh;j++){}
        vector<sna> tmp;
        for(int k=min(j,nxt);k>=i;k--){
            assert(a[arr[k]]>=sh);
            if(a[arr[k-1]]+sh>m){
                int hm=max(0,sh-a[arr[k-1]]);
                a[arr[k]]-=hm, a[arr[k-1]]+=hm;
                r[arr[k]]-=hm, r[arr[k-1]]+=hm;
                ans.pb({arr[k],arr[k-1],hm});
                tmp.pb({arr[k],arr[k-1],sh-hm});
            }
            else{
                ans.pb({arr[k],arr[k-1],sh});
                a[arr[k]]-=sh; a[arr[k-1]]+=sh;
                r[arr[k]]-=sh, r[arr[k-1]]+=sh;
            }
        }
        reverse(tmp.begin(),tmp.end());
        for(auto v : tmp)
            edd.pb(v);
    }
    for(auto v : edd){
        ans.pb(v);
        a[v.x]-=v.w,a[v.y]+=v.w;
        r[v.x]-=v.w,r[v.y]+=v.w;
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        r[i]=a[i]-x;
        sm+=r[i];
    }
    for(i=1;i<=k;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(i=1;i<=n;i++){
        memset(par[i],-1,sizeof(par[i]));
        q.push(i); par[i][i]=0;
        while(q.size()){
            x=q.front(); q.pop();
            for(auto v : adj[x]){
                if(par[i][v]==-1){
                    par[i][v]=x;
                    q.push(v);
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        if(r[i]<=0) continue;
        for(j=1;j<=n;j++){
            if(r[j]<0&&r[i]>0&&par[i][j]>=0){
                int sh=min(abs(r[j]),abs(r[i]));
                process(i,j,sh);
            }
        }
    }
    for(i=1;i<=n;i++){
        if(r[i]<=0) continue;
        for(j=1;j<=n;j++){
            if(r[j]<0&&r[i]>0&&par[i][j]>=0){
                int sh=min(abs(r[j]),abs(r[i]));
                process(i,j,sh);
            }
        }
    }
    for(i=1;i<=n;i++){
        if(r[i]) sm=1;
    }
    if(sm) printf("NO\n");
    else{
        printf("%d\n",ans.size());
        for(auto v : ans)
            printf("%d %d %d\n",v.x,v.y,v.w);
    }
    return 0;
}