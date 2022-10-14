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
template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

int tim = 0;
int n,m,u,v,k,c[500050],ncol[500050],nco[500050],o_circ[500050];
vector<int> G[500050],c_cn[500050];

int idct[500050];

struct Graph{
    set<int> V;
    map<int,set<int>> E;
    map<int,int> col;
    void clear(){
        V.clear();
        E.clear();
        col.clear();
    }
    void insedg(int a,int b,int c,int d){
        debug(a,b,c,d);
        V.insert(a*2+0);V.insert(a*2+1);
        V.insert(c*2+0);V.insert(c*2+1);
        E[a*2+0].insert(a*2+1);
        E[a*2+1].insert(a*2+0);
        E[c*2+0].insert(c*2+1);
        E[c*2+1].insert(c*2+0);
        E[a*2+b].insert(c*2+d);
        E[c*2+d].insert(a*2+b);
    }
    bool dfs(int num){
        debug(num);
        bool ans = 0;
        for(auto ct:E[num]){
            if(col.count(ct)){
                if(col[ct]==col[num])ans = 1;
            }else{
                col[ct] = col[num]^1;
                ans|=dfs(ct);
            }
        }
        debug(ans);
        return ans;
    }
    bool test(){
        bool ans = 0;
        for(auto ct:V){
            if(!col.count(ct)){
                col[ct] = 0;
                ans|=dfs(ct);
            }
        }
        debug(ans);
        return ans;
    }
}alg[500050];

bool dfs(int num){
    bool ret = 0;
    for(auto ct:G[num]){
        if(c[ct]!=c[num])continue;
        if(!ncol[ct]){
            ncol[ct] = ncol[num];
            nco[ct] = nco[num]^1;
            ret|=dfs(ct);
        }else{
            ret|=nco[ct]^nco[num]^1;
        }
    }
    return ret;
}

int main() {
    read(n,m,k);
    for(int i=1;i<=n;i++){
        read(c[i]);
        c_cn[c[i]].PB(i);
    }
    for(int i=1;i<=m;i++){
        read(u,v);
        G[u].PB(v);
        G[v].PB(u);
    }
    
    ll ans = 0,rem = k;
    for(int i=1;i<=k;i++){
        for(auto ct:c_cn[i]){
            if(!ncol[ct]){
                ncol[ct] = ++tim;
                o_circ[i]|=dfs(ct);
            }
        }
        rem-=o_circ[i];
    }
    for(int i=1;i<=k;i++){
        if(o_circ[i])continue;
        rem-=1;
        debug(i,rem);
        ans+=rem;
        vector<int> t_pro;
        for(auto cv:c_cn[i]){
            for(auto ct:G[cv]){
                if(c[cv]>=c[ct] || o_circ[c[ct]])continue;
                if(idct[c[ct]] != i){
                    idct[c[ct]] = i;
                    alg[c[ct]].clear();
                    t_pro.PB(c[ct]);
                }
                alg[c[ct]].insedg(ncol[cv],nco[cv],ncol[ct],nco[ct]);
            }
        }
        for(auto ct:t_pro){
            if(alg[ct].test()){
                debug(i,ct);
                ans-=1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}