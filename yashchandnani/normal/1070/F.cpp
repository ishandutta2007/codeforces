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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vi v1,v2,v3;
	int cnt = 0;
	ll ans = 0;
	rep(i,n){
		string s;cin>>s;
		int x;cin>>x;
		if(s=="11") ans+=x,cnt++;
		else if(s=="10") v2.pb(x);
		else if(s=="01") v1.pb(x);
		else v3.pb(x);
	}
	sort(all(v1));	
	sort(all(v2));	
	while(sz(v1)>0&&sz(v2)>0){
		ans+=v1.back()+v2.back();
		v1.pop_back();
		v2.pop_back();
	}
	trav(i,v1) v3.pb(i);
	trav(i,v2) v3.pb(i);
	sort(all(v3));	
	while(sz(v3)&&cnt>0){
		ans+=v3.back();
		v3.pop_back();
		cnt--;
	}
	cout<<ans;
	return 0;
}