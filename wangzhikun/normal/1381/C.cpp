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

int T,n,x,y;
int b[100010],c[100010];
vector<int> ocur[100010];
int main() {
    read(T);
    while(T--){
        read(n,x,y);
        for(int i=1;i<=n+1;i++){
            ocur[i].clear();
        }
        for(int i=1;i<=n;i++){
            read(b[i]);
            ocur[b[i]].PB(i);
        }
        priority_queue<pii> Q;
        for(int i=1;i<=n+1;i++)Q.push(MP(ocur[i].size(),i));
        for(int i=0;i<x;i++){
            pii cu = Q.top();Q.pop();
            debug(cu,i,ocur[cu.S].back());
            c[ocur[cu.S].back()] = cu.S;
            ocur[cu.S].pop_back();
            cu.F--;
            Q.push(cu);
        }
        vector<pii> V;
        int uoc = -1;
        while(!Q.empty()){
            pii cu = Q.top();Q.pop();
            if(cu.F)V.PB(cu);
            else uoc = cu.S;
        }
        if(!V.size()){
            cout<<"YES\n";
            for(int i=1;i<=n;i++)cout<<c[i]<<' ';
            cout<<'\n';
            continue;
        }
        int req = y-x,rmoc = n-x-max(V[0].F*2-(n-x),0);
        if(req>rmoc)cout<<"NO\n";
        else{
            vector<int> toC;
            vector<int> frB;
            for(int i=0;i<V.size();i++){
                for(auto ct:ocur[V[(i+1)%V.size()].S])toC.PB(ct);
                if(i == 0 && ocur[V[0].S].size()*2>n-x){
                    for(int i=0;i<n-x-ocur[V[0].S].size();i++)frB.PB(ocur[V[0].S][i]);
                }else{
                    for(auto ct:ocur[V[i].S])frB.PB(ct);
                }
            }
            debug(toC,frB,uoc);
            for(int i=0;i<n-x;i++){
                if(i<req)c[toC[i]] = b[frB[i]];
                else c[toC[i]] = uoc;
            }
            cout<<"YES\n";
            for(int i=1;i<=n;i++)cout<<c[i]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}