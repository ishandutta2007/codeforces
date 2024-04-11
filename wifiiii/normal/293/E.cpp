//#include <bits/stdc++.h>
//using namespace std;
//
//#define REP(i, n) for(int i = 0; i < (n); i++)
//typedef long long int ll;
//
//const int maxn = 100100;
//
//int fen[maxn];
//
//void ubaci(int x, int sta) {
//    x++;
//    for(int i = x; i < maxn; i += i &- i) fen[i] += sta;
//    return;
//}
//
//int daj(int x) {
//    x++;
//    int ret = 0;
//    for(int i = x; i > 0; i -= i &- i) ret += fen[i];
//    return ret;
//}
//
//ll rj = 0, pom_rj, pom_rj2;
//int l, w;
//
//vector <vector <pair <int, int> > > graf;
//vector <bool> obraden;
//vector <int> vel;
//
//int daj_vel(int cvor, int rod) {
//    vel[cvor] = 1;
//    for(pair <int, int> sus : graf[cvor]) {
//        if(obraden[sus.first] || sus.first == rod) continue;
//        vel[cvor] += daj_vel(sus.first, cvor);
//    }
//    return vel[cvor];
//}
//
//ll rijesi(vector <pair <int, int> > &upiti) {
//    ll ret = 0;
//    sort(upiti.begin(), upiti.end());
//    int ptr = 0;
//    for(int i = (int)upiti.size() - 1; i >= 0; i--) {
//        while(ptr < (int)upiti.size() && upiti[ptr].first <= w - upiti[i].first) {
//            ubaci(upiti[ptr].second, 1);
//            ptr++;
//        }
//        ret += daj(l - upiti[i].second);
//    }
//    for(ptr--; ptr >= 0; ptr--) ubaci(upiti[ptr].second, -1);
//    return ret;
//}
//
//vector <pair <int, int> > tr_upiti, svi_upiti;
//
//void daj_upite(int cvor, int rod, int dub, int tez) {
//    tr_upiti.push_back(make_pair(tez, dub));
//    if(dub <= l && tez <= w) rj++;
//    if(dub * 2 <= l && tez * 2 <= w) pom_rj++;
//    for(pair <int, int> sus : graf[cvor]) {
//        if(obraden[sus.first] || sus.first == rod) continue;
//        daj_upite(sus.first, cvor, dub + 1, tez + sus.second);
//    }
//    return;
//}
//
//void dek(int cvor) {
//    int n = daj_vel(cvor, -1), rod = -1;
//    bool nasao = 0;
//    while(!nasao) {
//        nasao = 1;
//        for(pair <int, int> sus : graf[cvor]) {
//            if(obraden[sus.first] || sus.first == rod) continue;
//            if(vel[sus.first] > n / 2) {
//                nasao = 0;
//                rod = cvor;
//                cvor = sus.first;
//                break;
//            }
//        }
//    }
//    obraden[cvor] = 1;
//    svi_upiti.clear();
//    pom_rj2 = 0;
//    for(pair <int, int> sus : graf[cvor]) {
//        if(!obraden[sus.first]) {
//            pom_rj = 0;
//            tr_upiti.clear();
//            daj_upite(sus.first, cvor, 1, sus.second);
//            pom_rj2 += pom_rj;
//            rj -= (rijesi(tr_upiti) + pom_rj) / 2;
//            svi_upiti.insert(svi_upiti.end(), tr_upiti.begin(), tr_upiti.end());
//        }
//    }
//    rj += (rijesi(svi_upiti) + pom_rj2) / 2;
//    for(pair <int, int> sus: graf[cvor]) {
//        if(!obraden[sus.first]) dek(sus.first);
//    }
//    return;
//}
//
//int main() {
//    int n;
//    scanf("%d%d%d", &n, &l, &w);
//    graf.resize(n, vector <pair <int, int> >());
//    obraden.resize(n, 0);
//    vel.resize(n);
//    int a, b;
//    REP(i, n - 1) {
//        scanf("%d%d", &a, &b);
//        a--;
//        graf[i + 1].push_back(make_pair(a, b));
//        graf[a].push_back(make_pair(i + 1, b));
//    }
//    dek(0);
//    cout << rj << endl;
//    return 0;
//}


#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 100005;
int sz[maxn], mx[maxn], vis[maxn];
int N,rt,n,k;
struct edge {
    int v,w;
};
vector<edge> g[maxn];
ll L, W;
void getrt(int u, int fa) {
    sz[u] = 1; mx[u] = 0;
    for(edge e : g[u]) {
        int v = e.v;
        if(vis[v] || v == fa) continue;
        getrt(v, u);
        sz[u] += sz[v];
        mx[u] = max(mx[u], sz[v]);
    }
    mx[u] = max(mx[u], N - sz[u]);
    if(mx[u] < mx[rt]) rt = u;
}
ll ans = 0;
pair<int,ll> vec[maxn];int tp=0;
ll tx,ty;
void add(int u,int fa,ll cur,ll cur2) {
    if(cur>tx || cur2>ty) return;
    vec[++tp]={cur,cur2};
    for(edge e:g[u]) {
        int v=e.v;
        if(v==fa || vis[v]) continue;
        add(v,u,cur+1,cur2+e.w);
    }
}
int bit[maxn];
void add(int x,int v){x++;for(;x<maxn;x+=x&-x)bit[x]+=v;}
int sum(int x) {x++;int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}

ll calc(int u, ll x, ll y) {
    if(x < 0 || y < 0) return 0;
    tx = x, ty = y;
    ll ret = 0;
    vec[tp=1]={0,0};
    for(edge e:g[u]) {
        int v=e.v;
        if(vis[v]) continue;
        add(v,u,1,e.w);
    }
    sort(vec+1,vec+1+tp,[&](pair<int,ll>i,pair<int,ll>j){return i.second<j.second;});
    int j=0;
    for(int i=tp;i>=1;--i) {
        while(j<tp && vec[i].second+vec[j+1].second<=y) add(vec[++j].first, 1);
        ret+=sum(x-vec[i].first);
    }
    for(int i=1;i<=j;++i) add(vec[i].first,-1);
    return ret;
}
void solve(int u) {
    vis[u] = 1;
    ans += calc(u, L, W);
    for(edge e : g[u]) {
        if(vis[e.v]) continue;
        ans -= calc(e.v, L-2, W-2*e.w);
    }
    int last = N;
    for(edge e : g[u]) {
        int v = e.v;
        if(vis[v]) continue;
        N = sz[u] > sz[v] ? sz[v] : last - sz[u];
        rt = 0;
        getrt(v, u);
        solve(rt);
    }
}
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;else if(c==EOF) return -1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main() {
    n=read(),L=read(),W=read();
    for(int i=2;i<=n;++i) {
        int u=read(),w=read();
        g[i].push_back({u,w});
        g[u].push_back({i,w});
    }
    N = n; mx[0] = 1e9; rt = 0;
    getrt(1,-1);
    solve(rt);
    cout<<(ans-n)/2<<endl;
}

/*
 *
5 3 10
1 3
1 4
2 2
2 4

 */