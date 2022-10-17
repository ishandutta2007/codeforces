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

void mmin(int &a, int b){a=min(a,b);}

#define time ttime
const int maxn = 300005;

int T=1;
stack<int> st;
int bcc[maxn], bc=0;
int time[maxn], low[maxn];
void dfs(int x,int p, vvi& g){
    time[x] = low[x] = T++;
    st.push(x);
    for(int y:g[x]) if(y!=p){
        if(!time[y]){
            dfs(y,x,g);
            mmin(low[x],low[y]);
        }
        else mmin(low[x],time[y]);
    }
    if(low[x]==time[x]){
        bcc[x]=++bc;
        while(st.top()!=x)
            bcc[st.top()]=bc, st.pop();
        st.pop();
    }
}

namespace dfs2{
    int target;
    vector<map<int,bool> > g;
    vi art;
    int vis[maxn];
    bool f(int x,int p,bool found){
        if(vis[x]) return false;
        vis[x] = 1;
        found |= art[x];
        if(x==target) return found;
        for(pii y:g[x]) if(y.X!=p){
            if(f(y.X,x,found || y.Y)) return true;
        }
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b,c;
    cin>>n>>m;
    vvi g(n+1);
    vi x(m),y(m),z(m);
    rep(i,0,m){
        cin>>a>>b>>c;
        g[a].pb(b);
        g[b].pb(a);
        x[i]=a, y[i]=b, z[i]=c;
    }
    rep(i,1,n+1)if(!time[i])dfs(i,-1,g);
    bc++;
    //rep(i,1,n+1)cout<<i<<" "<<bcc[i]<<endl;
    vector<map<int,bool> > gg(bc);
    vi art(bc);
    rep(i,0,m){
        a = bcc[x[i]], b=bcc[y[i]];
        if(a==b){
            art[a] |= z[i];
            continue;
        }
        gg[a][b] |= z[i];
        gg[b][a] |= z[i];
    }
    cin>>a>>b;
    dfs2::target = bcc[b];
    dfs2::art = move(art);
    dfs2::g = move(gg);
    cout<<(dfs2::f(bcc[a],-1,0)?"YES":"NO")<<endl;
    return 0;
}