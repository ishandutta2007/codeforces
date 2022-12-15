#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 200005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

const ld PI = (ld)4*atanl(1);

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

struct node{
    int l,r,sum;
    ll lazy;
    pair<ll,int> mn;
};

int N,M,Q,cnt[MAXN],in[MAXN],out[MAXN],sz[MAXN],par[MAXN],heavy[MAXN],head[MAXN],depth[MAXN],pos[MAXN],tot[MAXN],cc;
pair<ll,int> vals[MAXN];
vector<int> adj[MAXN],girls[MAXN];
node seg[4*MAXN];

inline void push_down(int rt){
    seg[rt<<1].mn.first+=seg[rt].lazy, seg[rt<<1|1].mn.first+=seg[rt].lazy;
    seg[rt<<1].lazy+=seg[rt].lazy, seg[rt<<1|1].lazy+=seg[rt].lazy;
    seg[rt].lazy = 0;
}

void build(int l, int r, int rt){
    seg[rt].l = l, seg[rt].r = r;
    if(l == r){
        seg[rt].mn = vals[l];
        if(seg[rt].mn.first == 0)
            seg[rt].sum++;
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    seg[rt].mn = min(seg[rt<<1].mn,seg[rt<<1|1].mn);
    seg[rt].sum = seg[rt<<1].sum+seg[rt<<1|1].sum;
}

void update(int l, int r, int rt, int val){
    if(l > r) return;
    if(seg[rt].l == l && seg[rt].r == r){
        seg[rt].mn.first+=val, seg[rt].lazy+=val;
        return;
    }
    if(seg[rt].lazy) push_down(rt);
    int mid = (seg[rt].l+seg[rt].r)/2;
    if(r <= mid) update(l,r,rt<<1,val);
    else if(l > mid) update(l,r,rt<<1|1,val);
    else update(l,mid,rt<<1,val), update(mid+1,r,rt<<1|1,val);
    seg[rt].mn = min(seg[rt<<1].mn,seg[rt<<1|1].mn);
}

pair<ll,int> query(int l, int r, int rt){
    if(l > r) return mp(LL_INF,INT_INF);
    if(seg[rt].l == l && seg[rt].r == r) return seg[rt].mn;
    if(seg[rt].lazy) push_down(rt);
    int mid = (seg[rt].l+seg[rt].r)/2;
    if(r <= mid) return query(l,r,rt<<1);
    else if(l > mid) return query(l,r,rt<<1|1);
    else{
        pair<ll,int> f = query(l,mid,rt<<1), s = query(mid+1,r,rt<<1|1);
        return min(f,s);
    }
}

void remove(int pos, int rt){
    if(seg[rt].l == seg[rt].r){
        seg[rt].mn = mp(LL_INF,INT_INF);
        seg[rt].sum = 0;
        return;
    }
    if(seg[rt].lazy) push_down(rt);
    int mid = (seg[rt].l+seg[rt].r)/2;
    if(pos <= mid) remove(pos,rt<<1);
    else remove(pos,rt<<1|1);
    seg[rt].mn = min(seg[rt<<1].mn,seg[rt<<1|1].mn);
    seg[rt].sum = seg[rt<<1].sum+seg[rt<<1|1].sum;
}

void print(){
    for(int i=1; i<=cc; i++){
        pair<ll,int> t = query(i,i,1);
        cout << t.first << " " << t.second << endl;
    }
    cout << endl;
}

void dfs(int node, int prev){
    sz[node] = 1;
    for(int check:adj[node]){
        if(check == prev) continue;
        depth[check] = depth[node]+1;
        dfs(check,node);
        sz[node]+=sz[check];
        par[check] = node;
        if(sz[check] > sz[heavy[node]])
            heavy[node] = check;
    }
}

void decompose(int node, int prev, int h){
    head[node] = h;
    in[node] = ++cc;
    vals[cc] = mp(LL_INF,INT_INF);
    for(int i=1; i<=cnt[node]; i++){
        vals[++cc] = mp(girls[node][i-1],girls[node][i-1]);
        pos[girls[node][i-1]] = cc;
    }
    tot[node] = cc;
    if(heavy[node])
        decompose(heavy[node],node,h);
    for(int check:adj[node]){
        if(check == prev || check == heavy[node]) continue;
        decompose(check,node,check);
    }
    out[node] = cc;
}

inline pair<ll,int> query(int a, int b){
    pair<ll,int> res = mp(LL_INF,INT_INF);
    for(; head[a] != head[b]; b = par[head[b]]){
        if(depth[head[a]] > depth[head[b]]) swap(a,b);
        assert(in[head[b]]<=tot[b]);
        pair<ll,int> t = query(in[head[b]],tot[b],1);
        res = min(res,t);
    }
    if(depth[a] > depth[b]) swap(a,b);
    assert(in[a]<=tot[b]);
    pair<ll,int> t = query(in[a],tot[b],1);
    return min(res,t);
}

int main(){
    fastio; cin >> N >> M >> Q;
    for(int i=1; i<N; i++){
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1; i<=M; i++){
        int a; cin >> a;
        cnt[a]++;
        girls[a].pb(i);
    }
    //CHAGE MAXN BBACK BBEFORE SUBMMIT
    dfs(1,-1);
    decompose(1,-1,1);
    build(1,cc,1);
//    print();
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            int u,v,k; cin >> u >> v >> k;
            vector<int> res;
            for(int j=1; j<=k; j++){
                pair<ll,int> t = query(u,v);
                if(t.first == LL_INF) break;
                res.pb(t.second);
                remove(pos[t.second],1);
            }
            cout << res.size() << " ";
            for(int check:res)
                cout << check << " ";
            cout << endl;
        }else{
            int u,k; cin >> u >> k;
            update(in[u],out[u],1,k);
        }
    }
}
/*
5 7 1
3 5
2 3
4 3
1 4
4 1 4 5 4 1 4
1 3 5 2
ans=4
 */