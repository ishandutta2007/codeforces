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

struct solver{
    #define nn 55
    vector<int> Map[nn];
    int T, i, m, u, v;
    int n, vis[nn], match[nn];
    bool dfs(int u)
    {
        for(int i = 0; i < Map[u].size(); i++)
        {
            int to = Map[u][i];
            if(!vis[to])
            {
                vis[to] = 1;
                if(!match[to] || dfs(match[to]))
                {
                    match[to] = u;
                    return 1;
                }
            }
        }
        return 0;
    }
    int solve()
    {
        memset(match, 0, sizeof(match));
        int ans = 0;
        for(int i = 1; i <= n; i++)//
        {
            memset(vis, 0, sizeof(vis));
            if(dfs(i)) ans++;
        }
        return ans;
    }
    void add(int u, int v){
        Map[u].push_back(v);
    }
    int main(){
        return n - solve();
    }
};

int n,m,k;

int ind[55];
vi G[55],rG[55];
vi Q,A;

ll dp[55][55],fr[55][55],x[55],y[55],u,v;
int use[55],ruse[55];
int main(){
    read(n,m,k);
    solver S;
    S.n = n;S.m = m;
    for(int i=0;i<m;i++){
        read(u,v);
        G[u].PB(v);
        rG[v].PB(u);
        ind[v]+=1;
        S.add(u,v);
    }
    for(int i=1;i<=n;i++){
        use[i] = 1;
        ruse[i] = 1;
    }
    int cs = S.main();
    memset(dp,7,sizeof(dp));
    dp[0][0] = 0;
    int req = max(0,k-cs+1);
    int la = cs;
    for(int i=0;i<req;i++){
        for(int j=1;j<=n;j++){
            if(!use[j])continue;
            use[j] = 0;
            solver nS; nS.n = n;
            for(int u=1;u<=n;u++){
                for(auto v:G[u]){
                    if(use[u] && ruse[v])nS.add(u,v);
                }
            }
            if(nS.main()!=la){
                A.PB(j);
                goto nxt;
            }else{
                use[j] = 1;
            }
        }
        for(int j=1;j<=n;j++){
            if(!ruse[j])continue;
            ruse[j] = 0;
            solver nS; nS.n = n;
            for(int u=1;u<=n;u++){
                for(auto v:G[u]){
                    if(use[u] && ruse[v])nS.add(u,v);
                }
            }
            if(nS.main()!=la){
                A.PB(-j);
                goto nxt;
            }else{
                ruse[j] = 1;
            }
        }
        nxt:;
        la+=1;
    }
    for(int i=1;i<=k;i++){
        read(x[i],y[i]);
        for(int j=0;j<=req;j++){
            for(int kk=max(j,i-cs+1);kk<=req;kk++){
                if(dp[i-1][j]+min(x[i],(kk-j)*y[i])<dp[i][kk]){
                    dp[i][kk] = dp[i-1][j]+min(x[i],(kk-j)*y[i]);
                    fr[i][kk] = j;
                }
            }
        }
    }
    vi O;
    int p = req;
    for(int i=k;i>=1;i--){
        O.PB(0);
        for(int j=fr[i][p];j<p;j++)O.PB(A[j]);
        p = fr[i][p];
    }
    reverse(all(O));
    cout<<O.size()<<endl;
    for(int i=0;i<O.size();i++)cout<<O[i]<<' ';cout<<endl;
    return 0;
}