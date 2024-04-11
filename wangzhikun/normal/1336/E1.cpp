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
typedef vector<int> VI;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

int mod = 998244353,inv2 = (mod+1)/2;
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}

int n,m;
ll a[200020],b[60],v[60],vn = 0;
int cnt[60],C[61][61];

void dfs(ll cv,int len){
	if(len == vn){
		++cnt[__builtin_popcountll(cv)];
		return;
	}
	dfs(cv,len+1);
	dfs(cv^v[len],len+1);
}

int main() {
	read(n,m);
	C[0][0] = 1;
	for(int i=1;i<=60;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)C[i][j] = add(C[i-1][j],C[i-1][j-1]);
	}
	for(int i=0;i<n;i++){
		read(a[i]);
		ll cc = a[i];
		for(int j=m-1;j>=0;j--){
			if(b[j])cc = min(cc,cc^b[j]);
			else if((cc>>j)&1){
				b[j] = v[vn++] = cc;
				break;
			}
		}
	}
	for(int j=0;j<m;j++){
		for(int k=j+1;k<m;k++)if((b[k]>>j)&1)b[k]^=b[j];
	}
	if(vn<m/2){
		dfs(0,0);
		for(int i=0;i<=m;i++)
			cout<<mul(cnt[i],mpow(2,n-vn))<<" \n"[i == m];
		return 0;
	}
	vn = 0;
	for(int i=0;i<m;i++){
		if(!b[i]){
			ll cv = 1ll<<i;
			for(int j=i+1;j<m;j++)if((b[j]>>i)&1)cv|=1ll<<j;
			v[vn++] = cv;
		}
	}
	dfs(0,0);
	int ans[61] = {0};
	for(int i=0;i<=m;i++){
		int cv[61] = {0};
		for(int j=0;j<=i;j++){
			for(int k=0;k<=m-i;k++){
				if(j&1)cv[j+k] = sub(cv[j+k],mul(C[i][j],C[m-i][k]));
				else cv[j+k] = add(cv[j+k],mul(C[i][j],C[m-i][k]));
			}
		}
		for(int j=0;j<=m;j++){
			ans[j] = add(ans[j],mul(mul(cv[j],cnt[i]),mul(mpow(2,n-m+vn),mpow(inv2,vn))));
		}
	}
	for(int j=0;j<=m;j++){
		cout<<ans[j]<<" \n"[j == m];
	}
	return 0;
}