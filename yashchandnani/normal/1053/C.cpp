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
const ll mod = 1e9+7;
struct FT {
		vector<ll> s;
			FT(int n) : s(n,0) {}
				void update(int pos, ll dif) { // a[pos] += dif
							for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
								}
					ll query(int pos) { // sum of values in [0, pos)
								ll res = 0;
										for (; pos > 0; pos &= pos - 1) res += s[pos-1];
												return res;
													}
};
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	ll madd = 0, val = 0,d;
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			d = (l->d+ r->d)%mod;
		}
		else if(lo+1==hi) d = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return (l->query(L, R)+r->query(L, R))%mod;
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			val += x%mod*d%mod;
			madd%=mod;
			val%=mod;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = (l->val+ r->val)%mod;
		}
	}
	void push() {
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0,val = (l->val+r->val)%mod;
	}
};
ll a[200009],w[200009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,q;cin>>n>>q;
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>w[i];
	FT T1(n+3),T2(n+3),T3(n+3),T4(n+3);
	ll sum = 0;
	vi d(n-1);
	rep(i,n-1) d[i] = a[i+1]-a[i]-1,T4.update(i,d[i]);
	Node N1(d,0,n-1),N2(d,0,n-1);
	rep(i,n-1){
		sum+=w[i];
		sum%=mod;
		T1.update(i,1ll*(a[i+1]-a[i]-1)*sum%mod);
	}
	sum = 0;
	repD(i,n-2,0){
		sum+=w[i+1];
		sum%=mod;
		T2.update(i,1ll*(a[i+1]-a[i]-1)*sum%mod);
	}
	rep(i,n){
		T3.update(i,w[i]);
	}
	rep(i,q){
		int l,r;cin>>l>>r;
		if(l<0){
			int ix = -l;ix--;
			ll dif = r - w[ix];
			dif%=mod;
			T3.update(ix,r-w[ix]);
			w[ix] = r;
			if(ix>0){
				N2.add(0,ix,dif);
			}
			if(ix<n-1){
				N1.add(ix,n,dif);
			}
		}
		else{
			l--,r--;
			int lo = l,hi = r;
			while(lo<hi){
				int m = (lo+hi)/2;
				if(T3.query(r+1)-T3.query(m+1)>=T3.query(m+1)-T3.query(l)){
					lo =m+1;
				}
				else hi = m;
			}
			ll ans = T2.query(r)-T2.query(lo)+T1.query(lo)-T1.query(l)-(T4.query(lo)-T4.query(l))%mod*(T3.query(l)%mod)%mod - (T4.query(r)-T4.query(lo))%mod*((T3.query(n)-T3.query(r+1))%mod)%mod;
			ans += N1.query(l,lo)+N2.query(lo,r);
			ans = (ans%mod+mod)%mod;
			cout<<ans<<'\n';
		}
	}
	return 0;
}