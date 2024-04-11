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
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
int n,k;

bitset<3020> moves;
string S;

int main() {
	read(n);read(k);
	cin>>S;
	int potent = 0,cu = 0;
	for(int i=0;i<S.length()-1;i++){
		if(S[i] == 'R' && S[i+1] == 'L')moves[i] = 1;
	}
	for(int i=0;i<S.length();i++){
		if(S[i] == 'R')cu+=1;
		else potent+=cu;
	}
	if(k>potent){
		cout<<-1<<endl;
	}else{
		vector<vector<int>> ans;
		while(k--){
			vector<int> chk;
			vector<int> cu;
			if(potent == k+1){
				for(auto ev:ans){
					putnum(ev.size());
					for(auto ct:ev){
						putchar(' ');
						putnum(ct+1);
					}putchar('\n');
				}
				int p = -1;
				for(int j=0;j<=k;j++){
					if(!(p>=0 && S[p] == 'R' && S[p+1] == 'L')){
						for(int j=0;j<n-1;j++){
							if(S[j] == 'R' && S[j+1] == 'L'){
								p = j;
								break;
							}
						}
					}
					cout<<1<<' '<<p+1<<"\n";
					swap(S[p],S[p+1]);
					p--;
				}
				return 0;
			}
			while(potent>k && moves.count()){
				int a = moves._Find_first();
				moves[a] = 0;
				chk.PB(a-1); chk.PB(a); chk.PB(a+1);
				cu.PB(a);
				swap(S[a],S[a+1]);
				potent--;
			}
			ans.PB(cu);
			for(auto ct:chk){
				if(ct<0)continue;
				if(S[ct] == 'R' && S[ct+1] == 'L')moves[ct] = 1;
				else moves[ct] = 0;
			}
		}
		if(potent == 0){
			for(auto ev:ans){
				putnum(ev.size());
				for(auto ct:ev){
					putchar(' ');
					putnum(ct+1);
				}putchar('\n');
			}
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}