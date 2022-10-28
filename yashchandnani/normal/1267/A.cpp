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
ll t[200009];
ll en[200009];
ll ss[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	set<pair<ll,int>> s;
	ll st = 1e18;
	repA(i,1,n){
		ll a,b;cin>>a>>b>>t[i];
		st=min(st,a);
		ss[i] = a;
		en[i] = b;
		s.insert({a+t[i],-i});
		s.insert({b,i});
	}
	ll cnt=0;
	set<pair<ll,int>> swords;
	while(sz(s)){
		pair<ll,int> x = *(s.begin()),z;
		x.snd=-x.snd;
		s.erase(s.begin());
		if(x.snd<0){
			swords.erase({t[-x.snd],-x.snd});
		}
		else{
			z=mp(t[x.snd],x.snd);
			swords.insert(z);
			if(st<ss[x.snd]){
				st=ss[x.snd];
			}
		}
		if(sz(swords)==0) continue;
		ll nxt = s.begin()->fst;
		ll best = swords.begin()->fst;
		cnt+=(nxt-st)/best;
		st+=((nxt-st)/best)*best;
	}
	cout<<cnt;
	return 0;
}