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
int a[10] = {119,18,93,91,58,107,111,82,127,123};
int n,k,c[2020],dp[2020][2020],fr[2020][2020],bcnt[2020];
int main() {
	for(int i=0;i<200;i++)bcnt[i] = __builtin_popcount(i);
	memset(fr,7,sizeof(fr));
	read(n,k);
	for(int i=1;i<=n;i++){
		string cc;
		cin>>cc;
		for(int j=0;j<7;j++){
			c[i] = c[i]*2+cc[j]-'0';
		}
	}
	dp[1][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(!dp[i][j])continue;
			for(int ch=0;ch<10;ch++){
				if((a[ch]&c[i]) == c[i] && dp[i][j]*10+ch>dp[i+1][j+bcnt[a[ch]]-bcnt[c[i]]]){
					dp[i+1][j+bcnt[a[ch]]-bcnt[c[i]]] = dp[i][j]*10+ch;
					fr[i+1][j+bcnt[a[ch]]-bcnt[c[i]]] = ch;
				}
			}
		}
		vector<int> U;
		U.PB(0);
		for(int j=0;j<=k;j++)U.PB(dp[i+1][j]);
		sort(all(U));
		U.erase(unique(all(U)),U.end());
		for(int j=0;j<=k;j++)dp[i+1][j] = lower_bound(all(U),dp[i+1][j])-U.begin();
	}
	if(fr[n+1][k]<10000){
		string S;
		int cp = k;
		for(int i=n+1;i>1;i--){
			S+='0'+fr[i][cp];
			cp-=bcnt[a[fr[i][cp]]]-bcnt[c[i-1]];
		}
		reverse(all(S));
		cout<<S<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}