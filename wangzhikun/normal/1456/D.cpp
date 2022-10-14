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
#define int long long
int n,T[5050],X[5050];

bool dp[5005][5005];
int mv1[5005],mv0[5005];

signed main() {
    read(n);
    for(int i=0;i<=n;i++)mv0[i] = mv1[i] = -1;
    for(int i=1;i<=n;i++){
    	read(T[i]);
    	read(X[i]);
    }
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
    	int cat = 0;
    	for(int j=0;j<=n;j++){
    		if(!dp[i][j])continue;
    		debug(i,j);
    		if(abs(X[i+1]-X[i])<=T[i+1]-T[i]){
    			dp[i+1][j] = 1;
    			mv0[i+1] = max(mv0[i+1],T[i+1]-T[i]-abs(X[i+1]-X[i]));
    		}
    		if(j == i+1)mv1[j] = max(mv1[j],T[j]-T[i]);
    		cat = 1;
    	}
    	if(cat){
    		for(int j=1;j<=n;j++){
    			if(abs(X[j]-X[i])+abs(X[j]-X[i+1])<=T[i+1]-T[i]){
    				dp[i+1][j] = 1;
    			}
    		}
    	}
    	if(mv0[i]!=-1){
    		debug(i,mv0[i]);
    		int l = X[i]-mv0[i],r = X[i]+mv0[i];
    		for(int j=1;j<=n;j++){
    			int dist;
    			if(X[j]>r){
    				dist = X[j]-r;
    			}else if(X[j]<l){
    				dist = l-X[j];
    			}else{
    				dist = 0;
    			}
    			if(dist+abs(X[j]-X[i+1])<=T[i+1]-T[i]){
    				dp[i+1][j] = 1;
    				if(j == i+1)mv0[j] = max(mv0[j],T[i+1]-T[i]-(dist+abs(X[j]-X[i+1])));
    			}
    		}
    	}
    	if(mv1[i]!=-1){
    		debug(i,mv1[i]);
			int l = X[i-1]-mv1[i],r = X[i-1]+mv1[i];
    		for(int j=1;j<=n;j++){
    			int dist;
    			if(X[j]>r){
    				dist = X[j]-r;
    			}else if(X[j]<l){
    				dist = l-X[j];
    			}else{
    				dist = 0;
    			}
    			if(dist+abs(X[j]-X[i+1])<=T[i+1]-T[i]){
    				dp[i+1][j] = 1;
    				if(j == i+1)mv0[j] = max(mv0[j],T[i+1]-T[i]-(dist+abs(X[j]-X[i+1])));
    			}
    		}
    	}
    }
    int ans  =0;
    if(mv0[n]!=-1 || mv1[n]!=-1)ans = 1;
    for(int j=0;j<=n;j++)if(dp[n][j])ans = 1;

    if(ans == 1){
    	cout<<"YES\n";
    }else{
    	cout<<"NO\n";
    }
    return 0;
}