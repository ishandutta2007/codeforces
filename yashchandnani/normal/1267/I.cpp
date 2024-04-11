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
char x[209][209];
bool q(int i,int j){
	if(x[i][j]) return x[i][j]=='>';
	cout<<"? "<<i<<' '<<j<<endl;
	cin>>x[i][j];
	return x[i][j]=='>';
}
bool cmpx(int l,int r){
	return q(l,r);
}
bool cmp(pii l,pii r){
	return q(l.snd,r.snd);
}
void solve(){
	fill(x);
	int n;cin>>n;
	vector<pii> v;
	repA(i,1,n) {
		if(!q(i,i+n)){
			v.pb({i+n,i});
		}
		else v.pb({i,i+n});
	}
	sort(all(v),cmp);
	if(q(v[2].fst,v[1].fst)) swap(v[1],v[2]);
	vi gg;
	repA(i,2,n-1) gg.pb(v[i].fst);
	rep(i,n) gg.pb(v[i].snd);
	sort(all(gg),cmpx);
	cout<<"!"<<endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) solve();	
	
	return 0;
}