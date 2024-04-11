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
const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, madd = 0, val = 0;
	Node(int lo=0,int hi=1e9+7):lo(lo),hi(hi){} // Large interval of -inf
	int query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		int ll=0,rr=0;
		if(l) ll = l->query(L,R);
		if(r) rr = r->query(L,R);
		return (ll+rr);
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			val += x;
		}
		else {
			push();l->add(L, R, x), r->add(L, R, x);
			val = l->val+r->val;
		}
	}
	void push() {
				if (!r) {
								int mid = lo + (hi - lo)/2;
											r = new Node(mid,hi); 					}
				if (!l) {
								int mid = lo + (hi - lo)/2;
											l = new Node(lo, mid); 					}
	}
};
int k;
Node N[2000029];
void add(int x,int q){
	N[q].add(x,x+1,1);
}
void del(int x,int q){
	N[q].add(x,x+1,-1);
}
ll query(int x1,int x2,int q){
	x1 = max(x1,0);
	x2 = min(x2,(int)(1e9+3));
	ll ans =0;
	repA(i,max(0,q-k),q+k){
		ans+=N[i].query(x1,x2+1);
	}
	return ans;
}
ll solve(vector<pair<pii,int>>& v){
	int q = v[0].fst.fst;
	trav(i,v) swap(i.fst.fst,i.fst.snd);
	sort(all(v));
	ll ans = 0;
	repD(i,sz(v)-1,0){
		ans+=query(v[i].snd-v[i].fst.fst,v[i].snd+v[i].fst.fst,v[i].fst.snd-q);
		add(v[i].snd,v[i].fst.snd-q);
	}
	rep(i,sz(v)){
		del(v[i].snd,v[i].fst.snd-q);
	}
	return ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n>>k;
	vector<pair<pii,int>> v(n);
	rep(i,n){
		cin>>v[i].snd>>v[i].fst.snd>>v[i].fst.fst;
	}
	sort(all(v));
	int st = 0;
	ll ans = 0;
	rep(i,n){
		st = i;
		while(i+1<n&&v[i+1].fst.fst-k<=v[i].fst.fst) i++;
		vector<pair<pii,int>> u(v.begin()+st,v.begin()+i+1);
		ans+=solve(u);
	}
	cout<<ans;
	return 0;
}