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

int n,m,k,u,v,w;

vector<pii> G[400020],ind[400020];

set<pii> con[20][20];
int dis[20][20];
int ans = 0;
void dfs(int num){
    if(num == k+1){
        //debug(V);
        ans+=1;
        return;
    }
    for(int j=0;j<num;j++){
        if(dis[num][j])continue;
        for(auto ct:con[num][j]){
            dis[ct.F][ct.S]+=1;
        }
        dfs(num+1);
        for(auto ct:con[num][j]){
            dis[ct.F][ct.S]-=1;
        }
    }
}

int main() {
    read(n,m,k);
    for(int i=0;i<m;i++){
        read(u,v,w);
        G[u].PB(MP(w,v));
    }
    for(int i=1;i<=n;i++){
        sort(all(G[i]));
        //debug(i,G[i]);
        for(int j=0;j<G[i].size();j++){
            ind[G[i][j].S].PB(MP(G[i].size(),j));
        }
    }
    for(int i=1;i<=n;i++){
        sort(all(ind[i]));
        for(int j=0;j<(int)ind[i].size()-1;j+=1){
            if(ind[i][j] == ind[i][j+1]){
                dis[ind[i][j].F][ind[i][j].S]+=1;
            }
        }
        ind[i].erase(unique(all(ind[i])),ind[i].end());
        for(int j=0;j<ind[i].size();j++){
            for(int k=j+1;k<ind[i].size();k++){
                con[ind[i][j].F][ind[i][j].S].insert(ind[i][k]);
            }
        }
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}