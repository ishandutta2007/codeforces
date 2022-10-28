#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
int jj=0;
void query(int i,int j,string& s){
	cout<<i+1<<' '<<j+1<<'\n';
	string t = s.substr(i,j-i+1);
	reverse(all(t));
	s=s.substr(0,i)+t+s.substr(j+1,sz(s)-j-1);
	jj++;
}
void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	cout<<n<<'\n';
	jj=0;
	rep(i,n/2-k+1){
		repA(j,jj,n-1){
			if(s[j]=='('){
				query(jj,j,s);
				break;
			}
		}
	}
	rep(i,n/2-k+1){
		repA(j,jj,n-1){
			if(s[j]==')'){
				query(jj,j,s);
				break;
			}
		}
	}
	rep(i,k-1){
		repA(j,jj,n-1){
			if(s[j]=='('){
				query(jj,j,s);
				break;
			}
		}
		repA(j,jj,n-1){
			if(s[j]==')'){
				query(jj,j,s);
				break;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	return 0;
}