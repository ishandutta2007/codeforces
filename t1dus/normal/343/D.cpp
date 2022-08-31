/*input
5
1 2
5 1
2 3
4 2
12
1 1
2 3
3 1
3 2
3 3
3 4
1 2
2 4
3 1
3 3
3 4
3 5
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

int n,q;
vi adj[500005];
int seg[2][1000005];
int start[500005],fin[500005];
int tim;

void dfs(int u,int p){
	start[u] = tim++;
	for(auto v:adj[u]){
		if(v == p) continue;
		dfs(v,u);
	}
	fin[u] = tim;
}

void upd0(int l,int r,int val){
	l += n; r += n;
	while(l < r){
		if(l%2) seg[0][l++] = val;
		if(r%2) seg[0][--r] = val;
		l /= 2;
		r /= 2;
	}
}

void upd1(int pos,int val){
	pos += n;
	seg[1][pos] = val;
	pos /= 2;
	while(pos){
		seg[1][pos] = max(seg[1][pos*2],seg[1][pos*2+1]);
		pos /= 2;
	}
}

int solve(int v){
	int pos = start[v]; pos += n;
	int fill = seg[0][pos];
	while(pos > 1){
		pos /= 2;
		remax(fill,seg[0][pos]);
	}
	int empty = -1,l = start[v]+n,r = fin[v]+n;
	while(l < r){
		if(l%2) remax(empty,seg[1][l++]);
		if(r%2) remax(empty,seg[1][--r]);
		l /= 2;
		r /= 2;
	}
	if(empty > fill) return 0;
	return 1;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	tim = 0;
	cin >> n;
	REP(i,n-1){
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	REP(i,1000005){
		seg[0][i] = -2;
		seg[1][i] = -1;
	}
	dfs(1,-1);
	cin >> q;
	REP(T,q){
		int type,v; cin >> type >> v;
		if(type == 1){
			upd0(start[v],fin[v],T);
		}
		else if(type == 2){
			upd1(start[v],T);
		}
		else{
			cout << solve(v) << endl;
		}
	}
}