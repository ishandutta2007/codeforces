#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cerr << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

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

int n,k;
string s;

int val;
vector<int> G[300030],V[300030],id[300030];

int bcj[300030],cnt[300030][2],sz[300030][2];
map<int,int> vld[300030][2];

int fnd(int x){
	return x == bcj[x]?x:bcj[x] = fnd(bcj[x]);
}

int calc(int x){
	//cout<<sz[x][0]<<' '<<sz[x][1]<<' '<<cnt[x][0]<<' '<<cnt[x][1]<<endl;
	if(sz[x][0]<sz[x][1])return cnt[x][1];
	if(sz[x][0]>sz[x][1])return cnt[x][0];
	return min(cnt[x][1],cnt[x][0]);
}

int main() {
	read(n,k);
	cin>>s;
	for(int i=1;i<=k;i++){
		int c,cc;
		read(c);
		while(c--){
			read(cc);
			V[cc].push_back(i);
		}
		bcj[i] = i;
		vld[i][1][i] = 1;
		vld[i][0][i] = 0;
		cnt[i][1] = 1;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		int cstate = s[i-1]-'0';
		if(V[i].size() == 0){
			cout<<ans<<"\n";
			continue;
		}
		if(V[i].size() == 1){
			int oc = V[i][0];
			int cv = fnd(oc),creq = cstate^1;
			ans-=calc(cv);
			int cho = (vld[cv][1][oc] == creq);
			sz[cv][cho]+=1;
			ans+=calc(cv);
			cout<<ans<<"\n";
			continue;
		}
		if(V[i].size() == 2){
			int c1 = V[i][0],c2 = V[i][1];
			if(fnd(c1) != fnd(c2)){
				//cout<<c1<<' '<<c2<<endl;
				int a1 = fnd(c1),a2 = fnd(c2);
				ans-=calc(a1);
				ans-=calc(a2);
				if(vld[a1][0].size()<vld[a2][0].size()){
					swap(a1,a2);
					swap(c1,c2);
				}
				int on1 = (vld[a1][1][c1] == 1),on2 = (vld[a2][1][c2] == 1);
				if(cstate == 1) on2^=1;
				
				sz[a1][on1]+=sz[a2][on2^1];
				sz[a1][on1^1]+=sz[a2][on2];
				cnt[a1][on1]+=cnt[a2][on2^1];
				cnt[a1][on1^1]+=cnt[a2][on2];
				for(auto ct:vld[a2][on2^1]) vld[a1][on1][ct.first] = ct.second;
				for(auto ct:vld[a2][on2]) vld[a1][on1^1][ct.first] = ct.second;
				bcj[a2] = a1;
				//cout<<"! ";cout<<a1<<' '<<a2<<' '<<on1<<' '<<on2<<endl;
				//cout<<"! ";
				ans+=calc(a1);
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}