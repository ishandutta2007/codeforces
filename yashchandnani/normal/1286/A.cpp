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
int p[100];
int vis[109];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) {
		cin>>p[i];
		vis[p[i]]=1;
	}
	vector<pii> v;
	rep(i,n) if(p[i]) p[i]=p[i]%2+2;
	v.pb(mp(p[0],1));
	repA(i,1,n-1){
		if(p[i]==p[i-1]) v.back().snd++;
		else v.pb(mp(p[i],1));
	}
	if(sz(v)==1){
		if(p[0]==0) {
			if(n==1) cout<<0;
			else cout<<1;
		}
		else cout<<0;
		return 0;
	}
	vi cnt[2];
	int fns = 0;
	rep(i,sz(v)){
		if(v[i].fst==0){
			if(i==0) ;
			else if(i==sz(v)-1) ;
			else if(v[i-1].fst%2==v[i+1].fst%2) cnt[v[i-1].fst%2].pb(v[i].snd);
			else fns++;
		}
		else if(i!=sz(v)-1&&v[i+1].fst!=0&&v[i].fst!=v[i+1].fst){
			fns++;
		}
	}
	int val[2];
	val[0]=val[1]=0;
	repA(i,1,n) if(!vis[i]) val[i%2]++;
	sort(all(cnt[0]));
	sort(all(cnt[1]));
	reverse(all(cnt[0]));
	reverse(all(cnt[1]));
	int gns = n;
	int st[2];
	st[0]=val[0],st[1] = val[1];
	vi gg1=cnt[0],gg2=cnt[1];
	int cns = fns;
	rep(q,4){
		val[0]=st[0];
		val[1] = st[1];
		cnt[0] = gg1;
		cnt[1] = gg2;
		fns=cns;
		if(v[sz(v)-1].fst==0){
			if(q&2){
				if(val[v[sz(v)-2].fst%2]>=v[sz(v)-1].snd){
					val[v[sz(v)-2].fst%2]-=v[sz(v)-1].snd;
				}
				else fns++;
			}
			else fns++;
		}
		if(v[0].fst==0){
			if(q&1){
				if(val[v[1].fst%2]>=v[0].snd){
					val[v[1].fst%2]-=v[0].snd;
				}
				else fns++;
			}
			else fns++;
		}
		while(sz(cnt[1])&&cnt[1].back()<=val[1]) {
			val[1]-=cnt[1].back();
			cnt[1].pop_back();
		}
		while(sz(cnt[0])&&cnt[0].back()<=val[0]) {
			val[0]-=cnt[0].back();
			cnt[0].pop_back();
		}
		gns=min(gns,fns+2*(sz(cnt[0])+sz(cnt[1])));
	}
	cout<<gns;
	return 0;
}