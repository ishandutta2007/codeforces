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

int T,h,g;
const int N = (1<<21)+10;
int a[N],ans[N],cpo[N];
vector<int> Q[N];
int main() {
	read(T);
	while(T--){
		read(h,g);
		for(int i=1;i<1<<h;i++){
			read(a[i]);ans[a[i]] = 0;
			Q[i].clear();Q[i].PB(a[i]);
			cpo[i] = 0;
		}
		ll ans0 = 0;
		for(int i = (1<<h)-1;i>=1;i--){
			if(i<(1<<g)){
				int cl = (i*2<(1<<g))?max(cpo[i*2],cpo[i*2+1]):0;
				vector<int> nQ;
				int mi = 1e9;
				for(auto ct:Q[i]){
					if(ct>=cl){
						mi = min(mi,ct);
						
					}
				}
				for(auto ct:Q[i]){
					if(ct>mi){
						
						nQ.PB(ct);
					}
				}
				Q[i] = nQ;
				ans[mi] = 1;
				cpo[i] = mi;
				ans0+=cpo[i];
			}
			if(i/2) for(auto ct:Q[i])Q[i/2].push_back(ct);
			Q[i].clear();
		}
		cout<<ans0<<"\n";
		vector<int> ops;
		for(int i=(1<<h)-1;i>=1;i--)
			if(!ans[a[i]]) ops.push_back(i);
		for(int i=0;i<(1<<h)-(1<<g);i++)
			cout<<ops[i]<<" \n"[i == ((1<<h)-(1<<g)-1)];
		for(int i=1;i<1<<h;i++){
			ans[a[i]] = 0;
			Q[i].clear();
			cpo[i] = 0;
		}
	}
	return 0;
}