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
bool vis[50009];
vector<pair<pii,pii>> v,v2,v3;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) {
		int x,y,z;cin>>x>>y>>z;
		v.pb(mp(mp(x,y),mp(z,i+1)));
	}
	sort(all(v));
	rep(i,n-1){
		if(!vis[i]){
			if(v[i].fst==v[i+1].fst){
				cout<<v[i].snd.snd<<' '<<v[i+1].snd.snd<<'\n';
				vis[i+1] = 1;
				vis[i] = 1;
			}
			else v2.pb(v[i]);
		}
	}
	if(!vis[n-1]) v2.pb(v[n-1]);
	if(sz(v2)==0) return 0;
	sort(all(v2));
	fill(vis);
	rep(i,sz(v2)-1){
		if(!vis[i]){
			if(v2[i].fst.fst==v2[i+1].fst.fst){
				cout<<v2[i].snd.snd<<' '<<v2[i+1].snd.snd<<'\n';
				vis[i]=vis[i+1] = 1;
			}
			else v3.pb(v2[i]);
		}
	}
	if(!vis[sz(v2)-1]) v3.pb(v2.back());
	if(sz(v3)==0) return 0;
	sort(all(v3));
	fill(vis);
	rep(i,sz(v3)-1){
		if(!vis[i]){
			cout<<v3[i].snd.snd<<' '<<v3[i+1].snd.snd<<'\n';
			vis[i+1] = vis[i] = 1;
		}
	}
	return 0;
}