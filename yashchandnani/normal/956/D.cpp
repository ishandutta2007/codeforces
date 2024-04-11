#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx,avx2")
#pragma GCC Optimize ("Ofast")
#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
	  	  tree_order_statistics_node_update>;

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
typedef double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ld, ld> pii;
typedef vector<int> vi;
map<ld,int> val;
int ss[100009];
ll ans;
vi inv(int l,int r){
	if(l==r) {
		vi a;a.pb(ss[l]);
		return a;
	}
	int m = (l+r)/2;
	vi a=inv(l,m);
	vi b=inv(m+1,r);
	vi c;
	int cnt  = 0;
	while(!a.empty()&&!b.empty()){
		if(a.back()>=b.back()) {
			c.pb(a.back());a.pop_back();
			cnt++;
		}
		else{
			ans+=cnt;
			c.pb(b.back());b.pop_back();
		}
	}
	while(!a.empty()){
			c.pb(a.back());a.pop_back();
			cnt++;
	}
	while(!b.empty()){
			ans+=cnt;
			c.pb(b.back());b.pop_back();
	}
	reverse(all(c));
	return c;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;ld w;cin>>n>>w;
	vector<pii> itr;
	set<ld> al;
	rep(i,n){
	    int xx,vv;
		ld x,v;cin>>xx>>vv;
		x=xx;v=vv;
		itr.pb(mp(abs(x/(v-w)),-abs(x/(v+w))));
		al.insert(abs(x/(v-w)));al.insert(abs(x/(v+w)));
	}
	int cnt = 0;
	trav(i,al){
		cnt++;
		val[i] = cnt;
	}
	sort(all(itr));
	int j = 0;
	trav(i,itr){
		ss[j] = (val[-i.snd]);j++;
	}
	inv(0,j-1);

	cout<<ans;
	return 0;
}