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

int n,m,p;
int s[11],ans[11];
vector<pii> a[11];
int vis[1005][1005];
queue<pii> q[11];
bool change;
queue<pair<pii,int>> lq;

bool valid(int i,int j){
	if(i <= 0 or j <= 0) return false;
	if(i > n or j > m) return false;
	if(vis[i][j]) return false;
	return true;
}

void bfs(int col){
	while(!lq.empty()){
		pii u = lq.front().F;
		int l = lq.front().S;
		lq.pop();
		vector<pii> nig = {{u.F-1,u.S},{u.F+1,u.S},{u.F,u.S+1},{u.F,u.S-1}};
		for(auto v:nig){
			if(valid(v.F,v.S) and l){
				// cout << u.F << " " << u.S << " ----> " << v.F << " " << v.S << endl;
				// cout << l << " " << col << endl;
				change = true;
				lq.push({v,l-1});
				vis[v.F][v.S] = col;
				q[col].push(v);
			}
		}
	}
}

signed main(){
	cin >> n >> m >> p;
	FOR(i,1,p+1) cin >> s[i];
	FOR(i,1,n+1){
		FOR(j,1,m+1){
			char c; cin >> c;
			if(c == '.') vis[i][j] = 0;
			else if(c == '#') vis[i][j] = -1;
			else{
				int x = c-'0';
				// cout << "-----------------" << x << endl;
				vis[i][j] = x;
				q[x].push({i,j});
			}
		}
	}
	while(true){
		change = false;
		FOR(i,1,p+1){
			while(!q[i].empty()){
				pii u = q[i].front();
				q[i].pop();
				lq.push({u,s[i]});
			}
			bfs(i);
		}
		if(!change) break;
	}
	FOR(i,1,n+1){
		FOR(j,1,m+1){
			// cout << vis[i][j] << " ";
			if(vis[i][j] > 0) ans[vis[i][j]]++;
		}
		// cout << "\n";
	}
	FOR(i,1,p+1) cout << ans[i] << " "; cout << "\n";
}