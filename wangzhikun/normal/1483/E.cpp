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
mt19937_64 rng(1);
template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

int T;

ll lwb = 0,upb = 100000000000000,balance = 1,ans,cnt = 0;
void query(ll x){
    cnt+=1;
    cout<<"? "<<x<<endl;//debug(balance,lwb,upb,upb-lwb);
    cout.flush();
    string S;
    cin>>S;
    //if(x<=ans)S = "Lucky";
    //else S = "Fraud";
    if(S[0] == 'F' && S[0] == 'i')exit(0);
    if(S[0] == 'F'){
        upb = x-1;
        balance-=x;
    }
    if(S[0] == 'L'){
        lwb = x;
        balance+=x;
    }
}

int dp[3010][110] = {0},bst[3010][110];
void solve(){
    lwb = 0;upb = 100000000000000;balance = 1;cnt = 0;
    for(int i=0;i<47;i++){
        if(upb == 100000000000000){
            query(1ll<<i);
            debug(lwb,upb);
        }
    }
    while(lwb!=upb){
        if(upb<lwb*1.01 && upb-lwb<2000)break;
        ll c = lwb+(upb-lwb)*0.3333;
        if(c == lwb)c+=1;
        while(c>balance)query(lwb);
        query(c);
        while(lwb == c && lwb!=upb){
            c = lwb+(upb-lwb)/2;
            if(c == lwb)c+=1;
            while(c>balance)query(lwb);
            query(c);
        }
    }
    while(lwb!=upb){
        ll c = bst[upb-lwb+1][balance/upb];
        query(lwb+c-1);
    }
    cout<<"! "<<lwb<<endl;
    cout.flush();
    //cout<<cnt<<endl;
    assert(cnt<=105);
}

int main() {
    memset(dp,7,sizeof(dp));
    for(int i=0;i<105;i++)dp[0][i] = dp[1][i] = 0;
    for(int i=1;i<2005;i++){
        for(int j=105;j>=0;j--){
            for(int k=1;k<=i;k++){
                if(max(dp[k-1][j-1],dp[i-k+1][j+1])+1<dp[i][j]){
                    dp[i][j] = max(dp[k-1][j-1],dp[i-k+1][j+1])+1;
                    bst[i][j] = k;
                }
            }
        }
    }
    read(T);
    while(T--){
        solve();
    }
    return 0;
}