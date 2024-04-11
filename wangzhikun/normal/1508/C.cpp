/*
    Author: Zhikun Wang 
 */
 
#include <bits/stdc++.h>

using namespace std;
#define int long long
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

mt19937_64 rnd(736);

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

int n,m,u[200020],v[200020],w[200020],cnt0[200020];

struct edge{
    int u,v,w,ty;
    bool operator < (const edge &rhs) const{
        return w < rhs.w;
    }
};

set<int> cont[200020];
vector<pii> G[200020];


int dis[1010][1010];

int bcj[200020];
ll ddd[200020];
int fnd(int x){
    if(bcj[x] == x){
        return x;
    }else{
        int u = fnd(bcj[x]);
        ddd[x]^=ddd[bcj[x]];
        return bcj[x] = u;
    }
}
void solve1(){
    int thr = (n-2)/2;
    vi V;
    for(int i=1;i<=n;i++){
        if(cont[i].size()<thr)V.PB(i);
        else{
            for(int j=1;j<=n;j++){
                if(!cont[i].count(j)){
                    int a = fnd(i),b = fnd(j);
                    if(a!=b)bcj[a] = b;
                }
            }
        }
    }
    for(int i=0;i<(int)(V.size()-1);i++){
        int a = fnd(V[i]),b = fnd(V[i+1]);
        if(a!=b)bcj[a] = b;
    }
    vector<edge> V2;
    for(int i=0;i<m;i++){
        V2.PB((edge){u[i],v[i],w[i],0});
    }
    sort(all(V2));
    ll ans = 0;
    for(auto ct:V2){
        if(fnd(ct.u) == fnd(ct.v))continue;
        int a = fnd(ct.u),b = fnd(ct.v);
        bcj[a] = b;
        ans+=ct.w;
    }
    cout<<ans<<endl;
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)bcj[i] = i;
    int q = 0;
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>w[i];
        cont[u[i]].insert(v[i]);
        cont[v[i]].insert(u[i]);
        cnt0[u[i]]+=1;
        cnt0[v[i]]+=1;
        q^=w[i];
    }
    int cc = 0;
    for(int i=1;i<=n;i++){
        if(cnt0[i]!=n-1)cc+=1;
    }
    if(n*(n-1)/2-m>=cc){
        solve1();
        return 0;
    }
    for(int i=0;i<m;i++){
        dis[u[i]][v[i]] = w[i];
        dis[v[i]][u[i]] = w[i];
    }
    vector<edge> V;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!dis[i][j]){
                V.PB((edge){i,j,0,1});
            }else{
                V.PB((edge){i,j,dis[i][j],0});
            }
        }
    }
    sort(all(V));
    ll ans = 0;
    for(auto ct:V){
        if(fnd(ct.u) == fnd(ct.v))continue;
        debug(ct.u,ct.v,ct.w,ct.ty);
        int a = fnd(ct.u),b = fnd(ct.v);
        bcj[a] = b;
        if(ct.ty)ddd[a] = rnd();
        else{
            ddd[a] = ddd[ct.u]^ddd[ct.v];
        }
        ans+=ct.w;
    }
    ll c = q;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(dis[i][j]){
                fnd(i);
                fnd(j);

                if(ddd[i]!=ddd[j]){
                    debug(i,j,ddd[i],ddd[j]);
                    c = min(c,1ll*dis[i][j]);
                }
            }
        }
    }
    ans+=c;
    cout<<ans<<endl;
    return 0;
}