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
const int mxv = 7009;
bitset<mxv> mu,a[100009],mask[71];
int p[7009];
vi g[7009];
void pre(){
	mu.reset();
	mu[1] = 1;
	int cnt =0;
	repA(i,2,7000){
		if(!p[i]){
			for(int j = 2*i;j<=7000;j+=i) p[j] = i;
			mu[i] = 1;
			cnt++;
		}
		else{
			if(mu[i/p[i]]==0||(i/p[i])%p[i]==0) mu[i] = 0;
			else mu[i]=1,cnt++;
		}
	}
	repA(i,1,7000){
		for(int j =i;j<=7000;j+=i) g[j].pb(i);
	}
	repA(i,1,70){
		for(int j =i;j<=7000;j+=i) mask[i][j] = mu[j/i];
	}
}

void solve(){


}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	int q;cin>>q;
	rep(i,q){
		int t,x,v;cin>>t>>x>>v;
		if(t==1){
			a[x].reset();
			trav(j,g[v]) a[x][j]=1;
		}
		else if(t==2){
			int z;cin>>z;
			a[x] = a[v]^a[z];
		}
		else if(t==3){
			int z;cin>>z;
			a[x] = a[v]&a[z];
		}
		else{
			if(v>70){
				bool ans = 0;
				repA(j,1,7000){
					if(j*v>7000) break;
					ans^=mu[j]&a[x][j*v];
				}
				cout<<ans;
			}
			else{
				cout<<(mask[v]&a[x]).count()%2;
			}
		}
	}
	
	
	return 0;
}