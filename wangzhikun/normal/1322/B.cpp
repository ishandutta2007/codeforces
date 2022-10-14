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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

int n,a[400040];

struct fenwick_tree{
	bool c[20000030];
	inline void add(int x){
		x+=1;
		while (x <= 20000030){
			c[x]^=1;
			x += x & -x;
		}
	}
	inline bool sum(int x){
		x+=1;
		bool res = 0;
		while (x > 0){
			res ^=c[x];
			x -= x & -x;
		}
		return res;
	}
}T[2];
int main() {
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	int ans = 0;
	for(int l=1;l<=2e7;l*=2){
		set0(T[0].c);
		set0(T[1].c);
		int cnt[2] = {0};
		for(int j=1;j<=n;j++){
			int cmod = a[j]%(l*2)/l,cm2 = a[j]%l;
			T[cmod].add(cm2);
			cnt[cmod]+=1;
		}
		ll tot[2] = {0,0};
		for(int j=1;j<=n;j++){
			int cmod = a[j]%(l*2)/l,cm2 = a[j]%l;
			T[cmod].add(cm2);
			cnt[cmod]-=1;
			int cn00 = T[0].sum(l-cm2-1),cn01 = cnt[0]-cn00;
			int cn10 = T[1].sum(l-cm2-1),cn11 = cnt[1]-cn10;
			//debug(l,j,cn00,cn01,cn10,cn11);
			tot[cmod]+=cn00+cn11;
			tot[cmod^1]+=cn01+cn10;
		}
		if(tot[1]%2 == 1){
			ans^=l;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
	Do something instead of doing nothing and stay organized
	Check n == 1, array size , -fsanitize=address, -Wshadow
	Whenever stuck for 15 minutes take a break out
	Think twice, code ONCE!
*/