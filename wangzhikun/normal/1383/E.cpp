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
int mod = 1000000007;
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}
string cc;
vector<int> G[1000010];
int fac[1000010];
int main() {
    cin>>cc;
    cc = '0'+cc;
    int zero = 0;
    for(int i=0;i<cc.size();i++){
        if(cc[i] == '1')zero = 1;
    }
    int cnt = 0;
    for(int i=cc.size()-1;i>=0;i--){
        if(cc[i] == '0')cnt+=1;
        else break;
    }
    for(int i=0;i<cc.size();i++){
        if(cc[i] == '1'){
            for(int j=i;j<cc.size() && j<=i+cnt;j++){
                if(j == i || cc[j] == '0')fac[j] = 1;
                else break;
            }
        }
    }
    if(!zero){
        cout<<cc.size()-1<<endl;
        return 0;
    }
    int n1 = 1000005,n0 = 1000005,zc = 0;
    vector<pii> Zl;
    for(int i= cc.size()-1;i>=0;i--){
        if(cc[i] == '1'){
            if(zc)Zl.PB(MP(i,zc));
            G[i].PB(n1);
            G[i].PB(n0);
            n1 = i;
            zc =0;
        }else{
            zc+=1;
            if(i+1<cc.size() && cc[i+1] == '0'){
                G[i].PB(i+1);
            }
            n0 = i;
            G[i].PB(n1);
        }
    }
    vector<pii> Q;
    reverse(all(Zl));
    for(int i=Zl.size()-1;i>=0;i--){
        pii cc = Zl[i];
        while(Q.size() && cc.S>=Q.back().S)Q.pop_back();
        if(Q.size()){
            G[cc.F+cc.S].PB(Q.back().F+cc.S+1);
        }
        Q.push_back(cc);
    }
    for(int i=cc.size()-1;i>=0;i--){
        for(auto ct:G[i])fac[i] = add(fac[i],fac[ct]);
    }/*
    for(int i=0;i<cc.size();i++){
        debug(i,G[i],fac[i]);
    }*/
    cout<<fac[0]<<endl;
    return 0;
}