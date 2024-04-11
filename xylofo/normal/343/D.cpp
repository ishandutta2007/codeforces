#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

struct sg{
    vi v,lazy;
    int n;
    void init(int m){
        n=1;
        while(n<=m)n*=2;
        v.assign(2*n,1);
        lazy.assign(2*n,0);
    }
    void maintain(int t){
        v[t]=v[t*2]|v[t*2+1];
    }
    void push(int t){
        if(lazy[t] && t<n){
            lazy[t]=0;
            v[2*t]=v[2*t+1]=v[t];
            lazy[2*t]=lazy[2*t+1]=1;
        }
    }
    void update(int x, int y, int val){upd(1,0,n,x,y,val);}
    void upd(int t,int xx,int yy,int x,int y,int val){
        //cout<<t<<" "<<xx<<" "<<yy<<" "<<x<<" "<<y<<" "<<n<<endl;
        if(x<=xx && yy<=y){lazy[t]=1,v[t]=val;return;}
        if(xx>=y || x>=yy)return;
        push(t);
        int m=(xx+yy)/2;
        upd(t*2,  xx,m,x,y,val);
        upd(t*2+1,m,yy,x,y,val);
        maintain(t);
    }
    int query(int x, int y){return que(1,0,n,x,y);}
    int que(int t,int xx,int yy,int x,int y){
        if(x<=xx && yy<=y)return v[t];
        if(xx>=y || x>=yy)return 0;
        push(t);
        int m=(xx+yy)/2;
        return que(t*2,xx,m,x,y) | que(t*2+1,m,yy,x,y);
    }
};

#define endl '\n'
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,cnt=0;
    cin>>n;
    vvi g(n);
    vi st(n),en(n),par(n);
    rep(i,1,n){
        int a,b;
        cin>>a>>b;
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    function<void(int,int)> dfs = [&](int x, int p){
        par[x]=p;
        st[x]=cnt++; 
        for(int y:g[x])if(y!=p)
            dfs(y,x);
        en[x]=cnt;
    };
    dfs(0,-1);
    sg T;
    T.init(n);
    int q;
    cin>>q;
    rep(i,0,q){
        int c,v;
        cin>>c>>v;
        --v;
        if(c==1){
            int t=T.query(st[v],en[v]);
            if(t && par[v]>=0)
                T.update(st[par[v]],st[par[v]]+1,1);  //empty parent if was empty (to remember)
            T.update(st[v],en[v],0);
        }
        if(c==2)
            T.update(st[v],st[v]+1,1); //empty
        if(c==3)
            cout<<1-T.query(st[v],en[v])<<endl;
        
    }
    return 0;
}