#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cerr << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
#define mp make_pair
#define set0(x) memset(x,0,sizeof(x))

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

vector<int> z(string s) {
	int n = s.size();
	vector<int> z(n);
	int x = 0, y = 0;
	for (int i = 1; i < n; i++) {
		z[i] = max(0,min(z[i-x],y-i+1));
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
			x = i; y = i+z[i]; z[i]++;
		}
	}
	return z;
}

struct fenwick_tree{
	ll c[1000010] = {0};
	inline void add(ll x, ll y){
		while (x <= 1000010){
			c[x]+=y;
			x += x & -x;
		}
	}
	inline ll sum(ll x){
		ll res = 0;
		while (x > 0){
			res +=c[x];
			x -= x & -x;
		}
		return res;
	}
}A,B;

void add(int l,int r,int k){
	A.add(l,k);
	A.add(r+1,-k);
	B.add(l,-(l-1)*k);
	B.add(r+1,r*k);
}

ll query(ll p){
	return A.sum(p)*p+B.sum(p);
}

string a,b,c;

vector<pair<pii,int>> S[500050];
int main() {
	int n,m;
	cin>>n>>m;
	cin>>a>>b>>c;
	string d = c+a;
	reverse(c.begin(),c.end());
	reverse(b.begin(),b.end());
	string e = c+b;
	//cout<<n<<' '<<m<<endl;
	vector<int> z1 = z(d),z2 = z(e);
	for(int i=m;i<m+n;i++){
		//cout<<z2[i]<<endl;
		int cc = z2[i];
		if(z2[i]){
			int j = n-1-(i-m);
			S[max(0,j-m+2)].push_back(mp(mp(max(m-z2[i],1),m-1),1));
			S[j+1].push_back(mp(mp(max(m-z2[i],1),m-1),-1));
		}
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		//cout<<ans<<' '<<i<<endl;
		for(auto ct:S[i]){
			debug(ct);
			add(ct.first.first,ct.first.second,ct.second);
		}
		if(z1[i+m]){
			debug(z1[i+m]);
			ans+=query(z1[i+m]);
		}
	}
	cout<<ans<<endl;
	return 0;
}