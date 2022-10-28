#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
#define int ll
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
vector<pii> ans;
const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	int	cnt1=0,cnt2=0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if(x>0) cnt1=1;
			else cnt2 = 1;
		}
		else {
			if(!l) {
				int mid = lo + (hi-lo)/2;
				l = new Node(lo,mid), r = new Node(mid,hi);
			}	
			l->set(L, R, x), r->set(L, R, x);
			cnt1 = r->cnt1+l->cnt1;
			cnt2 = r->cnt2+l->cnt2;
		}
	}
	void query(){
		if(cnt1==0){
			if(cnt2==0) return;
			else {
				ans.pb(mp(lo,hi));
			}
		}
		else{
			if(l) l->query();
			if(r) r->query();
		}
	}
};
pii parse(string s){
	int x = 0;
	int v = 0;
	int fg = 0;
	trav(i,s){
		if(i=='.') (x+=v),x*=256,v=0;
		else if(i=='/'){
			x+=v;
			v=0;
			fg = 1;
		}
		else {
			v = 10*v +(i-'0');
		}
	}
	if(fg) return mp(x,32-v);
	else return mp(x+v,0);
}
template <class T>
auto addInterval(set<pair<T, T>>& is, T L, T R) {
	if (L == R) return is.end();
	auto it = is.lower_bound({L, R}), before = it;
	while (it != is.end() && it->first <= R) {
		R = max(R, it->second);
		before = it = is.erase(it);
	}
	if (it != is.begin() && (--it)->second >= L) {
		L = min(L, it->first);
		R = max(R, it->second);
		is.erase(it);
	}
	return is.insert(before, {L,R});
};
void pr(pii u){
	pii v = mp(u.fst,0);
	repD(i,32,0){
		if(u.snd-u.fst==1ll<<i) v.snd = i;
	}
	int z = 256*256*256;
	rep(i,4){
		cout<<v.fst/z;
		if(i!=3) cout<<'.';
		v.fst%=z;
		z/=256;
	}
	cout<<'/';
	cout<<32-v.snd<<'\n';
}
set<pii> s1,s2;
signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	ll m = 1ll<<32;
	rep(i,n){
		string s;cin>>s;
		pii x = parse(s.substr(1,sz(s)-1));
		if(s[0]=='+'){
			addInterval(s1,x.fst,x.fst+(1ll<<x.snd));
		}
		else {
			addInterval(s2,x.fst,x.fst+(1ll<<x.snd));
		}
	}
	vector<pair<pii,int>> v;
	trav(i,s1) v.pb(mp(i,1));
	trav(i,s2) v.pb(mp(i,-1));
	sort(all(v));
	rep(i,sz(v)-1){
		if(v[i].fst.snd>v[i+1].fst.fst) {
			cout<<-1;
			exit(0);
		}
	}
	Node N(0,1ll<<32);
	trav(i,v) N.set(i.fst.fst,i.fst.snd,i.snd);
	N.query();
	cout<<sz(ans)<<'\n';
	trav(i,ans) pr(i);
	return 0;
}