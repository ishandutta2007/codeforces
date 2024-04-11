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
int l[1009],r[1009],t[1009];
int ans[1009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n){
		cin>>l[i];
		t[i]+=l[i];
	}
	rep(i,n) {
		cin>>r[i];
		t[i]+=r[i];
	}
	vector<pii> v;
	rep(i,n) v.pb(mp(t[i],i));
	sort(all(v));
	ans[v[0].snd] = n;
	repA(i,1,n-1){
		if(v[i].fst==v[i-1].fst) ans[v[i].snd] = ans[v[i-1].snd];
		else ans[v[i].snd] = ans[v[i-1].snd]-1;
	}
	rep(i,n){
		int c1=0,c2=0;
		rep(j,i) if(ans[j]>ans[i]) c1++;
		repA(j,i+1,n-1) if(ans[j]>ans[i]) c2++;
		if(c1!=l[i]||c2!=r[i]) {
			cout<<"NO";
			exit(0);
		}
	}
	cout<<"YES\n";
	rep(i,n) cout<<ans[i]<<' ';
	return 0;
}