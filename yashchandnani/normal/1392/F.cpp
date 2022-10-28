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
ll h[1000009];
ll ans[1000009];
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	ll madd = 0, val = 0;
	Node(int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		else val = 0;
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};
struct FT {
	vector<ll> s;
	FT(int n) : s(n+7,0ll) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	void add(int l,int r,ll x){
		update(l,x);
		update(r,-x);
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n){
		cin>>h[i];
	}
	FT N(n);
	vi v;
	v.pb(0);
	N.add(0,1,h[0]);
	repA(i,1,n-1){
		ll lst = N.query(i);
		bool fg=0;
		while(sz(v)>1){
			int j = v.back();
			int l = i-j;
			if(h[i]-l>=lst+1) {
				N.add(j,i,1);
				lst++;
				h[i]-=l;
				v.pop_back();
				continue;
			}
			else{
				fg=1;
				if(h[i]==lst){
					v.pb(i);
				}
				else if(h[i]==lst+1){
					
				}
				else{
					ll x = h[i]-lst-1;
					N.add(j,j+x,1);
					v.pop_back();
					v.pb(j+x);
					h[i]=lst+1;
				}
				N.add(i,i+1,h[i]);
				break;
			}
		}
		if(!fg){
			ll lo = 0,hi = h[i]-lst-1;
			while(lo<hi){
				ll mid = (lo+hi)/2;mid++;
				if(mid%i!=0){
					if(lst+mid/i<h[i]-mid){
						lo=mid;
					}
					else hi=mid-1;
				}
				if(mid%i==0){
					if(lst+mid/i<=h[i]-mid){
						lo=mid;
					}
					else hi=mid-1;
				}
			}
			h[i]-=lo;
			lst+=lo/i;
			N.add(0,i,lo/i);
			if(lo%i!=0){
				N.add(0,lo%i,1);
				v.pb(lo%i);
			}
			N.add(i,i+1,h[i]);
			if(h[i]==lst) v.pb(i);
		}
	}
	rep(i,n) cout<<N.query(i+1)<<' ';
	return 0;
}