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

ll gcd(ll a,ll b){
	return b == 0 ? a : gcd(b,a%b);
}
int n,m,u,v;
vector<int> G[500050],G2[500050];
ll a[500050];
ll get(int n){
	ll ret = 0;
	trav(ct,G[n])ret+=a[ct];
	return ret;
}
map<pii,ll> Mp;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
void solve(){
	read(n,m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	rep(i,1,m+1){
		read(u,v);
		G[u].PB(v);
		G2[v].PB(u);
	}
	ll g = get(1);
	rep(i,1,n+1)g = gcd(g,get(i));
	int b = rnd()%50000000+50000000;
	rep(i,1,n+1){
		int c1 = 1,c2 = 1;
		if(G2[i].size() == 0)continue;
		sort(all(G2[i]));
		trav(ct,G2[i]){
			c1 = (1ll*c1*19260817+ct)%998244353;
			c2 = (1ll*c2*b+ct)%1000000007;
		}
		Mp[MP(c1,c2)]+=a[i];
	}
	trav(ct,Mp){
		g = gcd(g,ct.second);
	}
	rep(i,1,n+1){
		G[i].clear();
		G2[i].clear();
	}
	Mp.clear();
	cout<<g<<"\n";
}
int T;
int main() {
	read(T);
	while(T--){
		solve();
	}
	return 0;
}
/*
	Do something instead of doing nothing and stay organized
	Check n == 1, array size , -fsanitize=address, -Wshadow
	Whenever stuck for 15 minutes take a break out
	Think twice, code ONCE!
*/