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
int a[100009];
int l[1509],r[1509];
vector<pii> v;
int n,s,m,k;
int dp[1509][1509];
int lt[1509],rt[1509];
vi g[1509];
int mx[1509];
int chk(int x){
	vi q;
	rep(i,x) q.pb(v[i].snd),g[i].clear();
	sort(all(q));
	fill(dp);
	memset(mx,-1,sizeof(mx));
	rep(i,s){
		lt[i] = lower_bound(all(q),l[i])-q.begin();
		rt[i] = upper_bound(all(q),r[i])-q.begin();rt[i]--;
		repA(j,lt[i],rt[i]){
			if(mx[j]==-1) mx[j] = lt[i];
			else mx[j] = min(mx[j],lt[i]);
		}
	}
	repA(i,1,k) dp[0][i] = 2000;
	repA(i,1,x){
		if(mx[i-1]==-1) {
			rep(j,k+1) dp[i][j] = dp[i-1][j];
			continue;
		}
		int mn = mx[i-1];
		int lg = min(i-mn,k);
		repA(j,1,lg){
			dp[i][j] = 1;
		}
		repA(j,lg+1,k){
			dp[i][j] = min(dp[i-1][j],dp[mn][j-lg]+1);
		}
	}
	return dp[x][k];
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	cin>>n>>s>>m>>k;
	rep(i,n) cin>>a[i],v.pb(mp(a[i],i));
	rep(i,s){
		cin>>l[i]>>r[i];l[i]--,r[i]--;
	}
	sort(all(v));
	if(chk(n)>m){
		cout<<-1;
		exit(0);
	}
	int lo = k,hi = n;
	while(lo<hi){
		int mid = (lo+hi)/2;
		if(chk(mid)<=m){
			hi  = mid;
		}
		else lo = mid+1;

	}
	cout<<v[lo-1].fst;
	return 0;
}