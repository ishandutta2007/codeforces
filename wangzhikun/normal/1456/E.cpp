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

int n,k;
ll lli[55],rli[55],a[55];

map<pll,ll> M[55][55][55];

ll getans(int lev,int l,int r,ll li,ll ri){
    if(lev == k || l>=r)return 0;
    if(M[lev][l][r].count(MP(li,ri))) return M[lev][l][r][MP(li,ri)];
    ll dp[2],val[55][2];
    bool leg[55][3] = {0};
    if(li == -1){
        leg[l][0] = leg[l][1] = 1;val[l][0] = val[l][1] = -1;
    }else{
        leg[l][li%2] = 1;val[l][li%2] = li;
    }
    if(ri == -1){
        leg[r][0] = leg[r][1] = 1;val[r][0] = val[r][1] = -1;
    }else{
        leg[r][ri%2] = 1;val[r][ri%2] = ri;
    }
    ll C = 1ll<<lev,D = C-1;
    for(int i = l+1;i<r;i++){
        ll cli = (lli[i]+D)/C,cri = (rli[i]+1)/C-1;
        if(cli%2 == 1){
            leg[i][1] = 1;val[i][1] = cli;
        }
        if(cri%2 == 0){
            leg[i][0] = 1;val[i][0] = cri;
        }
        if((cri-cli+1-(cli%2 == 1)-(cri%2 == 0))>=2){
            leg[i][2] = 1;
        }
    }
    dp[0] = dp[1] = 2e18;
    for(int k=0;k<2;k++){
        if(!leg[r][k])continue;
        for(int k2=0;k2<2;k2++){
            if(!leg[l][k2])continue;
            for(int j=r-1;j>=l;j--){
                if(leg[j][k])dp[k] = min(dp[k],getans(lev,l,j,val[l][k2],val[j][k])+getans(lev+1,j,r,val[j][k]>>1,val[r][k]>>1));
                if(leg[j][k^1])dp[k] = min(dp[k],getans(lev,l,j,val[l][k2],val[j][k^1])+getans(lev+1,j,r,val[j][k^1]>>1,val[r][k]>>1)+a[lev]);
                if(!leg[j][2])break;
            }
        }
    }
    M[lev][l][r][MP(li,ri)] = min(dp[0],dp[1]);
    return min(dp[0],dp[1]);
}

int main(){
    read(n,k);
    for(int i=1;i<=n;i++){
        read(lli[i],rli[i]);
    }
    for(int i=0;i<k;i++){
        read(a[i]);
    }
    cout<<getans(0,0,n+1,-1,-1)<<endl;
    return 0;
}