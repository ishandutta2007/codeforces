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
vi g[100009],g2[100009];
int f[100009],don[100009];
bool vis[100009],vis2[100009];
vector<pair<pii,int>> ans;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,m;cin>>n>>m;
	int tot = 0;
	repA(i,1,n){
		int s;cin>>s;
		rep(j,s){
			int x;cin>>x;
			g[i].pb(x);
		}
		tot+=s;
	}
	int mn,mx,cntmn=0,cntmx=0;	
	if(tot%n==0){
		mn = mx = tot/n;
		cntmn = n,cntmx=0;
	}
	else{
		mn = tot/n,mx = mn+1,cntmx = tot%n,cntmn = n-cntmx;
	}
	set<int> give;
	repA(i,1,n){
		if(sz(g[i])>=mx){
			if(cntmx){
				f[i] = mx;
				cntmx--;
			}
			else f[i] = mn,cntmn--;
		}
		else{
			if(cntmn) f[i]=mn,cntmn--;
			else f[i] = mx,cntmx--;
		}
		if(sz(g[i])>f[i]){
			trav(j,g[i]) {
				g2[j].pb(i);
				if(!vis2[j]) give.insert(j);
				vis2[j]=1;
			}
		}
	}
	repA(i,1,n){
		if(sz(g[i])<f[i]){
			int cnt  =0;
			trav(j,g[i]) vis[j] = 1;
			vi tem;
			trav(j,give){
				if(vis[j]) continue;
				while(sz(g2[j])&&(sz(g[g2[j].back()])-don[g2[j].back()]==f[g2[j].back()])){
					g2[j].pop_back();
				}
				if(sz(g2[j])){
					int k = g2[j].back();
					g2[j].pop_back();
					don[k]++;
					ans.pb(mp(mp(k,i),j));
					cnt++;
				}
				if(sz(g2[j])==0) tem.pb(j);
				if(cnt+sz(g[i])==f[i]) break;
			}
			trav(i,tem) give.erase(i);
			trav(j,g[i]) vis[j] = 0;
		}
	}
	cout<<sz(ans)<<'\n';
	trav(i,ans) cout<<i.fst.fst<<' '<<i.fst.snd<<' '<<i.snd<<'\n';
	return 0;
}