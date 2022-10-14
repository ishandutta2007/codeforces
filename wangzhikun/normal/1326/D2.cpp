#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cerr << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
#define endl "\n"
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
typedef vector<int> vi;
array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

int T;
string S;
int main() {
	read(T);
	while(T--){
		cin>>S;
		int n = S.length();
		int mi = 0,mj = n-1;
		while(S[mi] == S[mj] && mi<n){
			mi++;mj--;
		}
		if(mi == n){
			cout<<S<<"\n";
			continue;
		}
		int mans = -1,mpo = -1,mtyp = -1;
		array<vi, 2> cu = manacher(S);
		for(int i=0;i<n;i++){
			int ctyp = 0,cr = i+cu[0][i]-1,cl = i-cu[0][i];
			if(mi>=min(cl,n-1-cr) && cu[0][i]*2+min(cl,n-1-cr)*2>mans){
				mans = cu[0][i]*2+min(cl,n-1-cr)*2;
				mpo = i;
				mtyp = ctyp;
			}
			ctyp = 1;cr = i+cu[1][i],cl = i-cu[1][i];
			if(mi>=min(cl,n-1-cr) && 1+cu[1][i]*2+min(cl,n-1-cr)*2>mans){
				mans = 1+cu[1][i]*2+min(cl,n-1-cr)*2;
				mpo = i;
				mtyp = ctyp;
			}
		}
		if(mtyp == 0){
			int i = mpo;
			int cr = i+cu[0][i]-1,cl = i-cu[0][i];
			int cdst = min(cl,n-1-cr);
			for(int j=0;j<n;j++){
				if(j<cdst || n-1-j<cdst || (j>=cl && j<=cr))cout<<S[j];
			}
			cout<<endl;
		}
		if(mtyp == 1){
			int i = mpo;
			int cr = i+cu[1][i],cl = i-cu[1][i];
			int cdst = min(cl,n-1-cr);
			for(int j=0;j<n;j++){
				if(j<cdst || n-1-j<cdst || (j>=cl && j<=cr))cout<<S[j];
			}
			cout<<endl;
		}
		if(mtyp == -1)cout<<S[0]<<endl;
	}
	return 0;
}