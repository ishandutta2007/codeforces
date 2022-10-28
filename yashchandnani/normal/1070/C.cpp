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
int k;
const int inf = 1e18+7;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi,  madd = 0,cnt=1,mn=0,smn=-inf;
	ll val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			cnt = l->cnt+r->cnt;
		}
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R)+r->query(L, R);
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L ) return;
		if ((L <= lo && hi <= R&&smn+x<k)||(lo+1>=hi)) {
			madd += x;
			if(mn+x<=k) val += 1ll*x*(hi-lo),mn+=x;
			else val+=1ll*x*(hi-lo-cnt)+1ll*(k-mn)*cnt,mn=k;
			if(smn!=-inf) smn+=x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			mn = max(l->mn,r->mn);
			smn = max(l->smn,r->smn);
			cnt =0;
			if(mn==r->mn) cnt+=r->cnt;
			else smn = max(smn,r->mn);
			if(mn==l->mn) cnt+=l->cnt;
			else smn = max(smn,l->mn);
			val = l->val+r->val;
		}
	}
	void push() {
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};
vector<pair<pii,pii>> v;
vi xx;
signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>k>>m;
	rep(i,m){
		int l,r,c,p;cin>>l>>r>>c>>p;
		v.pb(mp(mp(p,c),mp(l,r)));
	}
	xx.resize(n,0);
	Node T(xx,0,n);
	sort(all(v));
	ll ans =0;
	trav(i,v){
		ll sum = T.query(i.snd.fst-1,i.snd.snd);
		T.add(i.snd.fst-1,i.snd.snd,i.fst.snd);
		ll sum2 = T.query(i.snd.fst-1,i.snd.snd);
		ans+=1ll*(sum2 - sum)*i.fst.fst;
	}
	cout<<ans;	
	return 0;
}