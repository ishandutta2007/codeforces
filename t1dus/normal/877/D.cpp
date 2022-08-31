/*input
3 4 4
....
###.
....
1 1 3 1
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

signed main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,k;
	cin >> n >> m >> k;
	bool a[n][m];
	int dist[n][m];
	REP(i,n) REP(j,m){
		dist[i][j] = -1;
		char x; cin >> x;
		if(x == '.') a[i][j] = 1;
		else a[i][j] = 0;
	}
	int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
	x1 --; x2 --;
	y1 --; y2 --;
	queue<pii> q;
	q.push({x1,y1});
	dist[x1][y1] = 0;
	while(!q.empty()){
		pii u = q.front();
		q.pop();
		for(int i = u.F,j = u.S+1; j <= u.S+k and j < m; j++){
			if(a[i][j] == 0) break;
			if(dist[i][j] > -1){
				if(dist[i][j] <= dist[u.F][u.S]) break;
				else continue;
			} 
			q.push({i,j});
			dist[i][j] = 1+dist[u.F][u.S];
		}
		for(int i = u.F,j = u.S-1; j >= u.S-k and j >= 0; j--){
			if(a[i][j] == 0) break;
			if(dist[i][j] > -1){
				if(dist[i][j] <= dist[u.F][u.S]) break;
				else continue;
			} 
			q.push({i,j});
			dist[i][j] = 1+dist[u.F][u.S];
		}
		for(int i = u.F+1,j = u.S; i <= u.F+k and i < n; i++){
			if(a[i][j] == 0) break;
			if(dist[i][j] > -1){
				if(dist[i][j] <= dist[u.F][u.S]) break;
				else continue;
			} 
			q.push({i,j});
			dist[i][j] = 1+dist[u.F][u.S];
		}
		for(int i = u.F-1,j = u.S; i >= u.F-k and i >= 0; i--){
			if(a[i][j] == 0) break;
			if(dist[i][j] > -1){
				if(dist[i][j] <= dist[u.F][u.S]) break;
				else continue;
			} 
			q.push({i,j});
			dist[i][j] = 1+dist[u.F][u.S];
		}
	}
	cout << dist[x2][y2] << endl;
}