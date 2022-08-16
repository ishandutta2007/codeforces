/*input
8 5
1 2 2 3 3 2 3 3
1 2
1 5
2 3
2 4
5 6
5 7
5 8
1 2
1 3
1 4
2 3
5 3
*/		
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n,m,cur = 0,bls;
vi adj[100005];
int start[100005],fin[100005];
int a[100005],b[100005],ans[100005],suf[100005],cnt[100005];

struct Q{
	int l,r,k,ind;
};

Q quer[100005];

void dfs(int s,int p){
	start[s] = cur++;
	for(auto x:adj[s]){
		if(x != p) dfs(x,s);
	}
	fin[s] = cur;
}

bool cmp(Q x, Q y){
	if(x.l/bls == y.l/bls) return x.r > y.r;
	return x.l < y.l; 
}

void solve(){
	cin >> n >> m;
	bls = sqrt(n);
	FOR(i,1,n+1) cin >> a[i];
	REP(i,n-1){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,-1);
	REP(i,n){
		b[start[i+1]] = a[i+1];
	}
	REP(i,m){
		int v,k; cin >> v >> k;
		quer[i] = {start[v],fin[v]-1,k,i};
	}
	sort(quer,quer+m,cmp);
	REP(i,100005) cnt[i] = 0,suf[i] = 0;
	int curl = 0,curr = 0;
	suf[1] = 1;
	cnt[b[0]] = 1;
	// REP(i,n) cout << b[i] << " "; cout << "\n";
	REP(i,m){
		int l = quer[i].l,r = quer[i].r,k = quer[i].k,ind = quer[i].ind;
		while(curl > l){
			curl --;
			cnt[b[curl]] ++;
			suf[cnt[b[curl]]] ++;
		}
		while(curl < l){
			suf[cnt[b[curl]]] --;
			cnt[b[curl]] --;
			curl ++;
		}
		while(curr < r){
			curr ++;
			cnt[b[curr]] ++;
			suf[cnt[b[curr]]] ++;
		}
		while(curr > r){
			suf[cnt[b[curr]]] --;
			cnt[b[curr]] --;
			curr --;
		}
		ans[ind] = suf[k];
		// cout << l << " " << r << " " << ind << " " << k << endl;
		// REP(j,11){
		// 	cout << cnt[j] << " " << suf[j] << endl;
		// }
	}
	REP(i,m){
		cout << ans[i] << endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	WL(t) solve();
}