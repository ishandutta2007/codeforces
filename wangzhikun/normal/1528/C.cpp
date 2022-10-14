/*
    Author: Zhikun Wang
    Date: 2021/05/24
    Misc: CF 
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

int T,n,f;
vi G1[300030],G2[300030];
int tim,ans = 0;
int ent[300030],ext[300030];
void dfs2(int num){
    tim+=1;
    ent[num] = tim;
    for(auto ct:G2[num]){
        dfs2(ct);
    }
    tim+=1;
    ext[num] = tim;
}
set<pii> A,B;

void dfs1(int num){
    int a = ent[num],b = ext[num];
    pii C = MP(a,b);
    auto it = A.lower_bound(MP(a,1e9));
    if(it != A.begin()){
        it--;
        pii CC = *it;
        if(CC.F<=C.F && CC.S>=C.S){
            A.erase(CC);B.insert(CC);
        }
    }
    it = A.lower_bound(MP(a,-1e9));
    int nop = 0;
    if(it!=A.end()){
        pii CC = *it;
        if(CC.F>=C.F && CC.S<=C.S){
            B.insert(C);
            nop = 1;
        }
    }
    if(!nop)A.insert(C);
    ans = max(ans,(int)A.size());
    for(auto ct:G1[num]){
        dfs1(ct);
    }
    if(A.count(C)){
        A.erase(C);
    }
    if(B.count(C)){
        B.erase(C);
    }
    it = B.lower_bound(MP(a,1e9));
    if(it != B.begin()){
        it--;
        pii CC = *it;
        if(CC.F<=C.F && CC.S>=C.S){
            auto it2 = A.lower_bound(CC);
            int nop = 0;
            if(it2!=A.end()){
                pii CC2 = *it2;
                if(CC2.F>=CC.F && CC2.S<=CC.S){
                    nop = 1;
                }
            }
            if(!nop){
                B.erase(CC);A.insert(CC);
            }
        }
    }
}
int main(){
    read(T);
    while(T--){
        read(n);
        for(int i=2;i<=n;i++){
            read(f);
            G1[f].PB(i);
        }
        for(int i=2;i<=n;i++){
            read(f);
            G2[f].PB(i);
        }
        tim = 0;
        ans = 0;
        dfs2(1);
        dfs1(1);
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++){
            G1[i].clear();
            G2[i].clear();
        }
    }
    return 0;
}