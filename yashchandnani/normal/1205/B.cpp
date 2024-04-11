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
vi v[65];
ll a[100009];
int dist[100009],par[100009];
bool vis[100009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n){
		cin>>a[i];
		if(a[i]) rep(j,60) if((1ll<<j)&a[i]) v[j].pb(i);
	}
	rep(j,60) if(sz(v[j])>=3) {
		cout<<3;
		return 0;
	}
	int cur = 1e7;
	rep(i,n){
		if(a[i]){
			memset(dist,-1,sizeof(dist));	
			memset(par,-1,sizeof(par));	
			fill(vis);
			queue<int> q;
			q.push(i);
			dist[i] = 0;
			while(!q.empty()){
				int z = q.front();
				vis[z] = 1;
				q.pop();
				rep(j,60){
					if((1ll<<j)&a[z]){
						trav(k,v[j]){
							if(k==par[z]||k==z) continue;
							if(!vis[k]) {
								par[k] = z;
								q.push(k);
								dist[k] = dist[z]+1;
							}
							else {
								cur = min(cur,dist[z]+dist[k]+1);		
							}
						}
					}
				}
			}
		}
	}
	if(cur==1e7) cur=-1;
	cout<<cur;
	return 0;
}