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

ll n,m,x,u,v;
ll a[300030];
set<pll> G[300030];

int bcj[300030];

int fnd(int x){
    return bcj[x] == x?x:bcj[x] = fnd(bcj[x]);
}

int main(){
    read(n,m,x);
    ll cs = 0;
    set<pll> S;
    for(int i=1;i<=n;i++){
        read(a[i]);
        cs+=a[i];
        bcj[i] = i;
        S.insert(MP(a[i],i));
    }
    if(cs<x*(n-1)){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=m;i++){
        read(u,v);
        G[u].insert(MP(v,i));
        G[v].insert(MP(u,i));
    }
    for(int it=0;it<n-1;it++){
        pll C = *S.rbegin();S.erase(C);
        pll edg;
        while(1){
            auto ct = *G[C.S].begin();
            if(fnd(ct.F) == C.S){
                G[C.S].erase(ct);
                continue;
            }
            edg = ct;
            break;
        }
        cout<<edg.S<<'\n';
        ll c = fnd(edg.F),d = C.S;
        S.erase(MP(a[c],c));
        if(G[c].size()<G[d].size())swap(c,d);
        bcj[d] = bcj[c];
        a[c]+=a[d];
        a[c]-=x;
        for(auto ct:G[d])G[c].insert(ct);
        S.insert(MP(a[c],c));
    }
    return 0;
}