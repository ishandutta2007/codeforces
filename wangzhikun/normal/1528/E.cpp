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

const int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}

int n;
int dp[1000010],su[1000010],inv[100010];

ll C(int a,int b){
    int ans = 1;
    for(int i=0;i<b;i++)ans = mul(ans,sub(a,i));
    for(int i=1;i<=b;i++)ans = mul(ans,inv[i]);
    return ans;
}

int main(){
    read(n);n+=1;
    dp[1] = 1;su[1] = 1;
    for(int i=1;i<=10;i++)inv[i] = mpow(i,mod-2);
    for(int i=2;i<=n;i++){
        dp[i] = (C(dp[i-1],1)+C(add(dp[i-1],1),2)+mul(dp[i-1],su[i-2]))%mod;
        su[i] = add(su[i-1],dp[i]);
    }
    int a = su[n-1],b = su[n-2];
    ll cans = ((C(a,1)+C(add(a,1),2)+C(add(a,2),3)-C(b,1)-C(add(b,1),2)-C(add(b,2),3))%mod+mod)%mod;
    int ans = (1ll*cans*2-1+mod)%mod;
    n-=1;
    for(int i=1;i<n;i++){
        ans = add(ans,mul(add(C(dp[i]+1,2),mul(dp[i],su[i-1])),sub(dp[n-i],1)));
    }
    cout<<ans<<endl;
    return 0;
}