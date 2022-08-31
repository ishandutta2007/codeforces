/*input
10 10
418 45 865 869 745 901 177 773 854 462
4 8
1 4
3 6
1 5
1 10
5 9
1 2
4 7
1 3
2 2
1 6 246
1 4 296
1 2 378
1 8 648
2 6
1 5 288
1 6 981
1 2 868
2 7
*/		
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FORD(i,a,b) for(int i=(a);i>=b;i--)
#define all(v) v.begin(),v.end()
#define itr ::iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))

#define MX 200005

int n,m;
vi adj[MX];
int a[MX];
int seg[2*MX];
int start[MX];
int fin[MX];
int dep[MX];
int c = 0;

void dfs(int s,int p,int h){
	start[s] = (c++);
	dep[s] = h;
	for(auto x:adj[s]){
		if(x!=p) dfs(x,s,1-h);
	}
	fin[s] = c;
}

void update(int l,int r,int val){
	l += MX;
	r += MX;
	while(l < r){
		if(l%2) seg[l++] += val;
		if(r%2) seg[--r] += val;
		l /= 2;
		r /= 2;
	}
}

int quer(int p){
	int cur = 0;
	p += MX;
	while(p){
		cur += seg[p];
		p /= 2;
	}
	return cur;
}

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	REP(i,n) cin >> a[i];
	REP(i,n-1){
		int u,v;
		cin >> u >> v;
		u --;
		v --;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0,-1,0);
	REP(i,m){
		int type;
		cin >> type;
		if(type == 1){
			int x,val; cin >> x >> val;
			x --;
			if(dep[x]){
				update(start[x],fin[x],-val);
			}
			else{
				update(start[x],fin[x],val);
			}
		}
		else{
			int x; cin >> x;
			x --;
			if(dep[x]){
				cout << a[x]-quer(start[x]) << endl;
			}
			else{
				cout << a[x]+quer(start[x]) << endl;
			}
		}
	}
}