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
int p[2009];
bool vis[2009];
int nx[2009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	set<pii> s1,s2;
	repA(i,1,2*n) cin>>p[i],s1.insert(mp(p[i],i));
	rep(i,m){
		int a,b;cin>>a>>b;
		vis[a]=vis[b]=1;
		nx[a]=b;nx[b]=a;
		s2.insert(mp(p[a],a));
		s2.insert(mp(p[b],b));
	}
	int t;cin>>t;
	rep(i,n){
		if(t==1){
			if(sz(s2)){
				pii x = *(s2.rbegin());
				cout<<x.snd<<endl;
				if(vis[x.snd]) s2.erase(mp(p[x.snd],x.snd));
				s1.erase(mp(p[x.snd],x.snd));
			}
			else{
				pii x = *(s1.rbegin());
				cout<<x.snd<<endl;
				if(vis[x.snd]) s2.erase(mp(p[x.snd],x.snd));
				s1.erase(mp(p[x.snd],x.snd));
			}
			int y;cin>>y;
				if(vis[y]) s2.erase(mp(p[y],y));
				s1.erase(mp(p[y],y));

		}
		else{
			int y;cin>>y;
				if(vis[y]) s2.erase(mp(p[y],y));
				s1.erase(mp(p[y],y));
			if(s1.find(mp(p[nx[y]],nx[y]))!=s1.end()){
				pii x = mp(p[nx[y]],nx[y]);
				cout<<x.snd<<endl;
				if(vis[x.snd]) s2.erase(mp(p[x.snd],x.snd));
				s1.erase(mp(p[x.snd],x.snd));
			}
			else if(sz(s2)){
				pii x = *(s2.rbegin());
				cout<<x.snd<<endl;
				if(vis[x.snd]) s2.erase(mp(p[x.snd],x.snd));
				s1.erase(mp(p[x.snd],x.snd));
			}
			else{
				pii x = *(s1.rbegin());
				cout<<x.snd<<endl;
				if(vis[x.snd]) s2.erase(mp(p[x.snd],x.snd));
				s1.erase(mp(p[x.snd],x.snd));
			}
		}
	}
	
	
	
	
	return 0;
}