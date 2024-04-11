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

const int mod = 1000000007;
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}
const int N = 1000000;
int fac[N+10],invfac[N+10];

int Cc(int n,int m){
    if(n<0 || m<0 || m>n)return 0;
    return mul(fac[n],mul(invfac[m],invfac[n-m]));
}

int n,a[70],vis[70],C[120][120];
ll conn[70],cvis = 0;
int pcnt(ll x){return __builtin_popcountll(x);}
int main(){
    fac[0] = 1;
    for(int i=1;i<=N;i++)fac[i] = mul(fac[i-1],i);
    invfac[N] = mpow(fac[N],mod-2);
    for(int i=N-1;i>=0;i--) invfac[i] = mul(invfac[i+1],i+1);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<120;i++)for(int j=0;j<120;j++)C[i][j] = Cc(i,j);
    sort(a+1,a+n+1);
    int cfa = 0;
    for(int i=1;i<=n;i++)debug(a[i]);
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        conn[cfa] = 0;
        for(int j=i+1;j<=n;j++){
            if(a[j]%a[i] == 0){
            debug(a[i],a[j]);
                vis[j] = 1;
                conn[cfa]|=1ll<<j;
            }
        }
        if(pcnt(conn[cfa])>=2){
            debug(a[i],conn[cfa]);
            cfa+=1;
        }
    }
    debug(cfa);
    int coef = 1,ccs = 0;
    for(int i=0;i<cfa;i++){
        ll Cv = conn[i];
        debug(i,Cv);
        vector<ll> M;
        M.PB(conn[i]);
        for(int j=0;j<cfa;j++){
            for(int k=0;k<cfa;k++){
                if(Cv&conn[k]){
                    int isin = 0;
                    for(auto ct:M)if(ct == conn[k])isin = 1;
                    if(!isin)M.PB(conn[k]);
                    Cv = Cv|conn[k];
                }
            }
        }
        debug(cvis,Cv,cvis&Cv);
        if(cvis&Cv)continue;
        ccs+=1;
        if(cvis) coef = mul(coef,C[pcnt(Cv|cvis)-ccs][pcnt(Cv)-1]);
        debug(cvis,coef,Cv,pcnt(Cv));
        cvis|=Cv;
        int cc = 0,cs = M.size();
        debug(M,cs);
        int ccnt[200] = {0};
        vector<int> cv;
        for(int i=1;i<=60;i++){
            if(!((Cv>>i)&1))continue;
            int c = 0;
            for(int j=0;j<cs;j++){
                if((M[j]>>i)&1)c|=1<<j;
            }
            debug(i,c);
            if(!ccnt[c])cv.PB(c);
            ccnt[c]+=1;
        }
        int cs2 = cv.size(),tc = pcnt(Cv);
        vi dp(1<<cs2,0);
        
        dp[0] = 1;
        for(int i=1;i<1<<cs2;i++){
            int cc = 0,has[10] = {0};
            for(int j=0;j<cs2;j++)if((i>>j)&1){
                for(int k=0;k<cs;k++)if((cv[j]>>k)&1)has[k]+=1;
                cc+=ccnt[cv[j]];
            }
            for(int j=0;j<cs2;j++)if((i>>j)&1){
                int ok = pcnt(i) == 1;
                for(int k=0;k<cs;k++)if((cv[j]>>k)&1 && has[k]>1){ok = 1;break;}
                if(ok){
                    dp[i] = add(dp[i],mul(fac[ccnt[cv[j]]],mul(C[tc-cc+ccnt[cv[j]]-1][ccnt[cv[j]]-1],dp[i-(1<<j)])));
                }
            }
        }
        coef = mul(coef,dp[(1<<cs2)-1]);
    }
    cout<<coef<<endl;
    return 0;
}