#include <bits/stdc++.h>
using namespace std;

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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int D[1000009],cnt[1000009],a[1000009];
vi primes;
bool p[1000009];
void sieve(){
	repA(i,2,1000000){
		if(!p[i]){
			primes.pb(i);
			for(int j =i;j<=1000000;j+=i) p[j] = true;
		}
	}
}
void pre(){
	repA(i,1,1000000){
		for(int j = i;j<=1000000;j+=i) D[j]++;
	}
}
map<int,int> m;
struct FT {
		vector<ll> s;
		FT(int n) : s(n) {}
		void update(int pos, ll dif) { // a[pos] += dif
			for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
		}
		ll query(int pos) { // sum of values in [0, pos)
			ll res = 0;
			for (; pos > 0; pos &= pos - 1) res += s[pos-1];
			return res;
		}
};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	cnt[1] = 0;
	cnt[2] = 0;
	repA(i,3,1000000){
		cnt[i] = 1+cnt[D[i]];
	}
	int n,q;cin>>n>>q;
	FT tree(n+1);
	repA(i,1,n) {
		cin>>a[i];
		tree.update(i-1,a[i]);
		if(cnt[a[i]]) m[i]=cnt[a[i]];
	}
	rep(i,q){
		int t,l,r;cin>>t>>l>>r;
		if(t==1){
			auto it = m.lower_bound(l);
			vi vx,vx2;
			while(it!=m.end()&&it->fst<=r){
				int ix = it->fst;
				tree.update(ix-1,D[a[ix]]-a[ix]);
				a[ix] = D[a[ix]];
				if(m[ix]>1) vx2.pb(ix);
				else vx.pb(ix);
				it++;
			}
			trav(ix,vx) m.erase(ix);
			trav(ix,vx2) m[ix]--;
		}
		else{
			ll ans = tree.query(r)-tree.query(l-1);
			cout<<ans<<endl;
		}
	}
	return 0;
}