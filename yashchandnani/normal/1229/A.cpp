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
bool vis[7009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	vector<pair<ll,int>> v(n);
	rep(i,n) cin>>v[i].fst;
	rep(i,n) cin>>v[i].snd;
	sort(all(v));
	ll ans=0;
	repD(i,n-1,0){
		repA(j,i+1,n-1){
			if(v[i].fst==v[j].fst){
				if(!vis[j]){
					vis[j]=1;
					ans+=v[j].snd;
				}
			}
			if(vis[j]&&((v[i].fst&v[j].fst)==v[i].fst)){
				vis[i]=1;
				ans+=v[i].snd;
				break;
			}
		}
	}
	cout<<ans;
	
	
	return 0;
}