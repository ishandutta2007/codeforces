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
#define int ll
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
vector<pii> v2;
queue<int> gg1,gg2;
int fns[1000009];
void solve(int st){
	int a = st;
	repA(i,a,a+sz(v2)/2-1){
		if(v2[i].snd>0){
			if(sz(gg2)){
				fns[v2[i].snd]=-gg2.front();
				gg2.pop();
			}
			else gg1.push(v2[i].snd);
		}
		else{
			if(sz(gg1)){
				fns[gg1.front()]=-v2[i].snd;
				gg1.pop();
			}
			else gg2.push(v2[i].snd);
		}
	}
	repA(i,1,sz(v2)/4){
		cout<<fns[i]<<' ';
	}
}
int lst[1000009];
ll s[1000009];
int t[1000009];
map<int,ll> ml[1000009];
ll ex[1000009];
int id[1000009];
ll val[1000009];
signed main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int m,n;cin>>m>>n;
	map<int,int> mx;
	vector<pii> v;
	rep(i,n){
		int x;cin>>x;
		v.pb(mp(x,i+1));
		v.pb(mp(x+m,i+1));
		v2.pb(mp(x,i+1));
		v2.pb(mp(x+m,i+1));
	}
	rep(i,n){
		int x;cin>>x;
		v.pb(mp(x,-(i+1)));
		v.pb(mp(x+m,-(i+1)));
		v2.pb(mp(x,-(i+1)));
		v2.pb(mp(x+m,-(i+1)));
	}
	sort(all(v2));
	sort(all(v));
	ll cur = 0;
	int ix=500000;
	memset(lst,-1,sizeof(lst));
	rep(i,sz(v)){
		s[i] = cur;
		t[i] = lst[ix];
		lst[ix] = i;
		if(v[i].snd>0) ix++,cur+=v[i].fst;
		else ix--,cur-=v[i].fst;
	}
	s[sz(v)] = cur;
	t[sz(v)]=lst[ix];
	ll ans = 1e18;
	int ansix = 0;
	repD(i,sz(v),0){
		if(i<sz(v)/2){
			if(val[i]-val[i+sz(v)/2]<ans) ans=val[i]-val[i+sz(v)/2],ansix=i;
		}
		if(t[i]==-1) continue;
		int j = t[i];
		val[j] = val[i]+abs(s[i]-s[j]);
	}
	cout<<ans<<'\n';
	assert(ansix<sz(v)/2);
	solve(ansix);
	return 0;
}