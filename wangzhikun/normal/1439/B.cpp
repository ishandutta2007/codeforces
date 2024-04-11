/*
    Author: Zhikun Wang 
 */
 
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cerr << '\n'; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}

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

int T,n,m,k,u,v;

int active[100010],deg[100010];

#define GPD __gnu_pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
GPD::gp_hash_table<int,int> Gs[100010];
vector<int> G[100010];
int main() {
    read(T);
    while(T--){
        read(n,m,k);
        for(int i=1;i<=n;i++){
            Gs[i].clear();
            G[i].clear();
            active[i] = 1;
            deg[i] = 0;
        }
        for(int i=1;i<=m;i++){
            read(u,v);
            G[u].PB(v);
            G[v].PB(u);
            Gs[u][v] =1;
            Gs[v][u] = 1;
            deg[u]+=1;
            deg[v]+=1;
        }
        set<pii> S;
        if(1ll*k*(k-1)/2>m){
            cout<<-1<<"\n";
            goto nxt;
        }
        for(int i=1;i<=n;i++){
            S.insert(MP(deg[i],i));
        }
        while(!S.empty()){
            pii A = *S.begin();
            if(A.F>=k){
                cout<<1<<" "<<S.size()<<'\n';
                for(auto ct:S)cout<<ct.S<<' ';
                cout<<'\n';
                goto nxt;
            }
            if(A.F == k-1){
                vector<int> cs;
                cs.PB(A.S);
                for(auto ct:G[A.S]){
                    if(active[ct])cs.PB(ct);
                }
                for(auto ct:cs)if(G[ct].size()<k-1)goto extt;
                for(auto ct1:cs){
                    for(auto ct2:cs){
                        if(ct2>ct1 && Gs[ct2].find(ct1) == Gs[ct2].end()) goto extt;
                    }
                }
                cout<<2<<'\n';
                for(auto ct:cs)cout<<ct<<' ';
                cout<<'\n';
                goto nxt;
            }
            extt:;
            S.erase(A);
            active[A.S] = 0;
            for(auto ct:G[A.S]){
                if(active[ct]){
                    S.erase(MP(deg[ct],ct));
                    deg[ct]-=1;
                    S.insert(MP(deg[ct],ct));
                }
            }
        }
        cout<<-1<<'\n';
        nxt:;
    }
    return 0;
}