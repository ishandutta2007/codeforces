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

void solve(){


}
bool query(int j,int k){
	cout<<2<<' '<<1<<' '<<j<<' '<<k<<endl;
	int x;cin>>x;
	if(x==1) return 1;
	else return 0;
}
ll q(int j,int k){
	cout<<1<<' '<<1<<' '<<j<<' '<<k<<endl;
	ll x;cin>>x;
	return x;
}
int ans[1009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int ix = 2;
	repA(i,3,n){
		if(query(i,ix)) ix=i;	
	}
	vector<pair<ll,int>> v;
	repA(i,2,n){
		if(i!=ix){
			v.pb(mp(q(ix,i),i));
		}
	}
	v.pb({0,ix});
	sort(all(v));
	vi v1,v2;
	int gg = v.back().snd;
	v.pop_back();
	trav(i,v){
		if(query(i.snd,gg)) v1.pb(i.snd);
		else v2.pb(i.snd);
	}
	v2.pb(gg);
	reverse(all(v2));
	cout<<0<<' '<<1<<' ';
	trav(i,v1) cout<<i<<' ';
	trav(i,v2) cout<<i<<' ';
	cout<<endl;
	return 0;
}