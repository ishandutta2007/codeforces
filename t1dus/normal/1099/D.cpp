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

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

int n;
vi adj[100005];
int p[100005],s[100005],a[100005];
bool flag = true;
int ans = 0;

void dfs(int u){
	if(u == 1){
		a[1] = s[1];
	}
	else if(s[u] == -1){
		int mn = 0;
		if(adj[u].size()) mn = s[adj[u][0]]-s[p[u]];
		for(auto v:adj[u]){
			remin(mn,s[v]-s[p[u]]);
		}
		a[u] = mn;
		s[u] = s[p[u]]+mn;
		if(mn < 0) flag=false;
	}
	else{
		a[u] = s[u]-s[p[u]];
	}
	ans += a[u];
	for(auto v:adj[u]) dfs(v);
}

signed main(){
	cin >> n;
	FOR(i,2,n+1){
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	FOR(i,1,n+1) cin >> s[i];
	dfs(1);
	if(!flag) cout << "-1\n";
	else{
		cout << ans << "\n";
	}
}