/*
    Author: Zhikun Wang 
*/
 
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cerr << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define set0(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

vi val, comp, z, cont;
int Time, ncomps;
template<class G> int dfs(int j, G& g) {
    int low = val[j] = ++Time, x; z.push_back(j);
    for (auto e : g[j]) if (comp[e] < 0)
        low = min(low, val[e] ?: dfs(e,g));

    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        cont.clear();
        ncomps++;
    }
    return val[j] = low;
}
template<class G> void scc(G& g) {
    int n = sz(g);
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i,0,n) if (comp[i] < 0) dfs(i, g);
}

ll n,m,a,b,l;
vector<pll> oG[200020],uG[200020],rG[200020];
vector<vi> G;

vector<pair<ll,pll>> E; 
int vis[200020],vis2[200020];
ll dis[200020],dis2[200020];

void dfs1(int num){
    vis[num] = 1;
    for(auto ct:uG[num]){
        if(!vis[ct.F]){
            dis[ct.F] = dis[num]+ct.S;
            dfs1(ct.F);
        }else{
            E.PB(MP(num,ct));
        }
    }
}

void dfs2(int num){
    vis2[num] = 1;
    for(auto ct:rG[num]){
        if(!vis2[ct.F]){
            dis2[ct.F] = dis2[num]+ct.S;
            dfs2(ct.F);
        }
    }
}

ll g[200020];
ll gcd(ll a,ll b){
    if(b == 0)return a;
    return gcd(b,a%b);
}
int main(){
    read(n,m);
    for(int i=0;i<m;i++){
        read(a,b,l);
        oG[a].PB(MP(b,l));
    }
    G.PB({});
    for(int i=1;i<=n;i++){
        vi C;
        for(auto ct:oG[i])C.PB(ct.F);
        G.PB(C);
    }
    scc(G);
    for(int i=1;i<=n;i++){
        for(auto ct:oG[i]){
            if(comp[ct.F] == comp[i]){
                uG[i].PB(MP(ct.F,ct.S));
                rG[ct.F].PB(MP(i,ct.S));
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(i);
            dfs2(i);
            for(auto ct:E){
                g[comp[i]] = gcd(g[comp[i]],dis[ct.F]+dis2[ct.S.F]+ct.S.S);
            }
            E.clear();
        }
    }
    ll Q,v,s,t;
    read(Q);
    while(Q--){
        read(v,s,t);
        ll cd = gcd(t,g[comp[v]]);
        if((t-s)%cd == 0){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}